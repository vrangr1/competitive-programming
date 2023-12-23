#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve();

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

bitset<(int)2e3> vis;
auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.first > b.first;
};
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,decltype(comp)> pq(comp);
vector<ll> mindists(2e3);

void dijkstra(ll node, const vector<vector<pair<ll,ll>>> &edges, const ll &n){
    vis[node] = true;
    for (const pair<ll,ll> &edge : edges[node]){
        ll ngb = edge.first;
        if (vis[ngb]) continue;
        if (mindists[ngb] <= mindists[node]+edge.second) continue;
        mindists[ngb] = mindists[node]+edge.second;
        pq.push(make_pair(mindists[ngb],edge.first));
    }
    while(!pq.empty() && vis[pq.top().second])
        pq.pop();
    if (pq.empty()) return;
    dijkstra(pq.top().second, edges, n);
}

void solve(){
    ll n; cin >> n;
    ll a, b, c; cin >> a >> b >> c;
    vector<vector<ll>> d(n,vector<ll>(n));
    rep(i,n)
        rep(j,n)
            cin >> d[i][j];
    vector<vector<pair<ll,ll>>> edges(2*n);
    rep(i,n){
        edges[i].push_back(make_pair(i+n,0ll));
        rep(j,i+1,n-1,1){
            edges[i].push_back(make_pair(j,d[i][j]*a));
            edges[i+n].push_back(make_pair(j+n,(d[i][j]*b)+c));
            edges[j].push_back(make_pair(i,d[i][j]*a));
            edges[j+n].push_back(make_pair(i+n,(d[i][j]*b)+c));
        }
    }
    rep(i,2*n) vis[i] = false;
    while(!pq.empty()) pq.pop();
    rep(i,2*n) mindists[i] = LLONG_MAX;
    mindists[0] = 0;
    dijkstra(0,edges,n);
    cout << min(mindists[n-1],mindists[2*n-1]) << endl;
}