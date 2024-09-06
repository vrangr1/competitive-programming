/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep  4 20:35:22 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class segtree1 {
public:
    ll n;
    vector<ll> tree;
    segtree1(const vector<ll> &a) {
        n = sz(a);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        tree.assign(gn,LLONG_MIN);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1ll,-1)
            tree[i] = max(tree[i<<1ll],tree[i<<1ll|1ll]);
    }

    ll query(ll l, ll r) {
        ll res = LLONG_MIN;
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res = max(res,tree[l++]);
            if (r&1ll) res = max(res,tree[--r]);
        }
        return res;
    }
};

void solve1() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> inds(n,-1);
    vector<ll> stt(n,-1), edd(n,-1);
    vector<bool> eddl(n,false),sttl(n,false);
    vector<ll> b;
    ll last = a.front(), dir = -1;
    inds[0] = 0;
    sttl[0] = true;
    stt[0] = 0;
    edd[0] = 0;
    rep(i,1,n-1ll,1) {
        if (last == a[i]) {
            inds[i] = max(sz(b)-1ll,0ll);
            if (edd[inds[i]] != -1) {
                eddl[edd[inds[i]]] = false;
            }
            edd[inds[i]] = i;
            eddl[i] = true;
            continue;
        }
        ll cdir = (a[i]>last);
        if (dir == cdir) {
            assert(!b.empty());
            b.back() += llabs(a[i]-last);
            last = a[i];
            inds[i] = sz(b)-1ll;
            if (edd[inds[i]] != -1) {
                eddl[edd[inds[i]]] = false;
            }
            edd[inds[i]] = i;
            eddl[i] = true;
            continue;
        }
        if (dir == -1ll) {
            b.push_back(llabs(a[i]-last));
            dir = cdir;
            last = a[i];
            inds[i] = 0ll;
            // stt[inds[i]] = i;
            // sttl[i] = true;
            if (edd[inds[i]] != -1) {
                eddl[edd[inds[i]]] = false;
            }
            edd[inds[i]] = i;
            eddl[i] = true;
            assert(sz(b) == 1);
            continue;
        }
        b.push_back(llabs(a[i]-last));
        last = a[i];
        dir = cdir;
        inds[i] = sz(b)-1ll;
        stt[inds[i]] = edd[inds[i]-1];
        edd[inds[i]] = i;
        sttl[stt[inds[i]]] = true;
        eddl[i] = true;
    }
    if (b.empty()) b.push_back(0ll);
    vector<ll> psum(sz(b));
    partial_sum(all(b),psum.begin());
    auto get_sum = [&](ll l, ll r) -> ll {
        return psum[r]-(l?psum[l-1ll]:0ll);
    };
    segtree1 seg(b);
    auto get_max = [&](ll l, ll r) -> ll {
        return seg.query(l,r+1ll);
    };
    debug(b,inds,stt,edd,sttl,eddl);
    // return;
    while(q--) {
        ll l, r, k; cin >> l >> r >> k;
        --l;--r;
        ll lb = inds[l], rb = inds[r];
        if (l!=r && sttl[r]) ++rb;
        // if (rb >= sz(b)) --rb;
        assert(lb <= rb);
        if (lb == rb) {
            ll sum = llabs(a[l]-a[r]);
            if (sum <= k) cout << "0\n";
            else cout << sum-k << endl;
            continue;
        }
        ll sum = 0ll, mx = LLONG_MIN;
        if (rb == lb+1ll) {
            ll fst, sd;
            if (!eddl[l]) {
                fst = llabs(a[edd[inds[l]]]-a[l]);
            }
            else fst = 0ll;
            if (!sttl[r]) {
                sd = llabs(a[stt[rb]]-a[r]);
            }
            else sd = 0ll;
            // sum = llabs(a[edd[inds[l]]]-a[l]) + llabs(a[stt[rb]]-a[r]);
            // mx = max(llabs(a[edd[inds[l]]]-a[l]),llabs(a[stt[rb]]-a[r]));
            sum = fst+sd;
            mx = max(fst,sd);
        }
        else {
            sum = get_sum(lb+1ll,rb-1ll);
            mx = get_max(lb+1ll,rb-1ll);
            ll fst, sd;
            if (!eddl[l]) {
                fst = llabs(a[edd[inds[l]]]-a[l]);
            }
            else fst = 0ll;
            if (!sttl[r]) {
                sd = llabs(a[stt[rb]]-a[r]);
            }
            else sd = 0ll;
            sum += fst+sd;
            mx = max({mx,fst,sd});
            // sum += llabs(a[edd[inds[l]]]-a[l]) + llabs(a[stt[rb]]-a[r]);
            // mx = max({mx,llabs(a[edd[inds[l]]]-a[l]),llabs(a[stt[rb]]-a[r])});
        }
        debug(endl,l,r,lb,rb,sum,mx);
        if (sum <= k) {
            cout << "0\n";
            continue;
        }
        if (mx <= sum-mx || mx-(sum-mx) <= k) {
            cout << (sum-k+1ll)/2ll << endl;
            continue;
        }
        ll sol = sum-mx;
        sum-=2ll*sol;
        assert(sum > k);
        sol += sum-k;
        cout << sol << endl;
    }
}
#define mxi 0
#define lvi 1
#define rvi 2
#define ldi 3
#define rdi 4
#define lsi 5
#define rsi 6
#define eql 0
#define inc 1
#define dec 2
class segtree {
private:
    ll adjsum(ll l, ll r) {
        return sum[l]+sum[r] + llabs(eds[l][rvi]-eds[r][lvi]);
    }

