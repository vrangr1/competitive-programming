#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
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
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST1;
	return 0;
}
vector<bool> visited(2e5);
vector<pair<ll,ll>> coords(2e5);
vector<vector<vector<ll>>> edges(2e5);

void dfs(int p){
    visited[p] = true;
    rep(i,edges[p].size()){
        if (visited[edges[p][i][0]]) continue;
        coords[edges[p][i][0]].first = coords[p].first + edges[p][i][1];
        coords[edges[p][i][0]].second = coords[p].second + edges[p][i][2];
        dfs(edges[p][i][0]);
    }
}
void solve(){
    ll n, m; cin >> n >> m;
    ll a, b, x, y;
    fill(visited.begin(), visited.begin() + n, false);
    rep(i,n) edges[i].clear();
    coords[0].first = 0;
    coords[0].second = 0;
    rep(i,m){
        cin >> a >> b >> x >> y;
        --a;
        --b;
        edges[a].push_back({b,x,y});
        edges[b].push_back({a,-x,-y});
    }
    dfs(0);
    rep(i,n){
        if (!visited[i]){
            cout << "undecidable\n";
            continue;
        }
        cout << coords[i].first << " " << coords[i].second << endl;
    }
}