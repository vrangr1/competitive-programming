/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan 17 20:51:54 IST 2024
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

#define up 0
#define left 1
#define both 2
#define none 3
#define one '1'
#define zero '0'

void solve1(){
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n)
        rep(j,m) cin >> a[i][j];
    vector<string> geese(n);
    rep(i,n) cin >> geese[i];
    vector<vector<ll>> dp(n,vector<ll>(m,LLONG_MAX)), dir(n,vector<ll>(m,none));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m){
            if (!i && !j) continue;
            if (!i){
                dp[i][j] = dp[i][j-1ll] + a[i][j];
                if (j+1ll < m && geese[i][j+1ll] == one) dp[i][j] += k;
                if (i+1ll < n && geese[i+1ll][j] == one) dp[i][j] += k;
                dir[i][j] = left;
                continue;
            }
            if (!j){
                dp[i][j] = dp[i-1ll][j] + a[i][j];
                if (j+1ll < m && geese[i][j+1ll] == one) dp[i][j] += k;
                if (i+1ll < n && geese[i+1ll][j] == one) dp[i][j] += k;
                dir[i][j] = up;
                continue;
            }
            // debug(i,j);
            ll ucost = dp[i-1ll][j], lcost = dp[i][j-1ll];
            // debug(ucost,lcost);
            assert((!(i-1ll) && !j) || dir[i-1ll][j] != none);
            assert((!i && !(j-1ll)) || dir[i][j-1ll] != none);
            if (dir[i-1ll][j] == up && geese[i][j-1ll] == one) ucost += k;
            if (dir[i][j-1ll] == left && geese[i-1ll][j] == one) lcost += k;
            if (lcost == ucost) dir[i][j] = both;
            if (lcost < ucost) dir[i][j] = left;
            else dir[i][j] = up;
            // debug(ucost,lcost);
            dp[i][j] = min(ucost,lcost) + a[i][j];
            // debug(dp[i][j]);
            if (j+1ll < m && geese[i][j+1ll] == one) dp[i][j] += k;
            if (i+1ll < n && geese[i+1ll][j] == one) dp[i][j] += k;
            // debug(dp[i][j]);
        }
    }
    debug(dir,dp);
    cout << dp[n-1ll][m-1ll] << endl;
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n)
        rep(j,m) cin >> a[i][j];
    vector<string> geese(n);
    rep(i,n) cin >> geese[i];
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(2,LLONG_MAX)));
    dp[0][0][up] = 0ll;
    dp[0][0][left] = 0ll;
    auto add = [](ll &dest, ll in){
        if (dest == LLONG_MAX || in == LLONG_MAX){
            dest = LLONG_MAX;
            return;
        }
        ull d = dest, i = in;
        if (d+i >= LLONG_MAX){
            dest = LLONG_MAX;
            return;
        }
        dest += in;
    };
    rep(i,n){
        rep(j,m){
            if (!i && !j) continue;
            if (!i){
                dp[i][j][left] = dp[i][j-1ll][left];
                add(dp[i][j][left],a[i][j]);
                if (j+1ll < m && geese[i][j+1ll] == one) add(dp[i][j][left],k);
                if (i+1ll < n && geese[i+1ll][j] == one) add(dp[i][j][left],k);
                continue;
            }
            if (!j){
                dp[i][j][up] = dp[i-1ll][j][up];
                add(dp[i][j][up],a[i][j]);
                if (j+1ll < m && geese[i][j+1ll] == one) add(dp[i][j][up],k);
                if (i+1ll < n && geese[i+1ll][j] == one) add(dp[i][j][up],k);
                continue;
            }
            dp[i][j][left] = dp[i][j][up] = 0ll;

            ll ucost = dp[i-1ll][j][up], lcost = dp[i][j-1ll][left];
            if (geese[i][j-1ll] == one) add(ucost,k);
            if (geese[i-1ll][j] == one) add(lcost,k);
            lcost = min(lcost,dp[i][j-1ll][up]);
            ucost = min(ucost,dp[i-1ll][j][left]);
            dp[i][j][left] = lcost;
            dp[i][j][up] = ucost;
            add(dp[i][j][left],a[i][j]);
            add(dp[i][j][up],a[i][j]);
            if (j+1ll < m && geese[i][j+1ll] == one) add(dp[i][j][left],k);
            if (i+1ll < n && geese[i+1ll][j] == one) add(dp[i][j][left],k);
            if (j+1ll < m && geese[i][j+1ll] == one) add(dp[i][j][up],k);
            if (i+1ll < n && geese[i+1ll][j] == one) add(dp[i][j][up],k);
            // ll ucost = dp[i-1ll][j], lcost = dp[i][j-1ll];
            // assert((!(i-1ll) && !j) || dir[i-1ll][j] != none);
            // assert((!i && !(j-1ll)) || dir[i][j-1ll] != none);
            // if (dir[i-1ll][j] == up && geese[i][j-1ll] == one) ucost += k;
            // if (dir[i][j-1ll] == left && geese[i-1ll][j] == one) lcost += k;
            // if (lcost == ucost) dir[i][j] = both;
            // if (lcost < ucost) dir[i][j] = left;
            // else dir[i][j] = up;
            // dp[i][j] = min(ucost,lcost) + a[i][j];
            // if (j+1ll < m && geese[i][j+1ll] == one) dp[i][j] += k;
            // if (i+1ll < n && geese[i+1ll][j] == one) dp[i][j] += k;
        }
    }
    debug(dp);
    cout << min(dp[n-1ll][m-1ll][left],dp[n-1ll][m-1ll][up]) << endl;
}

/*

3

1
3 3 10
0 4 6
3 7 4
3 5 1
000
010
000

1
3 3 10
0 4 6
3 7 4
3 5 1
000
000
100

1
4 3 80
0 0 312
1 42 234
0 12 7542
234 43 108
000
000
010
100


*/