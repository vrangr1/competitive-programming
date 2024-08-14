/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 14 20:06:54 IST 2024
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int mx = *max_element(all(a));
    if (mx == 1) return void(cout << "-1\n");
    auto ans = [&](int i, int j = -1) -> void {
        assert(i == -1 || i != j);
        if (i == -1) cout << "-1\n";
        else cout << i+1 << " " << j+1 << endl;
    };
    auto isp = [&](int v) -> bool {
        if (v == 1) return false;
        if (v == 2) return true;
        if (v%2 == 0) return false;
        int sq = bsqrt(v);
        rep(f,3,sq,2) if (v%f == 0) return false;
        return true;
    };
    int e = -1, o = -1, one = -1;
    rep(i,n) {
        if (a[i] == 1) {
            if (e != -1 && !isp(1+a[e])) {
                ans(e,i);
                return;
            }
            if (o != -1 && !isp(1+a[o])) {
                ans(o,i);
                return;
            }
            one = i;
            continue;
        }
        if (a[i]%2) {
            if (o != -1) {
                assert(!isp(a[o]+a[i]));
                ans(o,i);
                return;
            }
            o = i;
            if (one != -1 && !isp(a[i]+1)) {
                ans(i,one);
                return;
            }
            continue;
        }
        assert(a[i]%2 == 0);
        if (e != -1) {
            // if (isp(a[e]+a[i])) {
            //     debug(a[e],a[i]);
            //     exit(0);
            // }
            assert(!isp(a[e]+a[i]));
            ans(i,e);
            return;
        }
        e = i;
        if (one != -1 && !isp(a[i]+1)) {
            ans(i,one);
            return;
        }
    }
    if (e != -1 && o != -1 && !isp(a[e]+a[o])) {
        ans(e,o);
        return;
    }
    cout << "-1\n";
}