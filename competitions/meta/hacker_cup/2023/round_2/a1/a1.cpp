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

const vector<ll> dx = {-1, 0, 0, 1};
const vector<ll> dy = {0, -1, 1, 0};

inline ll get_hash(ll x, ll y){
    return x*1e4+y;
}

class DSU{
public:
    vector<ll> parent, rank;
    DSU(ll r, ll c):parent(get_hash(r,c)+1,-1),rank(get_hash(r,c)+1,1ll){}

    ll find(ll x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(ll x, ll y){
        ll px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]){
            rank[px] = rank[py];
            parent[px] = py;
        }
        else if (rank[px] > rank[py]){
            rank[py] = rank[px];
            parent[py] = px;
        }
        else{
            rank[px] = ++rank[py];
            parent[px] = py;
        }
    }
};

inline bool is_valid(ll x, ll y, ll r, ll c){
    return x >= 0ll && x < r && y >= 0ll && y < c;
}

#define black 'B'
#define white 'W'
#define dot '.'

void solve(int T){
    cout << "Case #" << T << ": ";
    ll r, c; cin >> r >> c;
    vector<string> board(r);
    rep(i,r) cin >> board[i];
    DSU dsu(r,c);
    rep(i,r){
        rep(j,c){
            if (board[i][j] != white) continue;
            rep(k,4){
                ll nx = i + dx[k];
                ll ny = j + dy[k];
                if (!is_valid(nx,ny,r,c) || board[nx][ny] != white) continue;
                dsu.unite(get_hash(i,j),get_hash(nx,ny));
            }
        }
    }
    unordered_map<ll,unordered_set<ll>> umap;
    rep(i,r){
        rep(j,c){
            if (board[i][j] != white) continue;
            rep(k,4){
                ll nx = i + dx[k];
                ll ny = j + dy[k];
                if (!is_valid(nx,ny,r,c)) continue;
                if (board[nx][ny] != dot) continue;
                umap[dsu.find(get_hash(i,j))].insert(get_hash(nx,ny));
            }
        }
    }
    for(auto e : umap){
        if (e.second.size() == 1) return void(cout << yes);
    }
    cout << no;
}