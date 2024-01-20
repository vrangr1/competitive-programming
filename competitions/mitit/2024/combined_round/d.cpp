/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 20 21:15:51 IST 2024
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
void solve(int x);

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	int T,x;cin>>T>>x;while(T--)solve(x);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

#define red 0
#define green0 1
#define green1 2
#define green2 3
#define green 4

void solve0(){
    ll n; cin >> n;++n;
    vector<ll> p(n);
    vector<vector<ll>> children(n);
    p.front() = -1;
    rep(i,1,n-1,1){
        cin >> p[i];
        --p[i];
        children[p[i]].push_back(i);
        // children[i].push_back(p[i]);
    }
    if (n <= 2)
        return void(cout << "1\n");
    vector<vector<ll>> dp(n,vector<ll>(5,0));
    auto inc = [](const vector<ll> &node) -> ll {
        return max(0ll,node[red]-(node[green]-1ll));
    };
    auto dfs = [&] (auto &&self, ll node, ll parent) -> void {
        dp[node][green0] = 1;
        dp[node][green] = 1;
        // if (parent != -1 && sz(children[node]) == 1){
        //     if (children[node][0] != parent){
        //         debug(node,parent,children[node]);
        //     }
        //     assert(children[node][0] == parent);
        //     return;
        // }
        ll gsum = 0;
        ll ct = 0;
        vector<ll> mx1, mx2;
        for (const ll &ngb : children[node]){
            if (ngb == parent) continue;
            self(self,ngb,node);
            gsum += dp[ngb][green];
            dp[node][red] += max({dp[ngb][red],dp[ngb][green0],dp[ngb][green1]});
            ct++;
            if (mx1.empty() || inc(mx1) < inc(dp[ngb])){
                swap(mx1,mx2);
                mx1 = dp[ngb];
                continue;
            }
            if (mx2.empty() || inc(mx2) < inc(dp[ngb]))
                mx2 = dp[ngb];
        }
        dp[node][green0] = max(dp[node][green0],gsum-ct+1ll);
        if (ct >= 1ll && !mx1.empty())
            dp[node][green1] = max(0ll,gsum-mx1[green]-(ct-1ll)+1ll+mx1[red]);
        if (ct >= 2ll && !mx1.empty() && !mx2.empty())
            dp[node][green2] = max(0ll,gsum-mx1[green]-mx2[green]-(ct-2ll)+1ll+mx1[red]+mx2[red]);
        dp[node][green] = max({dp[node][green0],dp[node][green1],dp[node][green2]});
    };
    dfs(dfs,0,-1);
    debug(dp);
    cout << max(dp[0][red], dp[0][green]) << endl;
}

void solve1(){
    ll n; cin >> n;++n;
    vector<ll> a(n);
    a.front() = -1;
    // vector<vector<ll>> dp(n,vector<ll>(2,-1));
    // dp[0][red] = 0;
    // dp[0][green] = 1;
    // auto follow = [&](auto &&self, ll node, ll color) -> void {
        
    // };
    // auto process = [&](ll node) {
    //     assert(dp[node][red] == dp[node][green] && dp[node][red] == -1);
    // };
    rep(i,1,n-1,1){
        cin >> a[i];
        --a[i];
        // ll k = i+1;

    }
    cout << "0\n";
}

void solve(int x){
    if (x) solve1();
    else solve0();
}