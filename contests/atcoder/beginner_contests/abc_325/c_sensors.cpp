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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

inline int get_hash(int x, int y){
    return 1e4*x+y;
}

class DSU{
public:
    vector<int> parent, rank;
    int ct;
    DSU(int h, int w, int ct):parent(get_hash(h,w)+1,-1),rank(get_hash(h,w)+1,0){
        this->ct = ct;
    }

    int find(int x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int px = find(x), py = find(y);
        if (px == py) return;
        ct--;
        if (rank[px] < rank[py]){
            parent[px] = py;
            rank[px] = rank[py];
        }
        else if (rank[py] < rank[px]){
            parent[py] = px;
            rank[py] = rank[px];
        }
        else{
            parent[px] = py;
            rank[px] = ++rank[py];
        }
    }
};

const vector<int> dx = {-1,-1,-1,0,0,1,1,1};
const vector<int> dy = {-1,0,1,-1,1,-1,0,1};

inline bool is_valid(int x, int y, int h, int w){
    return x >= 0 && x < h && y >= 0 && y < w;
}

void solve(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    int ct = 0;
    rep(i,h){
        cin >> s[i];
        ct += count(all(s[i]),'#');
    }
    DSU dsu(h,w,ct);
    rep(i,h){
        rep(j,w){
            if (s[i][j] != '#') continue;
            rep(k,8){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(!is_valid(nx,ny,h,w) || s[nx][ny] != '#') continue;
                dsu.unite(get_hash(i,j),get_hash(nx,ny));
            }
        }
    }
    cout << dsu.ct << endl;
}