/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Apr  8 22:04:39 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
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

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    auto get_fac = [](int val) -> vector<int> {
        vector<int> facs;
        int sq = bsqrt(val);
        rep(f,1,sq,1){
            if (f > val) break;
            if (val%f) continue;
            // facs.insert(f);
            // facs.insert(val/f);
            facs.push_back(f);
            facs.push_back(val/f);
        }
        sort(all(facs));
        return facs;
    };
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m));
    rep(i,n-1,0,-1){
        rep(j,m-1,0,-1){
            if (i == n-1 && j == m-1){
                dp[i][j] = get_fac(a[i][j]);
                continue;
            }
            vector<int> cur = get_fac(a[i][j]), res;
            if (i == n-1){
                set_intersection(all(cur),all(dp[i][j+1]),back_inserter(res));
            }
            else if (j == m-1){
                set_intersection(all(cur),all(dp[i+1][j]),back_inserter(res));
            }
            else{
                set_intersection(all(cur),all(dp[i][j+1]),back_inserter(res));
                set_intersection(all(cur),all(dp[i+1][j]),back_inserter(res));
            }
            sort(all(res));
            res.erase(unique(all(res)),res.end());
            dp[i][j] = res;
        }
    }
    cout << dp[0][0].back() << endl;
}