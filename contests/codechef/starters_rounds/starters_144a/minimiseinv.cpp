/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 24 20:08:05 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class segtree {
public:
    ll n;
    vector<ll> tree;
    segtree(ll gn) {
        n = gn;
        gn<<=1ll;
        if (__builtin_popcountll(gn) != 1)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
    }

    void update(ll ind, ll x) {
        for(tree[ind+=n]=x;ind>1;ind>>=1ll)
            tree[ind>>1ll] = tree[ind]+tree[ind^1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve1() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll z = ll(count(all(s),'0')), o = n-z;
    if (z <= k || o <= k) return void(cout << "0\n");
    ll l = 0, r = n-1ll;
    while(l < r && k > 0ll) {
        while(l < r && s[l] == '0') {
            ++l;
            --z;
        }
        while(l < r && s[r] == '1') {
            --r;
            --o;
        }
        if (l >= r) break;
        assert(z >= 0ll && o >= 0ll);
        if (z > o) {
            s[l++] = '0';
            --o;
        }
        else if (o >= z){
            s[r--] = '1';
            z--;
        }
        // else {

        // }
        --k;
    }
    debug(s);
    segtree seg(n);
    ll sol = 0ll;
    rep(i,n) {
        if (s[i] == '0') sol += seg.query(0,i);
        else seg.update(i,1);
    }
    cout << sol << endl;
}

void solve() {
    ll n, k; cin >> n >> k;
    auto comp = [&](string &s) -> ll {
        ll sol = 0ll;
        segtree seg(n);
        rep(i,n) {
            if (s[i] == '0') sol += seg.query(0,i);
            else seg.update(i,1);
        }
        return sol;
    };
    string s; cin >> s;
    ll z = ll(count(all(s),'0')), o = n-z;
    if (z <= k || o <= k) return void(cout << "0\n");
    string t = s;
    ll l = 0ll, ops = 0ll;
    while(ops < k) {
        assert(l < n);
        if (s[l] == '0') z--;
        else {
            ops++;
            o--;
            t[l] = '0';
        }
        l++;
    }
    assert(ops == k);
    ll r = n-1ll;
    ll inv = comp(t), sol = inv;
    --l;
    while(l >= 0ll) {
        assert(l <= r);
        assert(s[l] == '1');
        inv += z;
        ops--;
        o++;
        l--;
        while(l >= 0ll && s[l] == '0') {
            --l;
            z++;
        }
        sol = min(sol,inv);
        while (ops < k && r > l) {
            while(r > l && s[r] == '1') {
                r--;
                o--;
            }
            if (l == r) break;
            z--;
            inv -= o;
            --r;
            ops++;
            sol = min(sol,inv);
        }
    }
    cout << sol << endl;
}