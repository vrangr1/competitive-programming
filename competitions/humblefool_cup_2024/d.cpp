/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Apr 16 21:40:21 IST 2024
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<pair<ll,ll>>> ints(n);
    auto dfs = [&](auto &&self, ll node, ll parent, ll st, ll ind) -> bool {
        if (node == ind) return true;
        bool cur = false;
        for (ll v : g[node]){
            if (v == parent) continue;
            ll nxt;
            if (node == 0ll) nxt = st;
            else nxt = st+(node*node)+(ind*ind);
            bool ck = self(self,v,node,nxt,ind);
            if (ck)
                ints[node].emplace_back(st,nxt);
            cur |= ck;
        }
        return cur;
    };
    rep(i,1,n-1ll,1ll)
        dfs(dfs,0,-1ll,i,i);
    debug(ints);
    rep(i,1,n-1ll,1){
        if (ints[i].empty()){
            cout << "0\n";
            continue;
        }
        sort(all(ints[i]));
        vector<pair<ll,ll>> cur;
        debug(i,ints[i]);
        for (auto [l,r] : ints[i]){
            if (cur.empty() || l > cur.back().second)
                cur.emplace_back(l,r);
            else cur.back().second = r;
        }
        debug(cur);
        ll sol = 0ll;
        for (auto [l,r] : cur)
            sol += r-l;
        cout << sol << endl;
        swap(ints[i],cur);
    }
    debug(ints);
}