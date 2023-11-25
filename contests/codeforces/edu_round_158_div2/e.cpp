/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
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

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> edges(n);
    vector<ll> deg(n,0ll);
    ll u, v;
    rep(i,n-1ll){
        cin >> u >> v; --u;--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    // vector<bool> removed(n,false);
    auto recurse = [&](auto self, ll node) -> void {
        if (deg[node] > 1) return;
        assert(deg[node] == 1);
        if (a[node] > 0) return;
        ll ngb = edges[node][0];
        edges[node].clear();
        edges[ngb].erase(find(all(edges[ngb]), node));
        self(self,ngb);
    };
    rep(i,n)
        recurse(recurse,i);
    vector<ll> sums(n,0ll);
    auto dfs = [&](auto self, ll node, ll parent) -> void {
        sums[node] = a[node];
        ll child = -1, c2 = -1;
        for(ll ngb : edges[node]){
            if (ngb == parent) continue;
            self(self, ngb, node);
            sums[node] += sums[ngb];
            if (child == -1)
                child = ngb;
            else c2 = ngb;
        }
        if (edges[node].size() == 1){
            return;
        }
        if (edges[node].size() == 2){
            if (a[node] > 0) return;
            if (parent == -1) return;
            edges[parent].push_back(child);
            edges[parent].erase(find(all(edges[parent]), node));
            return;
        }
        if (a[node] >= 0) return;
        if (parent == -1) return;
        if (sums[child] < -a[node]){
            edges[parent].push_back(child);
            edges[parent].erase(find(all(edges[parent]), node));
        }
    };
}