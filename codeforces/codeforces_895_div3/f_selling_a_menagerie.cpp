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
* Nick : vrangr
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
#define debug
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
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
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

void handle_loop(int node, int &cmin, int &mindex, const vector<int> &edges, const vector<int> &weights, vector<int> &loop, int &sz){
    if (loop[node] != -1) return;
    loop[node] = 1;
    if (cmin > weights[node]){
        cmin = weights[node];
        mindex = sz;
    }
    sz++;
    handle_loop(edges[node], cmin, mindex, edges, weights, loop, sz);
}

void dfs(int node, const vector<int> &edges, const vector<int> &weights, vector<int> &order, vector<bool> &visited, vector<int> &loop, vector<int> &loop_order){
    if (loop[node] != -1){
        assert(visited[node]);
        return;
    }
    if (visited[node]){
        auto iter = find(order.begin(), order.end(), node);
        assert(iter != order.end());
        vector<int> norder(iter, order.end());
        if (iter == order.begin()) order.clear();
        else order.erase(iter, order.end());
        loop[norder[0]] = 1;
        int cmin = weights[norder[0]], mindex = 0, sz = 1;
        handle_loop(edges[norder[0]], cmin, mindex, edges, weights, loop, sz);
        assert(sz == norder.size());
        if (mindex != norder.size() - 1)
            rotate(norder.begin(), norder.begin() + mindex+1,norder.end());
        loop_order.insert(loop_order.end(), norder.begin(), norder.end());
        return;
    }
    visited[node] = true;
    order.push_back(node);
    dfs(edges[node], edges, weights, order, visited, loop, loop_order);
}

void solve(){
    int n; cin >> n;
    vector<int> edges(n), parent(n,-1);
    forn(i,n){
        cin >> edges[i];
        edges[i]--;
        parent[edges[i]] = i;
    }
    vector<int> weights(n), loop(n,-1);
    forn(i,n) cin >> weights[i];
    vector<bool> visited(n,false);
    vector<int> ans, loop_order;
    forn(i,n){
        if (visited[i]) continue;
        if (parent[i] != -1) continue;
        vector<int> order;
        dfs(i, edges, weights, order, visited, loop, loop_order);
        ans.insert(ans.end(), order.begin(), order.end());
    }
    forn(i,n){
        if (visited[i]) continue;
        vector<int> order;
        dfs(i, edges, weights, order, visited, loop, loop_order);
        assert(order.size() == 0);
    }
    ans.insert(ans.end(), loop_order.begin(), loop_order.end());
    forn(i, ans.size())
        cout << ans[i]+1 << " \n"[i==ans.size()-1];
}