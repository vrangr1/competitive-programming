/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 10 20:06:03 IST 2024
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

void solve() {
    ll x; cin >> x;
    // auto ispf = [](ll n) -> bool {
    //     ll sq = bsqrt(n);
    //     assert(sq*sq <= n);
    //     return sq*sq == n;
    // };
    auto check = [](ll n) -> bool {
        assert(n > 2);
        ll sq = bsqrt(n);
        if (sq*sq == n) return false;
        if (n%2ll == 0ll) return false;
        rep(f,3,sq,2ll)
            if ((n%f) == 0ll) return false;
        return true;
    };
    auto fpm = [&check](ll n) -> ll {
        if (2ll >= n) return 2ll;
        rep(f,n+1ll-n%2ll,(ll)1e9+123ll,2ll)
            if (check(f)) return f;
        assert(false);
        return -1;
    };
    ll p = fpm(x), p2 = fpm(p+1ll);
    debug(x,p,p2);
    cout << p * p2 << endl;
}