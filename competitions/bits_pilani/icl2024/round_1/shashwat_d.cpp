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
* AUTHOR : Shashwat Agrawal
* Nick : shashuiitk
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

#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
// #define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
// #define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
// #define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; ((st<=end or d>0)?i<=end:i>=end); i+=d)
#define pass (void)0
#define space " "
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = (ll)1e9+7ll;

void solve(){
    int n;
    cin>>n;
    vector<ll> p(n);
    forn(i,n) {
        cin>>p[i];
    }
    vector<vector<int>> adj(n);
    forn(i,n-1) {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    auto min_depth_root = [&](){
        vector<bool> visited(n,false);
        queue<int> q;
        forn(i,n) {
            if (adj[i].size()==1) {
                q.push(i);
                visited[i] = true;
            }
        }
        int root = -1;
        while(q.size()>1) {
            queue<int> new_q;
            while(q.size()) {
                int cur = q.front();
                q.pop();
                for(auto v:adj[cur]) {
                    if (!visited[v]) {
                        new_q.push(v);
                        visited[v] = true;
                    }
                }
            }
            q = new_q;
            if (new_q.size() and new_q.size()<=2) {
                root = new_q.front();
                new_q.pop();
                if (new_q.size() and new_q.front() < root) {
                    root = new_q.front();
                }
            }
        }
        return root;
    };
    int root = min_depth_root();
    auto find_cost = [&](int root) -> ll {
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(root);
        visited[root] = true;
        ll cost = 0;
        ll t = 0ll;
        while(!q.empty()) {
            ++t;
            queue<int> new_q;
            while(!q.empty()) {
                int i = q.front();
                q.pop();
                for(auto v:adj[i]) {
                    if (visited[v]==false) {
                        cost = (cost + t*p[v])%mod;
                        visited[v] = true;
                        for(auto j:adj[v]) {
                            if (visited[j]==false) {
                                cost = (cost + t*p[j])%mod;
                                new_q.push(j);
                                visited[j] = true;
                            }
                        }
                    }
                }
            }
            q = new_q;
        }
        return cost;
    };
    cout<<find_cost(root)<<endl;
}

int main(){
	fastIO;
	TEST1;
	return 0;
}