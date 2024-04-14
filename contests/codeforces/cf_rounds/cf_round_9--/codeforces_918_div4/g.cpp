/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 30 03:23:14 IST 2023
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

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<vector<ll>>> edges(n);
    rep(i,m){
        ll u, v, w; cin >> u >> v >> w; --u;--v;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    vector<ll> s(n);
    ll mn = *min_element(all(s));
    rep(i,n) cin >> s[i];
    
    vector<bool> vis(n,false);
    vector<ll> sol(n,LLONG_MAX);
    sol[0] = 0;
    auto comp = [](const vector<ll>&a, const vector<ll> &b){
        // if (a[2] != b[2]) return a[2] > b[2];
        return a[0] > b[0];
    };
    priority_queue<vector<ll>,vector<vector<ll>>, decltype(comp)> pq(comp);
    pq.push({0ll,0ll,s[0]});
    while(!pq.empty()){
        ll node = pq.top().at(1);
        ll w = pq.top().at(0);
        if (node == n-1ll && s[node] == mn) return void(cout << sol[node] << endl);
        ll cyc = pq.top().at(2);
        s[node] = min(s[node],cyc);
        pq.pop();
        // vis[node] = true;
        for(auto edge : edges[node]){
            ll ngb = edge[0], ew = edge[1];
            if (sol[ngb] < w+s[node]*ew && s[ngb] <= s[node]) continue;
            sol[ngb] = min(sol[ngb],w+s[node]*ew);
            pq.push({w+s[node]*ew,ngb,s[node]});
        }
    }
    assert(sol[n-1ll] != LLONG_MAX);
    cout << sol[n-1ll] << endl;
}