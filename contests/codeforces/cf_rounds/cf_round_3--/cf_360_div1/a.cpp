/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb 13 19:32:26 IST 2024
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
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n);
    rep(i,m){
        int u, v; cin >> u >> v;
        --u;--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<set<int>> sts(2);
    auto bfs = [&](int node) -> bool {
        sts[0].clear();
        sts[1].clear();
        vector<bool> vis(n,false);
        sts[0].insert(node);
        vis[node] = true;
        queue<int> q;
        q.push(node);
        int flty = 0;
        set<int> rem;
        rep(i,n) rem.insert(i);
        rem.erase(0);
        while(!rem.empty()){
            if (q.empty()){
                assert(!rem.empty());
                node = *rem.begin();
                assert(node < n);
                q.push(node);
                vis[node] = true;
                rem.erase(node);
                sts[flty].insert(node);
            }
            while(!q.empty()){
                int s = sz(q);
                flty = 1-flty;
                while(s--){
                    node = q.front();
                    q.pop();
                    for (int ngb : edges[node]){
                        if (vis[ngb] && sts[flty].find(ngb) == sts[flty].end())
                            return false;
                        if (vis[ngb]) continue;
                        sts[flty].insert(ngb);
                        vis[ngb] = true;
                        rem.erase(ngb);
                        q.push(ngb);
                    }
                }
            }
        }
        return true;
    };
    if (!bfs(0)) return void(cout << "-1\n");
    cout << sz(sts[0]) << endl;
    for (auto it = sts[0].begin(); it != sts[0].end(); ++it)
        cout << (*it) + 1 << " \n"[it == prev(sts[0].end())];
    cout << sz(sts[1]) << endl;
    for (auto it = sts[1].begin(); it != sts[1].end(); ++it)
        cout << (*it) + 1 << " \n"[it == prev(sts[1].end())];
}