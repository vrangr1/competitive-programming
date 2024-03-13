/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Feb 16 20:32:47 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = 998244353ll;

void solve1(){
    ll n; cin >> n;
    vector<vector<ll>> edges(n);
    rep(i,n-1ll){
        ll u, v; cin >> u >> v; --u;--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    auto pr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0ll) return 1ll;
        ll a2 = (a*a)%mod;
        if (n%2ll) return (a*self(self,a2,n/2ll))%mod;
        return self(self,a2,n/2ll);
    };
    if (n <= 2ll) return void(cout << pr(pr,2ll,n) << endl);
    [[maybe_unused]]auto inv = [](auto &&self, ll n) -> ll {
        if (n <= 1ll) return 1ll;
        return ((mod - mod/n)*self(self,mod%n))%mod;
    };
    auto diff = [](ll a, ll b) -> ll {
        a%=mod;
        b%=mod;
        return (a-b+mod)%mod;
    };
    ll sol = pr(pr,2ll,n);
    debug(sol);
    auto dfs = [&](auto &&self, ll node, ll parent, ll depth) -> void {
        if (sz(edges[node]) == 1ll && edges[node][0] == parent && depth >= 2ll){
            // leaf node
            ll bad, t = pr(pr,2ll,n-depth);
            bad = diff(pr(pr,2ll,depth),depth+1ll);
            bad = diff(bad,(depth*(depth-1ll))/2ll);
            bad = (bad*t)%mod;
            bad += ((((depth*(depth-1ll))/2ll)%mod)*(diff(t,1ll)))%mod;
            debug(bad);
            sol = diff(sol,bad);
            return;
        }
        for (ll ngb : edges[node]){
            if (ngb == parent) continue;
            self(self,ngb,node,depth+1ll);
        }
    };
    dfs(dfs,0ll,-1ll,1ll);
    cout << sol << endl;
}

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i,n-1ll){
        ll u, v; cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n,-1);
    ll sol = 0ll;
    auto dfs = [&](auto &&self, ll node, ll parent) -> void {
        if (sz(g[node]) == 1 && g[node][0] == parent){
            dp[node] = 2ll;
            return;
        }
        ll prod = 1ll;
        for (ll v : g[node]){
            if (v == parent) continue;
            self(self,v,node);
            prod *= dp[v];
            prod%=mod;
            sol += (dp[v]-1ll);
            sol%=mod;
        }
        dp[node] = (prod+1ll)%mod;
    };
    dfs(dfs,0,-1ll);
    debug(sol,dp);
    sol += dp[0];
    sol%=mod;
    cout << sol << endl;
}