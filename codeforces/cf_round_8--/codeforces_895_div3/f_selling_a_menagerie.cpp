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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

bitset<(int)1e5> vis;

void dfs(int node, vector<int> &deg, vector<int> &order, const vector<int> &a){
    vis[node] = true;
    deg[a[node]]--;
    order.push_back(node);
    if(deg[a[node]] == 0)
        dfs(a[node], deg, order, a);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), deg(n);
    rep(i,n){
        cin >> a[i]; --a[i];
        deg[a[i]]++;
        vis[i] = false;
    }
    vector<int> cost(n);
    rep(i,n) cin >> cost[i];
    vector<int> order;
    rep(i,n){
        if (vis[i] || deg[i] > 0) continue;
        dfs(i, deg, order, a);
    }
    rep(i,n){
        if (vis[i]) continue;
        vector<int> cycle, costs;
        for(int j = i; !vis[j]; j = a[j]){
            cycle.push_back(j);
            vis[j] = true;
            costs.push_back(cost[j]);
        }
        int ind = min_element(all(costs)) - costs.begin();
        if (ind < (int)cycle.size() - 1)
            rotate(cycle.begin(), cycle.begin() + ind + 1, cycle.end());
        order.insert(order.end(), all(cycle));
    }
    assert((int)order.size() == n);
    rep(i,n)
        cout << order[i]+1 << " \n"[i==n-1];
}