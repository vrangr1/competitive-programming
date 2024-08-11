/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug 11 22:47:48 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
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

const ll mx = ll(2e7)+4ll;
vector<ll> smf(mx,LLONG_MAX);

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    smf[1] = 1;
    ll sq = bsqrt(mx);
    rep(f,2,sq,1ll) {
        rep(v,f,mx-1ll,f){
            smf[v] = min(smf[v],f);
        }
    }
}

void solve() {
    init();
    ll n, l, f; cin >> n >> n >> l >> f;
    if (l > f) swap(l,f);
    ll sol = n*f+l;
    rep(ct,1ll,n,-1ll) {
        ll fac = smf[ct];
        if (fac == LLONG_MAX) fac = fac-1ll;
        else if (fac != 1ll) fac--;
        sol = max(sol,ct*f + fac*l);
    }
    cout << sol << endl;
}