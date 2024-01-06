/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan  6 17:44:51 IST 2024
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
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
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

const string dot = ".";
#define up 1
#define right 2
#define down 3
#define left 4

void solve(){
    int n; cin >> n;
    vector<vector<string>> grid(n,vector<string>(n,dot));
    grid[n/2][n/2] = "T";
    int x = 1, t = n*n;
    int i = 0, j = 0;
    int dir = right;
    auto valid = [&n](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < n && y < n;
    };
    while(x<t){
        // debug(i,j,endl);
        assert(grid[i][j] == dot);
        grid[i][j] = to_string(x++);
        switch(dir){
            case right:
                if (valid(i,j+1) && grid[i][j+1] == dot){
                    j++;
                    break;
                }
                dir = down;
            case down:
                if (valid(i+1,j) && grid[i+1][j] == dot){
                    i++;
                    break;
                }
                dir = left;
            case left:
                if (valid(i,j-1) && grid[i][j-1] == dot){
                    j--;
                    break;
                }
                dir = up;
            case up:
                if (valid(i-1,j) && grid[i-1][j] == dot){
                    i--;
                    break;
                }
                dir = right;
                assert((x>=t) || (valid(i,j+1) && grid[i][j+1] == dot));
                j++;
        }
    }
    rep(k,n) print_vec(grid[k]);
}