/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar  9 18:15:56 IST 2024
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
    ll n; cin >> n;
    vector<vector<ll>> p(n,vector<ll>(n)), r(n,vector<ll>(n-1)), d(n-1,vector<ll>(n));
    rep(i,n) rep(j,n) cin >> p[i][j];
    rep(i,n) rep(j,n-1ll) cin >> r[i][j];
    rep(i,n-1ll) rep(j,n) cin >> d[i][j];
    auto comp = [&](const ll sx, const ll sy, const ll dx, const ll dy) -> ll {
        assert(sx <= dx && sy <= dy);
        vector<vector<ll>> dp(n,vector<ll>(n));
        dp[sx][sy] = 0ll;
        if (sx == dx && sy == dy) return 0ll;
        rep(y,sy+1ll,n-1ll,1){
            dp[sx][y] = dp[sx][y-1ll] + r[sx][y-1ll];
            if (sx == dx && y == dy) return dp[dx][dy];
        }
        rep(x,sx+1ll,n-1ll,1){
            rep(y,sy,n-1ll,1){
                if (y == sy) dp[x][y] = dp[x-1ll][y] + d[x-1ll][y];
                else dp[x][y] = min(dp[x-1ll][y]+d[x-1ll][y],dp[x][y-1ll]+r[x][y-1ll]);
                if (x == dx && y == dy) return dp[dx][dy];
            }
        }
        assert(false);
        return dp[dx][dy];
    };
    ll sol = LLONG_MAX;
    rep(x,n){
        rep(y,n){
            ll cost = comp(0,0,x,y) + comp(x,y,n-1,n-1);
            sol = min(sol, ((cost + p[x][y]-1ll)/p[x][y]));
        }
    }
    cout << sol + (2ll*(n-1ll)) << endl;
}