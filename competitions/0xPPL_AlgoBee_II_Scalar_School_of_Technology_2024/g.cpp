/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Apr 14 21:32:56 IST 2024
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
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i,n-1ll){
        ll u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<ll> dp(n,0ll);
    auto dfs1 = [&](auto &&self, ll node, ll parent) -> void {
        for (ll v : g[node]){
            if (v == parent) continue;
            self(self,v,node);
            dp[node] += dp[v];
        }
        dp[node]++;
    };
    dfs1(dfs1,0,-1);
    auto dfs2 = [&](auto &&self, ll node, ll parent, ll d) -> ll {
        ll sol = 0ll;
        for (ll v : g[node]){
            if (v == parent) continue;
            sol += self(self,v,node,d+1ll);
        }
        return sol+d;
    };
    auto get = [&](ll node, ll parent, ll psum) -> ll {
        assert(node != -1ll && parent != -1ll);
        return psum - dp[node] + (n-dp[node]);
    };
    ll sum = dfs2(dfs2,0,-1,0ll);
    vector<ll> sol = {1};
    debug(sum,sol);
    auto dfs3 = [&](auto &&self, ll node, ll parent, ll csum) -> void {
        for (ll v : g[node]){
            if (v == parent) continue;
            ll vsum = get(v,node,csum);
            if (vsum < sum){
                sum = vsum;
                sol = {v+1};
            }
            else if (vsum == sum){
                sol.push_back(v+1);
            }
            self(self,v,node,vsum);
        }
    };
    dfs3(dfs3,0,-1,sum);
    debug(sum,sol);
    cout << sz(sol) << endl;
    sort(all(sol));
    print_vec(sol);
}