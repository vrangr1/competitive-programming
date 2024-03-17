/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 22:47:10 IST 2024
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
    int n, k; cin >> n >> k;
    if (n == 1ll) return void(cout << no);
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v; --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dists(n,0ll);
    ll mxnode = 0ll, mxdist = 0;
    auto dfs = [&](auto &&self, ll node, ll parent, ll d) -> void {
        if (mxdist < d){
            mxdist = d;
            mxnode = node;
        }
        if (sz(g[node]) == 1ll && g[node][0] == parent){
            dists[node] = d;
            return;
        }
        dists[node] = d;
        for (ll v : g[node]){
            if (v == parent) continue;
            self(self,v,node,d+1ll);
        }
    };
    dfs(dfs,0,-1,0);
    ll root = mxnode;
    mxnode = mxdist = 0ll;
    dfs(dfs,root,-1ll,0ll);
    ll leaf = mxnode;
    assert(sz(g[leaf]) == 1ll);
    ll diam = mxdist+1ll;
    vector<ll> marks(n,false);
    vector<ll> ctr;
    debug(diam);
    debug(root,leaf);
    auto mark = [&](auto &&self, ll node, ll parent, ll d) -> bool {
        if (sz(g[node]) == 1ll && g[node][0] == parent){
            if (node == leaf && diam <= 2ll) ctr.push_back(node);
            marks[node] = node==leaf;
            return node == leaf;
        }
        bool rec = false;
        for (ll v : g[node]){
            if (v == parent) continue;
            rec |= self(self,v,node,d+1ll);
        }
        marks[node] = rec;
        if (rec){
            if (diam%2ll && d == diam/2ll)
                ctr.push_back(node);
            else if (diam%2ll == 0ll && (d == diam/2ll - 1ll || d == diam/2ll))
                ctr.push_back(node);
        }
        return rec;
    };
    mark(mark,root,-1,0);
    if (diam%2ll) assert(sz(ctr) == 1);
    else assert(sz(ctr) == 2);
    ll sol = diam;
    
    sol--;
    if (sol > k) cout << yes;
    else cout << no;
    return;
    
    vector<ll> vis(n,false);
    auto get = [&](auto &&self, ll node, ll parent) -> ll {
        vis[node] = true;
        if (sz(g[node]) == 1ll)
            return 1ll;
        ll ct = 0ll;
        // ll sum = 0ll;
        for (ll v : g[node]){
            if (v == parent) continue;
            ll val = self(self,v,node);
            ct = max(ct,val);
            // sum += val;
        }
        // debug(node,ct,sum);
        // sum-=ct;
        // sol += sum;
        return ct+1ll;
    };
    // debug(root,leaf);
    debug(sol,marks);
    rep(node,n){
        if (!marks[node]) continue;
        for (ll v : g[node]){
            if (marks[v] || vis[v]) continue;
            debug(v);
            vis[v] = true;
            sol += get(get,v,node)-1ll;
        }
    }
    sol--;
    debug(sol);
    if (sol > k) cout << yes;
    else cout << no;
}