    ll adjmx(array<ll,7> &res, ll l, ll r) {
        res[mxi] = max(eds[l][mxi],eds[r][mxi]);
        if (eds[l][rvi] == eds[r][lvi]) {
            if (eds[l][rdi] == eds[r][ldi]) {
                res[mxi] = max(res[mxi],eds[l][rsi]+eds[r][lsi]);
                if (eds[l][lsi] == sum[l]) {
                    res[lsi] = eds[l][lsi]+eds[r][lsi];
                }
                else res[lsi] = eds[l][lsi];
                if (eds[r][rsi] == sum[r])
                    res[rsi] = eds[r][rsi]+eds[l][rsi];
                else res[rsi] = eds[r][rsi];
            }
            else {
                if (eds[l][ldi] == eql)
                    res[lsi] = eds[r][lsi];
                else
                    res[lsi] = eds[l][lsi];
                if (eds[r][rdi] == eql)
                    res[rsi] = eds[l][rsi];
                else
                    res[rsi] = eds[r][rsi];
            }
        }
        else if (eds[l][rvi] < eds[r][lvi]) {
            if (eds[l][rdi] == inc) {
                if (eds[r][ldi] == inc) {
                    res[mxi] = max(res[mxi],eds[l][rsi]+eds[r][lsi]+eds[r][lvi]-eds[l][rvi]);
                    if (eds[l][lsi] == sum[l])
                        res[lsi] = eds[l][lsi] + eds[r][lvi] - eds[l][rvi] + eds[r][lsi];
                    else res[lsi] = eds[l][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[r][lvi] - eds[l][rvi] + eds[l][rsi];
                    else res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[l][rsi]+eds[r][lvi]-eds[l][rvi]);
                    if (eds[l][lsi] == sum[l])
                        res[lsi] = eds[l][lsi] + eds[r][lvi]-eds[l][rvi];
                    else
                        res[lsi] = eds[l][lsi];
                    if (eds[r][rdi] == dec)
                        res[rsi] = eds[r][rsi];
                    else res[rsi] = eds[r][lvi] - eds[l][rvi] + eds[l][rsi];
                }
            }
            else if (eds[l][rdi] == dec) {
                if (eds[r][ldi] == dec) {
                    res[mxi] = max(res[mxi],eds[r][lvi]-eds[l][rvi]);
                    res[lsi] = eds[l][lsi];
                    res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[r][lvi]-eds[l][rvi] + eds[r][lsi]);
                    res[lsi] = eds[l][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[r][lvi]-eds[l][rvi]+eds[l][rsi];
                    else res[rsi] = eds[r][rsi];
                }
            }
            else {
                if (eds[r][ldi] == inc) {
                    res[mxi] = max(res[mxi],eds[r][lvi]-eds[l][rvi]+eds[r][lsi]);
                    res[lsi] = eds[r][lvi]-eds[l][rvi]+eds[r][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[r][lvi]-eds[l][rvi];
                    else res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[r][lvi]-eds[l][rvi]);
                    res[lsi] = eds[r][lvi]-eds[l][rvi];
                    if (eds[r][ldi] == dec)
                        res[rsi] = eds[r][rsi];
                    else res[rsi] = eds[r][lvi]-eds[l][rvi];
                }
            }
        }
        else {
            if (eds[l][rdi] == dec) {
                if (eds[r][ldi] == dec) {
                    res[mxi] = max(res[mxi],eds[l][rsi]+eds[r][lsi]+eds[l][rvi]-eds[r][lvi]);
                    if (eds[l][lsi] == sum[l])
                        res[lsi] = eds[l][lsi] + eds[l][rvi]-eds[r][lvi] + eds[r][lsi];
                    else res[lsi] = eds[l][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[l][rvi]-eds[r][lvi] + eds[l][rsi];
                    else res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[l][rsi]+eds[l][rvi]-eds[r][lvi]);
                    if (eds[l][lsi] == sum[l])
                        res[lsi] = eds[l][lsi] + eds[l][rvi]-eds[r][lvi];
                    else res[lsi] = eds[l][lsi];
                    if (eds[r][ldi] == inc)
                        res[rsi] = eds[r][rsi];
                    else res[rsi] = eds[l][rvi] - eds[r][lvi] + eds[l][rsi];
                }
            }
            else if (eds[l][rdi] == inc) {
                if (eds[r][ldi] == inc) {
                    res[mxi] = max(res[mxi],eds[l][rvi]-eds[r][lvi]);
                    res[lsi] = eds[l][lsi];
                    res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[l][rvi]-eds[r][lvi]+eds[r][lsi]);
                    res[lsi] = eds[l][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[l][rvi]-eds[r][lvi];
                    else res[rsi] = eds[r][rsi];
                }
            }
            else {
                if (eds[r][ldi] == dec) {
                    res[mxi] = max(res[mxi],eds[l][rvi]-eds[r][lvi]+eds[r][lsi]);
                    res[lsi] = eds[l][rvi]-eds[r][lvi]+eds[r][lsi];
                    if (eds[r][rsi] == sum[r])
                        res[rsi] = eds[r][rsi] + eds[l][rvi]-eds[r][lvi];
                    else res[rsi] = eds[r][rsi];
                }
                else {
                    res[mxi] = max(res[mxi],eds[l][rvi]-eds[r][lvi]);
                    res[lsi] = eds[l][rvi] - eds[r][lvi];
                    if (eds[r][ldi] == inc)
                        res[rsi] = eds[r][rsi];
                    else res[rsi] = eds[l][rvi] - eds[r][lvi] + eds[l][rsi];
                }
            }
        }
        res[lvi] = eds[l][lvi];
        res[rvi] = eds[r][rvi];
        if (eds[l][ldi] != eql) res[ldi] = eds[l][ldi];
        else if (eds[r][ldi] != eql) res[ldi] = eds[r][ldi];
        else res[ldi] = eql;
        if (eds[r][rdi] != eql) res[rdi] = eds[r][rdi];
        else if (eds[l][rdi] != eql) res[rdi] = eds[l][rdi];
        else res[rdi] = eql;
    }
public:
    ll n;
    vector<ll> sum;
    vector<array<ll,7>> eds; // mx,lval,rval,ldir,rdir,lsum,rsum
                             //  0, 1  , 2  , 3  , 4  , 5  , 6
    segtree(vector<ll> a) {
        n = sz(a);
        if (__builtin_popcountll(n) != 1ll)
            n = (1ll<<(64ll-__builtin_clzll(n)));
        while(sz(a) < n) {
            a.push_back(a.back());
        }
        ll gn = (n<<1ll);
        sum.assign(gn,0ll);
        eds.resize(gn);
        rep(i,n) {
            sum[i+n] = 0ll;
            eds[i+n] = {0ll,a[i],a[i],eql,eql,0ll,0ll};
        }
        rep(i,n-1,1ll,-1) {
            sum[i] = adjsum((i<<1ll),(i<<1ll|1ll));
            adjmx(eds[i],(i<<1ll),(i<<1ll|1ll));
        }
    }

    ll query_sum(ll l, ll r) {
        array<ll,3> resl = {0ll,-1ll,-1ll}, resr = {0ll,-1ll,-1ll};
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                if (resl[1] == -1ll) {
                    resl[0] = sum[l];
                    resl[1] = eds[l][lvi];
                    resl[2] = eds[l][rvi];
                } else {
                    resl[0] += sum[l] + llabs(resl[2]-eds[l][lvi]);
                    resl[2] = eds[l][rvi];
                }
                l++;
            }
            if (r&1ll) {
                --r;
                if (resr[1] == -1ll) {
                    resr[0] = sum[r];
                    resr[1] = eds[r][lvi];
                    resr[2] = eds[r][rvi];
                } else {
                    resr[0] += sum[r] + llabs(resr[1]-eds[r][rvi]);
                    resr[l] = eds[r][lvi];
                }
            }
        }
        return resl[0] + resr[0] + llabs(resl[2]-resr[1]);
    }

    ll query_max(ll l, ll r) {
        
    }
};

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
}