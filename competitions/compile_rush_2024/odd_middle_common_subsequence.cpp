/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Apr 18 20:54:43 IST 2024
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

// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    int k; cin >> k;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)), dp2(n+1,vector<int>(m+1,0));
    rep(i,1,n,1){
        rep(j,1,m,1){
            dp[i][j] = max({dp[i-1][j],dp[i][j-1]});
            if (a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    rep(i,n-1,0,-1){
        rep(j,m-1,0,-1){
            dp2[i][j] = max(dp2[i+1][j],dp2[i][j+1]);
            if (a[i] == b[j]) dp2[i][j] = max(dp2[i][j],dp2[i+1][j+1]+1);
        }
    }
    debug(n,m,a,b,dp,dp2);
    auto get = [&](int i, int j) -> int {
        if (a[i] != k || b[j] != k) return -1;
        int left = dp[i+1][j+1];
        assert(left>0);
        int right = dp2[i+1][j+1];
        assert(right >= 0);
        debug(i,j,left,right);
        int sol = min(left-1,right);
        return 2*sol + 1;
    };
    int sol = -1;
    rep(i,n){
        rep(j,m){
            sol = max(sol,get(i,j));
        }
    }
    cout << sol << endl;
}