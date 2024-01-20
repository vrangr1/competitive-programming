/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 20 21:10:58 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = (ll)1e9+7ll;

#define blocked '#'
#define empty '.'
#define ocell 'o'

const vector<int> dir1x = {-1,0,1,0};
const vector<int> dir1y = {0,1,0,-1};
const vector<int> dir2x = {0,1,0,-1};
const vector<int> dir2y = {1,0,-1,0};


void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    rep(i,n) cin >> grid[i];
    // vector<pair<int,int>> cells;
    ll sol = 1;
    auto valid = [n,m](int x, int y) -> bool {
        return (x >= 0 && x < n && y < m && y >= 0);
    };
    vector<vector<ll>> cts(n,vector<ll>(m,0ll));
    rep(i,n){
        rep(j,m){
            if (grid[i][j] != ocell) continue;
            ll ct = 0ll;
            rep(dir,4){
                if (!valid(i+dir1x[dir],j+dir1y[dir]) || !valid(i+dir2x[dir],j+dir2y[dir])) continue;
                if (grid[i+dir1x[dir]][j+dir1y[dir]] != empty) continue;
                if (grid[i+dir2x[dir]][j+dir2y[dir]] != empty) continue;
                ct++;
            }
            cts[i][j] = ct;
            sol *= ct;
            sol %= mod;
        }
    }
    // auto inv = [](auto &&self, ll n) -> ll {
    //     if (n <= 1ll) return 1ll;
    //     return ((mod-mod/n)*self(self,mod%n))%mod;
    // };
    // rep(i,n){
    //     rep(j,m){
    //         if (grid[i][j] != ocell) continue;
    //         ll ct = 0ll;
    //         rep(dir,4){
    //             if (!valid(i+dir1x[dir],j+dir1y[dir]) || !valid(i+dir2x[dir],j+dir2y[dir])) continue;
    //             if (grid[i+dir1x[dir]][j+dir1y[dir]] == blocked) continue;
    //             if (grid[i+dir2x[dir]][j+dir2y[dir]] == blocked) continue;
    //             if ((grid[i+dir1x[dir]][j+dir1y[dir]] == empty) && 
    //                 (grid[i+dir2x[dir]][j+dir2y[dir]] == empty)) continue;
                
    //         }
    //         cts[i][j] = ct;
    //         sol *= ct;
    //         sol %= mod;
    //     }
    // }
    cout << sol << endl;
}

/*

5

1
4 5
###.o
.o...
#..o.
#..##


5 5
..###
.o..#
.o.o.
..#o.
###..
8 31
.########.#..oo..o..o#o..o....o
o.######.o#o...o..o..#..o..oo..
o..####.o.#####..########o..###
..o.o..o..#####.o########..o###
.o##..##.o#####o.########..o###
o.##.o##.o#####..########o..###
..######..#..o..o.o..####..o###
.o######o.#o..o..o..o####o..###
2 3
#.o
.o.
2 2
..
..

*/