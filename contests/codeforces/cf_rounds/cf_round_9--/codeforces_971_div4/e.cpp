/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep  3 20:35:59 IST 2024
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

#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type>
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

void solve() {
    i128 n, k; 
    {
        ll n1, k1; cin >> n1 >> k1;
        n = n1;
        k = k1;
    }
    if (n == 1) {
        cout << ll(k) << endl;
        return;
    }
    i128 disc = k*4ll*k + 4ll*k + ((i128)1) + 4ll*n*k - 8ll*k + (n-1ll)*n*2ll;
    assert(disc > 0ll);
    debug(ll(disc));
    i128 sq = bsqrt(disc);
    debug(ll(sq));
    i128 root = -(2ll*k+1ll)+sq;
    root/=i128(2ll);
    debug(ll(root));
    auto get = [&](i128 x) -> ll {
        i128 sol = x*x + x*(2ll*k+1ll) - (n-2ll)*k - ((n-1ll)*n)/(i128(2));
        return llabs(ll(sol));
    };
    if (n-1ll > root) {
        if (root == 0ll) {
            cout << min(get(0),get(1)) << endl;
        }
        else cout << min({get(root),get(root-1),get(root+1)}) << endl;
        return;
    }
    i128 sum = n*k + ((n-1ll)*n)/(i128(2ll));
    sum-=k*2ll;
    ll sol = ll(sum);
    cout << sol << endl;
}