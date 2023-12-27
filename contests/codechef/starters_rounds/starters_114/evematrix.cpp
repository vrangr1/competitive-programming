/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 27 20:23:12 IST 2023
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n; cin >> n;
    if (n%2 == 0) return void(cout << "-1\n");
    int n2 = n*n;
    int e = 2, o = 1;
    vector<vector<int>> grid(n,vector<int>(n));
    grid[0][0] = 1;
    o+=2;
    auto orem = [&](){
        return (n2-o+1)/2;
    };
    auto erem = [&]()->int {
        return (n2-e+1)/2;
    };
    int lex=-1,ley=-1,lox=-1,loy=-1, ex,ey,ox,oy;
    int oc = 0;
    auto get_val = [&](){
        if (e <= n2){
            e += 2;
            return e-2;
        }
        o+=2;
        oc++;
        return o-2;
    };
    auto update = [&](int x, int y){
        if (grid[x][y]%2){
            ox = x;
            oy = y;
        }
        else{
            ex = x;
            ey = y;
        }
    };
    bool first = false;
    rep(d,1,n-1,1){
        oc = 0;
        rep(j,d){
            grid[d][j] = get_val();
            update(d,j);
        }
        grid[d][d] = get_val();
        update(d,d);
        rep(i,d-1,0,-1){
            grid[i][d] = get_val();
            update(i,d);
        }
        if (oc%2){
            first = !first;
            if (first)
                swap(grid[ox][oy],grid[lex][ley]);
        }
        
    }
}