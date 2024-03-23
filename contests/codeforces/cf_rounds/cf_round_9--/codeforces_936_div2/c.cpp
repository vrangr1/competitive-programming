/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 22 20:42:31 IST 2024
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

void solve(){
    int n, k; cin >> n >> k;
    int mx = (n/(k+1));
    vector<vector<int>> adj(n);
    rep(i,n-1){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int tot = 0ll;
    auto dfs = [&](auto &&self, int node, int parent, const int com) -> int {
        if (sz(adj[node]) == 1 && parent != -1){
            return 1;
        }
        int ct = 0;
        for (int v : adj[node]){
            if (v == parent) continue;
            int c = self(self, v, node, com);
            if (c >= com){
                tot++;
                continue;
            }
            ct += c;
        }
        return ct+1;
    };
    auto pos = [&](int com) -> bool {
        tot = 0;
        int f = dfs(dfs,0,-1,com);
        if (f >= com) tot++;
        return tot >= k+1;
    };
    debug(mx);
    auto bsch = [&pos](auto &&self, int low, int high) -> int {
        if (low == high) return low;
        int mid = (low+high+1)/2;
        if (pos(mid)) return self(self,mid,high);
        return self(self,low,mid-1);
    };
    cout << bsch(bsch, 1, mx) << endl;
}

/*


6

1
5 1
1 2
1 3
3 4
3 5


2 1
1 2
6 1
1 2
2 3
3 4
4 5
5 6
3 1
1 2
1 3
8 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
6 2
1 2
2 3
1 4
4 5
5 6




*/