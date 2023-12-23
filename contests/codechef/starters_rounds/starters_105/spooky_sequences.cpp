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

class DSU{
public:
    vector<int> parent,rank;
    DSU(int n):parent(n,-1),rank(n,0){}

    int find(int x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]){
            rank[px] = rank[py];
            parent[px] = py;
        }
        else if(rank[px] > rank[py]){
            rank[py] = rank[px];
            parent[py] = px;
        }
        else{
            rank[px] = ++rank[py];
            parent[px] = py;
        }
    }
};

const ll mod = 1e9+7;

ll inv(ll n){
    if (n <= 1ll) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void solve(){
    int n, m; cin >> n >> m;
    int u, v;
    DSU dsu(n);
    rep(i,m){
        cin >> u >> v; --u;--v;
        dsu.unite(u,v);
    }
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    unordered_map<int,vector<int>> umap;
    rep(i,n){
        umap[dsu.find(i)].push_back(a[i]);
    }
    ll ans = 1;
    // debug(a);
    vector<ll> lens;
    for(auto it : umap){
        vector<int> &vec = it.second;
        sort(all(vec));
        lens.push_back((ll)vec.size());
        debug(vec);
        ll cur = 1, seq = 1;
        rep(i,(int)vec.size()-1){
            if (vec[i] == vec[i+1]){
                seq++;
            }
            else{
                while(seq>1){
                    cur *= seq--;
                    cur %= mod;
                }
                seq = 1;
            }
        }
        while(seq>1){
            cur *= seq--;
            cur %= mod;
        }
        seq = 1;
        ans *= cur;
        ans %= mod;
    }
    ll temp = n;
    debug(ans,lens);
    while(temp>1){
        ans *= temp--;
        ans %= mod;
    }
    for (ll num : lens){
        while(num > 1){
            debug(num);
            debug(inv(num));
            ans *= inv(num--);
            ans %= mod;
        }
    }
    cout << ans << endl;
}