/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Mar 26 20:18:38 IST 2024
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

const ll mod = (ll)1e9+7ll;

void solve(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<vector<ll>> adj(n);
    rep(i,n-1){
        ll u, v; cin >> u >> v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dp(n,1ll);
    ll root = n;
    auto dfs1 = [&](auto &&self, ll node, ll parent) -> void {
        for (ll v : adj[node]){
            if (v == parent) continue;
            self(self,v,node);
            dp[node] = max(dp[node],dp[v]+1);
        }
    };
    dfs1(dfs1,0,-1);
    vector<ll> dp2(n,LLONG_MAX);
    auto dfs = [&](auto &&self, ll node, ll parent) -> ll {
        set<pair<ll,ll>> st;
        for (ll v : adj[node]){
            st.emplace(dp[v],-v);
            if (sz(st) > 2) st.erase(st.begin());
        }
        assert(sz(st) <= 2 && !st.empty());
        if (sz(st) == 1ll){
            assert(dp2[node] == LLONG_MAX);
            auto [nd,nxt] = *st.begin();
            nxt=-nxt;
            dp2[node] = nd;
            dp[node] = 1;
            if (nxt == parent){
                assert(dp2[nxt] != LLONG_MAX);
                if (dp2[nxt] > dp2[node]) return node;
                else if (dp2[nxt] < dp2[node]) return nxt;
                return min(nxt,node);
            }
            return self(self,nxt,node);
        }
        auto [nd,nxt] = *st.rbegin();
        auto [od,oxt] = *st.begin();
        nxt = -nxt;
        oxt = -oxt;
        assert(dp2[node] == LLONG_MAX);
        dp2[node] = nd;
        if (nxt == parent){
            assert(dp2[nxt] != LLONG_MAX);
            if (dp2[nxt] > dp2[node]) return node;
            else if (dp2[nxt] < dp2[node]) return nxt;
            return min(nxt,node);
        }
        dp[node] = od+1;
        return self(self,nxt,node);
    };
    root = dfs(dfs,0,-1);
    assert(root != n);
    debug(root);
    vector<ll> ct(n,0ll);
    auto dfs2 = [&](auto &&self, ll node, ll parent, ll d) -> void {
        assert(d < sz(ct));
        ct[d] += p[node];
        ct[d] %= mod;
        for (ll v : adj[node]){
            if (v == parent) continue;
            self(self,v,node,d+1);
        }
    };
    dfs2(dfs2,root,-1,0);
    debug(ct);
    reverse(all(ct));
    ll sol = 0ll;
    ll t = 1;
    ct.pop_back();
    while(!ct.empty()){
        ll k = 0ll;
        while(k <= 2ll && !ct.empty()){
            sol += (t*ct.back());
            sol%=mod;
            ct.pop_back();
            ++k;
        }
        ++t;
    }
    cout << sol << endl;
}

/*

0 1 2 3 4 5 6 7 8 9 10
0
  1 1 
    _ 2 2
      _ _ 3 3
        _ _ _ 4 4
1 (2,5)
|
4
|
6
|
3

*/