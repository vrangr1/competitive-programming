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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = 998244353;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> edges(n);
    rep(i,n-1){
        ll u; cin >> u;
        --u;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    vector<pair<ll,ll>> balls(m);
    rep(i,m){
        cin >> balls[i].first >> balls[i].second;
        --balls[i].first;
        --balls[i].second;
    }
    vector<ll> cts(n,1ll);
    auto dfs = [&] (auto self, int node, int parent, ll mxct) -> void {
        cts[node] = 1ll;
        ll ct = 0;
        for (int ngb : edges[node]){
            if (ngb == parent) continue;
            self(self, ngb, node);
            ct++;
            cts[node] *= cts[ngb];
            cts[node]%=mod;
        }
        if (ct == 2ll) cts[node]*=2ll;
        cts[node]%=mod;
    };
    dfs(dfs,0,-1, k);
    cout << cts[0] << endl;
}