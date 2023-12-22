/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 21:56:46 IST 2023
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

const ll mod = (ll)1e9+7;

ll inv(ll n){
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

const ll rat = 0, som = 1;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> edges(n);
    rep(i,n-1ll){
        ll u, v; cin >> u >> v;--u;--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if (n <= 2ll){
        cout << (a[0]+a[1])%mod << endl;
        return;
    }
    vector<vector<ll>> ideal(n,vector<ll>(2,-1ll));
    vector<ll> dir(n,-1);
    auto dfs = [&] (auto &&self, ll node, ll parent) -> void {
        if (sz(edges[node]) == 1ll && edges[node][0] == parent){
            ideal[node][0] = ideal[node][1] = a[node];
            return;
        }
        ideal[node][rat] = ideal[node][som] = a[node];
        ll mx = LLONG_MIN, mn = LLONG_MAX;
        ll mxdir = -1;
        for (auto ngb : edges[node]){
            if (ngb == parent) continue;
            self(self,ngb,node);
            if (mx == ideal[ngb][som]) mxdir = min(mxdir,ngb);
            if (mx < ideal[ngb][som]) mxdir = ngb;
            mx = max(mx,ideal[ngb][som]);
            mn = min(mn,ideal[ngb][rat]);
        }
        ideal[node][rat] += mx;
        ideal[node][som] += mn;
        dir[node] = mxdir;
    };
    dfs(dfs,0ll,-1ll);
    vector<vector<ll>> exp(n,vector<ll>(2ll,0ll));
    auto d2 = [&] (auto &&self, ll node, ll parent) -> void {
        if (sz(edges[node]) == 1ll && edges[node][0] == parent){
            exp[node][rat] = exp[node][som] = a[node];
            return;
        }
        ll k = sz(edges[node])-1ll;
        for (auto ngb : edges[node]){
            if (ngb == parent) continue;
            self(self,ngb,node);
            exp[node][som] += exp[ngb][rat];
            exp[node][som] %= mod;
        }
        exp[node][som] *= inv(k);
        exp[node][som] %= mod;
        exp[node][som] += a[node];
        exp[node][som] %= mod;
        exp[node][rat] = (exp[dir[node]][som] + a[node])%mod;
    };
    d2(d2,0,-1);
    cout << exp[0][rat] << endl;
}