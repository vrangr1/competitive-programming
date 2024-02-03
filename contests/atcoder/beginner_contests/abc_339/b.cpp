/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Feb  3 17:33:06 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
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
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<"\n";}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

#define white '.'
#define black '#'
#define up 0
#define right 1
#define down 2
#define left 3
#define cwise 0
#define ccwise 1

const vector<vector<int>> dirx = {{0,1,0,-1},{0,-1,0,1}};
const vector<vector<int>> diry = {{1,0,-1,0},{-1,0,1,0}};
const vector<vector<int>> dirupd = {{right,down,left,up},{left,up,right,down}};

void solve(){
    int h, w, n; cin >> h >> w >> n;
    vector<string> grid(h,string(w,white));
    auto valid = [&](int x, int y) -> bool {
        return (x <= h && x >= 1 && y <= w && y >= 1);
    };
    int x = 1, y = 1, dir = up;
    rep(_,n){
        if (grid[x-1][y-1] == white){
            grid[x-1][y-1] = black;
            x = ((x-1 + dirx[cwise][dir]+h)%h)+1;
            y = ((y-1 + diry[cwise][dir]+w)%w)+1;
            assert(valid(x,y));
            dir = dirupd[cwise][dir];
        }
        else{
            grid[x-1][y-1] = white;
            x = ((x-1 + dirx[ccwise][dir]+h)%h)+1;
            y = ((y-1 + diry[ccwise][dir]+w)%w)+1;
            assert(valid(x,y));
            dir = dirupd[ccwise][dir];
        }
    }
    print_vec(grid);
}