/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 24 20:12:59 IST 2024
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
#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif
// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1() {
    ll n, l, r; cin >> n >> l >> r;
    if (n == 1) return void(cout << "1\n");
    if (r < n) {
        vector<ll> p(n);
        iota(all(p),1ll);
        swap(p.back(),p.front());
        print_vec(p);
        return;
    }
    if (r == n) {
        if (n == 2) return void(cout << "1 2\n");
        if (n == 3) return void(cout << "2 3 1\n");
        vector<ll> p(n);
        iota(all(p),1ll);
        swap(p[1],p.back());
        swap(p[0],p[n-2]);
        print_vec(p);
        return;
    }
    vector<ll> p(n);
    iota(all(p),1ll);
    ll sum = 0ll;
    rep(i,n) {
        sum += p[i];
        if (sum >= l && sum <= r) {
            reverse(p.begin()+i,p.end());
            print_vec(p);
            return;
        }
    }
    print_vec(p);
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
        rep(i,n)
            tree[i+n] = i+1ll;
        rep(i,n-1ll,1ll,-1)
            tree[i] = tree[i>>1ll] + tree[i>>1ll|1ll];
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

void solve(){
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> p(n);
    iota(all(p),1ll);
    ll stt = -1ll, edd = stt, sum = 0ll;
    rep(i,n) {
        sum += p[i];
        if (sum >= l && sum <= r) {
            if (stt == -1ll) stt = i;
            edd = i;
        }
    }
    ll last = n-1ll;
    segtree seg(n);
    ll cst = stt, ced = edd;
    while(ced < last && cst <= ced) {
        swap(p[cst],p[last]);
        seg.update(cst,p[cst]);
        seg.update(last,p[last]);
        if (seg.query(0,cst+1) > r) {
            edd = cst-1ll;
            break;
        }
        while(ced >= cst && seg.query(0,ced+1ll) > r) {
            edd--;
        }
        assert(ced >= cst);
        last--;
        cst++;
    }
    if (edd < stt) return void(print_vec(p));
    edd = stt;
    sum = seg.query(0,stt);
    while(edd < n) {
        sum += p[edd];
        if (sum >= l && sum <= r) {
            edd++;
        }
        else break;
    }
    edd--;
    assert(edd < n && stt <= edd);
    ll i = 0;
    last = edd+1ll;
    while(i < stt && last < n) {
        swap(p[i],p[last]);
        i++;
        last++;
    }
    print_vec(p);
}