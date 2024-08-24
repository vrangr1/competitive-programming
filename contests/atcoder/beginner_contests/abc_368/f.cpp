/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 24 17:51:28 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int n; cin >> n;
    auto get = [](int v) -> int {
        int ct = 0;
        while(v%2 == 0) {
            v/=2;
            ct++;
        }
        int sq = bsqrt(v);
        rep(f,3,sq,2) {
            if (v%f) continue;
            while(v%f == 0) {
                v/=f;
                ct++;
            }
        }
        if (v != 1) ct++;
        return ct;
    };
    int sol = 0;
    rep(i,n) {
        int v; cin >> v;
        int g = get(v);
        debug(v,g);
        sol^=g;
    }
    if (sol) cout << "Anna\n";
    else cout << "Bruno\n";
}