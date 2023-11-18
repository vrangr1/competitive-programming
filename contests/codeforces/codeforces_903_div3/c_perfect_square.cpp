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

void solve1(){
    int n; cin >> n;
    vector<string> sq(n);
    rep(i,n) cin >> sq[i];
    int ops = 0;
    char sol;
    rep(i,n){
        rep(j,n){
            if (sq[i][j] == sq[n-j-1][i])
                continue;
            sol = max(sq[i][j], sq[n-j-1][i]);
            if (n-1-i < n && n-1-i >= 0){
                sol = max(sol,sq[j][n-1-i]);
                ops += (int)(sol-sq[j][n-1-i]);
                sq[j][n-1-i] = sol;
            }
            ops += (int)(sol-sq[i][j]);
            sq[i][j] = sol;
            ops += (int)(sol-sq[n-j-1][i]);
            sq[n-j-1][i] = sol;
        }
    }
    cout << ops << endl;
}

vector<vector<bool>> vis(1e3,vector<bool>(1e3));//, path(1e3,vector<bool>(1e3));
unordered_set<int> path;

inline int get_hash(int x, int y){
    return x*1e4+y;
}

char dfs(int x, int y, char maxch, int &ops, vector<string> &sq, const int n);

char handle_child(int x, int y, char maxch, int &ops, vector<string> &sq, const int n){
    if (x < 0 || x >= n || y < 0 || y >= n) return maxch;
    if (!vis[x][y])
        return max(maxch, dfs(x,y,maxch,ops,sq,n));
    // assert(path[x][y]);
    assert(path.find(get_hash(x,y)) != path.end());
    return maxch;
}

char dfs(int x, int y, char maxch, int &ops, vector<string> &sq, const int n){
    vis[x][y] = true;
    // path[x][y] = true;
    path.insert(get_hash(x,y));
    maxch = max(maxch,sq[x][y]);
    maxch = handle_child(n-y-1,x,maxch,ops,sq,n);
    maxch = handle_child(y,n-1-x,maxch,ops,sq,n);
    ops += (int)(maxch-sq[x][y]);
    sq[x][y] = maxch;
    return maxch;
}

void solve(){
    int n; cin >> n;
    vector<string> sq(n);
    rep(i,n){
        cin >> sq[i];
        fill(vis[i].begin(), vis[i].begin() + n, false);
        // fill(path[i].begin(), path[i].begin() + n, false);
    }
    int ops = 0;
    rep(i,n){
        rep(j,n){
            if (vis[i][j]) continue;
            path.clear();
            dfs(i,j,sq[i][j],ops,sq,n);
        }
    }
    cout << ops << endl;
}


/*
bbaa
abba
aaba
abba

*/