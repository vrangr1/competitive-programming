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
#define no "No\n"
void solve();

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}
const char a = 'A', b = 'B', c = 'C';

inline int get_ind(char ch){
    switch(ch){
        case a: return 0;
        case b: return 1;
        case c: return 2;
        case '.': return 4;
    }
}

const vector<char> chars = {a,b,c};

void increment(int &x, int &y, const int &n){
    if (y == n-1){
        x++;
        y = 0;
        return;
    }
    y++;
}

void decrement(int &x, int &y, const int &n){
    if (y == 0){
        x--;
        y=n-1;
        return;
    }
    y--;
}

inline bool check(int coord, const vector<bitset<3>> &vals){
    return vals[coord][0] && vals[coord][1] && vals[coord][2];
}

bool dfs(int x, int y, vector<bitset<3>> &rows, vector<bitset<3>> &cols, vector<string> &grid, const string &r, const string &c, const int &n, int &rsum, int &csum, const int &limit){
    if (csum == limit && rsum == limit) return true;
    if (csum == limit || rsum == limit) return false;
    if (x >= n || x < 0 || y >= n || y < 0) return false;
    assert(csum < limit && rsum < limit);
    assert(grid[x][y] == '.');
    if (rows[x][get_ind(r[x])] && cols[y][get_ind(c[y])]){
        for (auto &ch : chars){
            if(!rows[x][get_ind(ch)] && !cols[y][get_ind(ch)]){
                rows[x][get_ind(ch)] = true;
                cols[y][get_ind(ch)] = true;
                grid[x][y] = ch;
                if (check(x,rows)) rsum += x;
                else if (y == n-1){
                    rows[x][get_ind(ch)] = false;
                    cols[y][get_ind(ch)] = false;
                    grid[x][y] = '.';
                    return false;
                }
                if (check(y,cols)) csum += y;
                else if (x == n-1){
                    rows[x][get_ind(ch)] = false;
                    cols[y][get_ind(ch)] = false;
                    grid[x][y] = '.';
                    return false;
                }
                increment(x,y,n);
                if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
                decrement(x,y,n);
                grid[x][y] = '.';
                if (check(x,rows)) rsum -= x;
                if (check(y,cols)) csum -= y;
                rows[x][get_ind(ch)] = false;
                cols[y][get_ind(ch)] = false;
                grid[x][y] = '.';
            }
        }
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        return false;
    }
    if (!rows[x][get_ind(r[x])] && !cols[y][get_ind(c[y])] && r[x] != c[y]){
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        return false;
    }
    if (!rows[x][get_ind(r[x])] && !cols[y][get_ind(c[y])]){
        if (x >= n-2 || y >= n-2) return false;
        rows[x][get_ind(r[x])] = true;
        cols[y][get_ind(c[y])] = true;
        grid[x][y] = r[x];
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        rows[x][get_ind(r[x])] = false;
        cols[y][get_ind(c[y])] = false;
        grid[x][y] = '.';
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        return false;
    }
    if (!rows[x][get_ind(r[x])]){
        if(!cols[y][get_ind(r[x])]){
            if (y >= n-2) return false;
            rows[x][get_ind(r[x])] = true;
            cols[y][get_ind(r[x])] = true;
            grid[x][y] = r[x];
            if (check(y,cols)) csum += y;
            else if (x == n-1){
                rows[x][get_ind(r[x])] = false;
                cols[y][get_ind(r[x])] = false;
                grid[x][y] = '.';
                return false;
            }
            increment(x,y,n);
            if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
            decrement(x,y,n);
            if (check(y,cols)) csum -= y;
            rows[x][get_ind(r[x])] = false;
            cols[y][get_ind(r[x])] = false;
            grid[x][y] = '.';
        }
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        return false;
    }
    assert(!cols[y][get_ind(c[y])]);
    if(!rows[x][get_ind(c[y])]){
        if (x >= n-2) return false;
        rows[x][get_ind(c[y])] = true;
        cols[y][get_ind(c[y])] = true;
        grid[x][y] = c[y];
        if (check(x,rows)) rsum += x;
        else if (y == n-1){
            rows[x][get_ind(c[y])] = false;
            cols[y][get_ind(c[y])] = false;
            grid[x][y] = '.';
            return false;
        }
        increment(x,y,n);
        if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
        decrement(x,y,n);
        if (check(x,rows)) rsum -= x;
        rows[x][get_ind(c[y])] = false;
        cols[y][get_ind(c[y])] = false;
        grid[x][y] = '.';
    }
    increment(x,y,n);
    if (dfs(x,y,rows,cols,grid,r,c,n,rsum,csum,limit)) return true;
    decrement(x,y,n);
    return false;
}

void solve(){
    int n; cin >> n;
    string r, c; cin >> r >> c;
    bool fa = false, fb = false, fc = false;
    rep(i,n){
        if (r[i] == a) fa = true;
        else if (r[i] == b) fb = true;
        else fc = true;
    }
    if (!fa || !fb || !fc) return void(cout << no);
    fa = false; fb = false; fc = false;
    rep(i,n){
        if (c[i] == a) fa = true;
        else if (c[i] == b) fb = true;
        else fc = true;
    }
    if (!fa || !fb || !fc) return void(cout << no);
    vector<string> grid(n,string(n,'.'));
    vector<bitset<3>> rows(n), cols(n);
    rep(i,n){
        rows[i].reset();
        cols[i].reset();
    }
    int rsum = 0, csum = 0, limit = ((n-1)*n)/2;
    if (dfs(0,0,rows,cols,grid,r,c,n,rsum,csum,limit)){
        rep(i,n){
            rep(j,n){
                cout << grid[i][j];
                if (j < n-1) cout << " ";
                else cout << "\n";
            }
        }
    }
    else cout << no;
}

/*

*/