/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 18:28:03 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> grid(n,vector<ll>(n));
    rep(i,n)
        rep(j,n) cin >> grid[i][j];
    vector<vector<ll>> dp(n,vector<ll>(n,0)), mats(n,vector<ll>(n,-1));
    // priority_queue<ll,vector<ll>,greater<ll>> pq;
    rep(i,n){
        rep(j,n){
            if (!i && !j) dp[i][j] = grid[i][j];
            else if (!i) dp[i][j] = dp[i][j-1] + grid[i][j];
            else if (!j) dp[i][j] = dp[i-1][j] + grid[i][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
            if (i < m-1 || j < m-1) continue;
            ll sum;
            if (i == m-1 && j == m-1){
                sum = dp[i][j];
            }
            else if (i == m-1){
                sum = dp[i][j] - dp[i][j-m];
            }
            else if (j == m-1)
                sum = dp[i][j] - dp[i-m][j];
            else sum = dp[i][j] - dp[i-m][j] - dp[i][j-m] + dp[i-m][j-m];
            mats[i][j] = sum;
            // if (sz(pq) < 3) pq.push(sum);
            // else pq.push(sum);
            // if (sz(pq) > 3) pq.pop();
        }
    }
    // assert(sz(pq) == 3);
    // ll sol = 0;
    // while(!pq.empty()){
    //     sol += pq.top();
    //     pq.pop();
    // }
    // cout << sol << endl;
    
}