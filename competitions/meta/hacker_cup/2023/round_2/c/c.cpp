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
void solve(int T);

int main(){
	fastIO;
	int T;cin>>T;
    rep(t,T)solve(t+1);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(int T){
    cout << "Case #" << T << ": ";
    ll n; cin >> n;
    vector<ll> parent(n);
    parent[0] = -1;
    vector<vector<ll>> edges(n);
    rep(i,n-1){
        cin >> parent[i];
        parent[i]--;
        edges[parent[i]].push_back(i+1);
    }
    vector<set<string>> topics(n);
    set<string> ctopics;
    string cur;
    rep(i,n){
        int m; cin >> m;
        rep(j,m){
            cin >> cur;
            topics[i].insert(cur);
        }
    }
    debug(edges);
    deque<ll> q;
    q.push_back(0ll);
    vector<bool> vis(n,false);
    while(q.size()){
        int node = q.front();
        vis[node] = true;
        q.pop_front();
        if (edges[node].size() == 0) continue;
        for (int child : edges[node]){
            if (vis[child]) continue;
            ctopics = topics[node];
            if (topics[node].size() == 0) break;
            for (string topic : topics[node]){
                if (topics[child].find(topic) == topics[child].end()){
                    topics[child].insert(topic);
                    ctopics.erase(topic);
                }
            }
            topics[node] = ctopics;
            q.push_back(child);
        }
    }
    vector<string> soln;
    vector<string> temp;
    bool start = false;
    rep(i,n){
        if (edges[i].size() == 0){
            if (!start){
                soln = vector<string>(all(topics[i]));
                start = true;
                continue;
            }
            debug(topics[i]);
            set_intersection(all(topics[i]),all(soln),back_inserter(temp));
            swap(temp,soln);
            temp.clear();
        }
    }
    debug(soln);
    cout << soln.size() << endl;
}