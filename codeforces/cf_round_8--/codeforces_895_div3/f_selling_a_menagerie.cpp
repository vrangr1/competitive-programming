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
    const bool DEBUG = false;
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
unordered_set<int> path;

void dfs(int node, const vector<int> &a, vector<bool> &isloop, vector<bool> &start, int &loopend, bool &loop_found, bool &last){
    assert(node < (int)a.size());
    assert(node >= 0);
    // debug(node);
    vis[node] = true;
    path.insert(node);
    if (path.find(a[node]) != path.end()){
        // debug('h');
        loop_found = true;
        loopend = a[node];
        isloop[node] = true;
        return;
    }
    if (vis[a[node]]){
        if (isloop[a[node]]) start[node] = true;
        return;
    }
    dfs(a[node],a,isloop,start,loopend,loop_found,last);
    // debug(node, loop_found, loopend);
    isloop[node] = loop_found;
    if (last){
        // debug(node, loop_found, loopend, isloop);
        assert(!loop_found);
        assert(loopend == -1);
        start[node] = true;
        last = false;
    }
    if (node == loopend){
        loopend = -1;
        loop_found = false;
        assert(!last);
        last = true;
    }
}

void recog_loops(const vector<int> &a, vector<bool> &isloop, vector<bool> &start){
    int n = a.size();
    bool loop_found = false, last = false;
    int loopend = -1;
    rep(i,n){
        if (vis[i]) continue;
        assert(!loop_found);
        assert(loopend == -1);
        path.clear();
        dfs(i, a, isloop, start, loopend, loop_found, last);
        last = false;
    }
    rep(i,n) vis[i] = false;
}

void handle_loop(int node, const vector<int> &a, const vector<ll> &cost, vector<int> &order, int &mnind, ll &mncost){
    vis[node] = true;
    order.push_back(node);
    if (mncost > cost[node]){
        mnind = order.size()-1;
        mncost = cost[node];
    }
    if (vis[a[node]]){
        assert(mnind >= 0 && mnind < (int)order.size());
        if(mnind != (int)order.size()-1)
            rotate(order.begin(), order.begin()+mnind+1,order.end());
        mnind = -1;
        mncost = INT_MAX;
        return;
    }
    handle_loop(a[node], a, cost, order, mnind, mncost);
}

void handle_loops(int n, const vector<int> &a, const vector<ll> &cost, const vector<bool> &isloop, vector<int> &order, vector<int> &loop){
    int mnind = -1;
    ll mncost = INT_MAX;
    rep(i,n){
        if (vis[i] || !isloop[i]) continue;
        loop.clear();
        assert(mnind == -1);
        assert(mncost == INT_MAX);
        handle_loop(i, a, cost, loop, mnind, mncost);
        reverse(all(loop));
        order.insert(order.end(), all(loop));
    }
}

void bfs(int node, const vector<vector<int>> &edges, vector<int> &order){
    deque<int> dq;
    dq.push_back(node);
    while(!dq.empty()){
        node = dq.front();
        dq.pop_front();
        order.push_back(node);
        assert(node < (int)edges.size());
        assert(node >= 0);
        for (const int &ngb : edges[node]){
            if (vis[ngb]) continue;
            vis[ngb] = true;
            dq.push_back(ngb);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> edges(n);
    rep(i,n){
        cin >> a[i]; a[i]--;
        assert(a[i] < (int)edges.size());
        assert(a[i] >= 0);
        edges[a[i]].push_back(i);
        vis[i] = false;
    }
    vector<ll> cost(n);
    rep(i,n) cin >> cost[i];
    vector<bool> isloop(n,false), start(n,false);
    debug(a);
    recog_loops(a, isloop, start);
    debug(isloop);
    vector<int> order, loop;
    handle_loops(n, a, cost, isloop, order, loop);
    rep(i,n){
        if(!start[i] || vis[i]) continue;
        bfs(i, edges, order);
    }
    reverse(all(order));
    debug(order);
    assert((int)order.size() == n);
    rep(i,n) cout << order[i]+1 << " \n"[i==(int)order.size()-1];
}