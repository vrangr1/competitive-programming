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
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

vector<vector<int>> edges(2e5);
vector<int> mshortest(2e5), vshortest(2e5);
bitset<(int)2e5> create, vis;

void bfs(int start, vector<int> &dist){
    vis.reset();
    int cur_dist = 0, node;
    dist[start] = cur_dist;
    vis[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for (int neighbor : edges[node]){
            if (vis[neighbor]) continue;
            dist[neighbor] = dist[node]+1;
            vis[neighbor] = true;
            q.push(neighbor);
        }
    }
}

bool dfs(int node, const int parent){
    vis[node] = true;
    for(int neighbor : edges[node]){
        if (neighbor == parent) continue;
        if (vis[neighbor] && mshortest[neighbor] > vshortest[neighbor]) return true;
        else if (vis[neighbor]) continue;
        if(dfs(neighbor, node)) return true;
    }
    return false;
}

void solve(){
    int n, M, V; cin >> n >> M >> V; 
    create.reset();
    int u, v;
    rep(i,n){
        cin >> u >> v;
        if (!create[u]) edges[u].clear();
        if (!create[v]) edges[v].clear();
        create[u] = true;
        create[v] = true;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if (M == V) return void(cout << no);
    fill(mshortest.begin(), mshortest.begin() + n, INT_MAX);
    fill(vshortest.begin(), vshortest.begin() + n, INT_MAX);
    bfs(M, mshortest);
    bfs(V, vshortest);
    vis.reset();
    if (dfs(V,-1)) cout << yes;
    else cout << no;
}