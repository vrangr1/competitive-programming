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

unordered_map<ll,ll> cts;
vector<ll> sizes(1e6+1);
// unordered_set<ll> vis;
bitset<(int)(1e6+1)> vis;
unordered_map<ll, unordered_set<ll>> edges;
vector<ll> parent(1e6+1);

void add_edges(ll n){
    ll rt = sqrt(n);
    repll(i,1ll,rt,1ll){
        if (n%i != 0ll) continue;
        // if (cts[n/i] == 0ll && cts[i] == 0ll) continue;
        if (cts.find(n/i) == cts.end() && cts.find(i) == cts.end()) continue;
        if (cts[n/i]){
            edges[n/i].insert(n);
            parent[n] = n/i;
        }
        if (cts[i]){
            edges[i].insert(n);
            parent[n] = i;
        }
    }
}

void dfs(ll node){
    // vis.insert(node);
    vis[node] = true;
    sizes[node] = cts[node];
    for (ll ngb : edges[node]){
        if (vis[ngb]){
            assert(sizes[ngb] != 0);
            sizes[node] += sizes[ngb];
            continue;
        }
        dfs(ngb);
        sizes[node] += sizes[ngb];
    }
}

inline ll nc2(ll n){
    if (n <= 1ll) return 0ll;
    return (n*(n-1ll))/2ll;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    ll mx = LLONG_MIN;
    ll ct = 0ll;
    cts.clear();
    sizes.clear();
    // vis.clear();
    edges.clear();
    rep(i,n){
        cin >> a[i];
        mx = max(mx,a[i]);
        cts[a[i]]++;
        sizes[a[i]] = 0;
        vis[a[i]] = false;
        parent[a[i]] = -1;
    }
    // fill(parent.begin(), parent.begin() + mx + 1, -1);
    rep(i,n)
        add_edges(a[i]);
    for (auto it : cts){
        if (vis[it.first]) continue;
        if (parent[it.first] != -1) continue;
        dfs(it.first);
        ct += nc2(sizes[it.first]-cts[it.first]);
        ct += (sizes[it.first]-cts[it.first])*(cts[it.first]);
        ct += nc2(cts[it.first]);
    }
    for (auto it : cts){
        assert(vis[it.first]);
    }
    // debug(dp);
    cout << ((n*(n+1ll))/2ll)-ct << endl;
}