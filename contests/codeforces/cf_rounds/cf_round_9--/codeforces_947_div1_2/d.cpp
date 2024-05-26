/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat May 25 21:06:33 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    ll a, b; cin >> a >> b; --a;--b;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll u, v; cin >> u >> v; --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> d(n), dp(n,0);
    d[a] = 0;
    auto dfs = [&](auto &&self, ll node, ll parent) -> void {
        for (ll v : g[node]) {
            if (v == parent) continue;
            d[v] = d[node]+1;
            self(self,v,node);
            dp[node] += 2ll + dp[v];
        }
    };
    dfs(dfs,a,-1);
    ll mx = *max_element(all(d)), ct = count(all(d),mx);
    vector<ll> path(n,false);
    if (ct == 1) {
        auto dfs1 = [&](auto &&self, ll node, ll parent) -> void {
            ll fct = 0;
            for (ll v : g[node]) {
                if (v == parent) continue;
                self(self,v,node);
                if (!path[v]) fct++;
                else path[node] = (fct == 0ll);
                if (!path[v]) path[node] = false;
            }
            if (d[node] == mx) path[node] = true;
        };
        dfs1(dfs1,a,-1);
    }
    debug(path);
    ll sol;
    if (a == b) return void(cout << dp[a]-mx << endl);
    if (sz(g[a]) > 1) {
        if (!path[b]) {
            sol = dp[a]-mx;
            if (d[b]%2ll) sol++;
            cout << sol << endl;
            return;
        }
        assert(ct==1ll);
        ll nxt = LLONG_MIN;
        rep(i,n) {
            ll dep = d[i];
            if (dep != mx && !path[i]) nxt = max(nxt,dep);
        }
        assert(nxt != LLONG_MIN);
        assert(path[a]);
        sol = d[b]+dp[a]-mx;
        ll other = dp[a]-nxt;
        if (d[b]%2ll) other++;
        sol = min(sol,other);
        cout << sol << endl;
        return;
    }
    if (!path[b]) {
        sol = dp[a];
        if (d[b]%2ll) sol++;
        cout << sol << endl;
        return;
    }
    assert(ct == 1ll);
    ll nxt = LLONG_MIN;
    rep(i,n) {
        ll dep = d[i];
        if (dep != mx && !path[i]) nxt = max(nxt,dep);
    }
    if (nxt == LLONG_MIN) {
        // chain
        assert(dp[a] - mx == n-1ll);
        sol = dp[a];
        if (d[b]%2ll) sol++;
        sol = min(sol,d[b]+n-1ll);
        cout << sol << endl;
        return;
    }
    debug(d,dp,mx,nxt);
    sol = d[b]+dp[a]-mx;
    ll other = dp[a];
    if (d[b]%2ll) other++;
    sol = min(sol,other);
    cout << sol << endl;
}