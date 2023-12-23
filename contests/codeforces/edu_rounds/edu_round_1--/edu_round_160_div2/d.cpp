/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec 18 20:55:30 IST 2023
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

const ll mod = 998244353ll;

void solve(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    if (n == 1ll) return void(cout << "1\n");
    vector<ll> dp(n+1ll,0), nxt(n,-1);
    nxt.back() = n;
    rep(i,n-2,0ll,-1ll){
        nxt[i] = i+1;
        while(nxt[i] < n && p[nxt[i]] > p[i])
            nxt[i] = nxt[nxt[i]];
    }
    ll sum = 0ll;
    dp[0] = 1ll;
    debug(nxt);
    rep(i,n){
        dp[i+1] += dp[i];
        dp[nxt[i]] += dp[i];
        if (nxt[i] == n){
            sum += dp[i];
            sum %= mod;
        }
    }
    debug(dp);
    cout << sum << endl;
}

/*

_ _ _ _ _ _ _ _ x _ _ _ _ _ _ v

_ _ _ _ _ _ _ _ 10 13 14 15 16 17 18 12



ns ns sm _ _ _ _ sm _ _ _ sm _ _ _
sm ns sm
smallest    _ _ _ _ _ _ [smallest _ _ _ [smallest _ _ _]

3

1
2
2 1

4
2 4 1 3

1
5
10 2 6 3 4

10 2 6 3 4
10 2 3 4
2 6 3 4
2 3 4
10 2 4
2 4


*/