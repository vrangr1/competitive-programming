/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec 10 22:16:52 IST 2023
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
#endif

using namespace std;

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
#define pass (void)0
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

class Solution {
  public:
    vector<ll> magicTree(ll n, vector<vector<int>> &gedges) {
        vector<vector<vector<ll>>> edges(n);
        for (const auto &edge : gedges){
            edges[edge[0]].push_back({edge[1],edge[2]});
            edges[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<ll> sol(n,LLONG_MAX);
        for (ll i = 0; i < n; ++i) if (edges[i].size() == 1) sol[i] = 0ll;
        auto dfs = [&] (auto self, ll node, ll parent) -> void {
            if (edges[node].size() <= 1) return;
            assert(sol[node] == LLONG_MAX);
            for (auto & edge : edges[node]){
                if (edge[0] == parent) continue;
                self(self,edge[0],node);
                sol[node] = min(sol[node],sol[edge[0]]+edge[1]);
            }
        };
        ll root = -1;
        for (ll i = 0; i < n; ++i){
            if (edges[i].size() <= 1) continue;
            root = i;
            dfs(dfs,i,-1ll);
            break;
        }
        auto dfs2 = [&] (auto self, ll node, ll parent) -> void {
            for (const auto &edge : edges[node]){
                if (edge[0] == parent) continue;
                if (sol[edge[0]] <= sol[node]+edge[1]) continue;
                sol[edge[0]] = sol[node]+edge[1];
                self(self,edge[0],node);
            }
        };
        dfs2(dfs2,root,-1);
        return sol;
    }
};

void solve(){
    ll n; cin >> n;
    vector<vector<int>> edges;
    rep(i,n-1ll){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    Solution sol;
    print_vec(sol.magicTree(n,edges));
}