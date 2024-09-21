/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 21 22:12:26 IST 2024
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

#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mxp = ll(1e18)+3l;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> h(n);
    // int mx = 0;
    rep(i,n) {
        cin >> h[i];
        // mx = max(mx,h[i]);
    }
    map<ll,ll> val;
    rep(i,n) {
        if (val.find(h[i]) != val.end()) continue;
        val[h[i]] = (ll)grng(mxp);
    }
    vector<ll> pxor(n);
    pxor[0] = val[h[0]];
    rep(i,n) {
        if (!i) continue;
        pxor[i] = pxor[i-1]^val[h[i]];
    }
    auto get = [&](ll l, ll r) -> ll {
        return pxor[r]^(l?pxor[l-1]:0ll);
    };
    while(q--) {
        ll l, r; cin >> l >> r;--l;--r;
        if ((r-l+1)%2ll || get(l,r)) cout << "NO\n";
        else cout << "YES\n";
    }
}