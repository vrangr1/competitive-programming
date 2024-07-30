/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jul 30 20:54:04 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sq = bsqrt(n), m = sq;
    if (m*m < n) m++;
    sq = m;
    vector<vector<int>> cts(m,vector<int>(n+1,0)), psum(m,vector<int>(n+1,0));
    rep(i,m) {
        if (i*sq >= n) break;
        rep(j,i*sq,i*sq + sq-1, 1) {
            if (j >= n) break;
            cts[i][min(a[j],n)]++;
        }
        rep(j,n-1,1,-1) {
            cts[i][j] += cts[i][j+1];
            psum[i][j] = cts[i][j];
            if (i) psum[i][j] += psum[i-1][j];
        }
    }
    // return;
    while(q--) {
        ll i, k; cin >> i >> k; --i;
        if (ll(a[i])*k > i) cout << yes;
        else {
            debug(i);
            int ct = 0, cur = 1;
            rep(p,m) {
                if (p*sq >= n) break;
                if (cur > a[i]) break;
                // int rem = min(int(i),(int(i)/sq)*sq + sq -1) - p*sq + 1;
                assert(cur <= n);
                // if ((i/sq) >= m) {
                //     debug(i,sq);
                //     exit(0);
                // }
                assert((i/sq) < m);
                int rem = psum[i/sq][cur];
                if (p) rem -= psum[p-1][cur];
                // int req = (a[i]+1-cur)*k-ct;
                if (rem < (a[i]+1-cur)*k - ct) break;
                if (p*sq+sq-1 >= i) {
                    rep(j,p*sq,p*sq+sq-1,1) {
                        if (j >= i) break;
                        ct+= (a[j] >= cur);
                        if (ct == k) {
                            cur++;
                            ct = 0;
                        }
                    }
                    break;
                }
                if (ct+cts[p][cur] < k) {
                    ct+=cts[p][cur];
                    continue;
                }
                rep(j,p*sq,p*sq+sq-1,1) {
                    if (j >= n) break;
                    ct+= (a[j] >= cur);
                    if (ct == k) {
                        cur++;
                        ct = 0;
                    }
                }
            }
            if (cur > a[i]) cout << no;
            else cout << yes;
        }
    }
}