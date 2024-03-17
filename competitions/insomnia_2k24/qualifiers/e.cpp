/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Mar 17 01:55:42 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> vals(n);
    rep(i,n) cin >> vals[i];
    vector<vector<int>> g(n);
    vector<int> parents(n,-1);
    vector<pair<int,int>> edges(n-1);
    rep(i,n){
        int u, v; cin >> u >> v;--u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u,v};
    }
    vector<int> dp(n,0);
    auto dfs = [&](auto &&self, int node, int parent) -> void {
        parents[node] = parent;
        if (sz(g[node]) == 1 && parent != -1){
            dp[node] = vals[node];
            return;
        }
        for (int v : g[node]){
            if (v == parent) continue;
            self(self,v,node);
            dp[node] += dp[v];
        }
        dp[node] += vals[node];
    };
    dfs(dfs,0,-1);
    debug(parents);
    set<int> pos;
    map<int,int> cts;
    cts[0]++;
    pos.insert(0);
    auto trace = [&](auto &&self, int node, int diff) -> void {
        while(node != -1){
            assert(dp[node] >= diff);
            dp[node]-=diff;
            node = parents[node];
        }
    };
    rep(_,n-1){
        int e, x; cin >> e >> x;
        auto [u,v] = edges[e];
        if (parents[v] != u) swap(u,v);
        assert(parents[v] == u);
        set<int> nvals;
        for (int v : pos){
            nvals.insert(v+dp[v]);
            cts[v+dp[v]]++;
        }
        for (int v : nvals) pos.insert(v);
        trace(trace,u,dp[v]);
        cout << cts[x] << " \n"[_==n-2];
        // if (pos.find(x) != pos.end()) 
    }
}