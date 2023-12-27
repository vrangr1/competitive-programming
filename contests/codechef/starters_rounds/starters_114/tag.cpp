/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 27 20:47:12 IST 2023
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

void solve(){
    int n; cin >> n;
    vector<vector<int>> edges(n);
    rep(i,n-1){
        int u, v; cin >> u >> v; --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if (n == 2) return void(cout << "0\n");
    vector<int> leafs(n,0), rdist(n), ldist(n);
    auto dfs = [&] (auto &&self, int node, int parent, int depth) -> void {
        if (sz(edges[node]) == 1 && edges[node][0] == parent){
            leafs[node] = 1;
            ldist[node] = 0;
            rdist[node] = depth;
            return;
        }
        ldist[node] = INT_MAX;
        rdist[node] = depth;
        for (int ngb : edges[node]){
            if (ngb == parent) continue;
            self(self,ngb,node,depth+1);
            leafs[node] += leafs[ngb];
            ldist[node] = min(ldist[node],ldist[ngb]+1);
        }
    };
    dfs(dfs,0,-1,0);
    int mx = 0;
    debug(leafs,rdist,ldist);
    rep(i,n){
        if (ldist[i] == 0 || ldist[i] > rdist[i]) continue;
        mx = max(leafs[i],mx);
    }
    cout << mx << endl;
}