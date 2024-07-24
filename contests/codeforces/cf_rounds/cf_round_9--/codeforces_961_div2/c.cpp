/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jul 23 20:33:20 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n), p(n);
    rep(i,n) cin >> a[i];
    fill(all(p),0ll);
    auto comp = [](ld a1, ld n1, ld a2, ld n2) -> bool {
        // return (n1*logl(a1) <= n2*logl(a2));
        return (log2l(log2l(a1)/log2l(a2)) <= (n2-n1));
    };
    ll sol = 0ll;
    rep(i,1,n-1ll,1) {
        if (a[i-1] == 1 && a[i] == 1) continue;
        if (a[i-1] > 1 && a[i] == 1) return void(cout << "-1\n");
        if (a[i-1] == 1) continue;
        assert(a[i] != 1ll && a[i-1] != 1ll);
        // ld est = ((ld)p[i-1]*logl((ld)(a[i-1])))/((ld)logl((ld)a[i]));
        // p[i] = (ll)est;
        // p[i] = max(1ll,p[i]-5ll);
        // p[i] = (1ll<<(63ll-__builtin_clzll(p[i])));
        // sol += __builtin_ctzll(p[i]);
        ld est = (ld)p[i-1] + log2l(log2l((ld)a[i-1])) - log2l(log2l((ld)a[i]));
        p[i] = (ll)est;
        p[i] = max(0ll,p[i]-1ll);
        sol += p[i];
        while(!comp((ld)a[i-1],(ld)p[i-1],(ld)a[i],(ld)p[i])) {
            p[i]++;
            // p[i]*=2ll;
            sol++;
        }
    }
    debug(p);
    cout << sol << endl;
}