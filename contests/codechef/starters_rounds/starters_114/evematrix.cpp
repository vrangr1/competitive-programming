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

bool doassert(int n, const vector<vector<int>> &grid){
    rep(d,1,n-1,1){
        int sum = 0;
        rep(i,d)
            sum += grid[i][0];
        rep(j,d)
            sum += grid[d][j];
        rep(i,d,1,-1)
            sum += grid[i][d];
        rep(j,d,1,-1)
            sum += grid[0][j];
        if (sum%2 == 0) return false;
        // assert(sum%2 == 1);
    }
    return true;
}

void process(int n){
    vector<vector<int>> grid(n,vector<int>(n));
    int o = 1, e = 2, n2 = n*n;
    grid[0][0] = o;
    o+=2;
    int rem, ensp;
    auto get_val = [&](bool set = false, int par = 0) -> int {
        rem--;
        if (set){
            if (par){
                assert(o <= n2);
                o += 2;
                return o-2;
            }
            assert(e <= n2);
            e += 2;
            return e-2;
        }
        if (ensp){
            if (rem == 0 || e > n2){
                assert(o<=n2);
                o+=2;
                return o-2;
            }
            assert(e<=n2);
            e+=2;
            return e-2;
        }
        if (rem == 0 || o > n2){
            assert(e <= n2);
            e+=2;
            return e-2;
        }
        assert(o<=n2);
        o+=2;
        return o-2;
    };
    // debug(n2);
    rep(d,1,n-1,1){
        rem = 2*d+1;
        if (d%2){
            grid[0][d] = get_val(true,1);
            grid[d][0] = get_val(true,0);
            ensp = 1;
        }
        else{
            grid[0][d] = get_val(true,0);
            grid[d][0] = get_val(true,1);
            ensp = 0;
        }
        // debug(d,rem,o,e,ensp);
        rep(j,1,d,1)
            grid[d][j] = get_val();
        rep(i,1,d-1,1)
            grid[i][d] = get_val();
        // debug(grid[d][d],endl);
    }
    if (!doassert(n,grid)) return void(cout << "-1\n");
    rep(i,n) print_vec(grid[i]);
}

void solve(){
    int n; cin >> n;
    if (n == 2) return void(cout << "-1\n");
    else if (n%2 == 0) return void(process(n));
    if (n == 1) return void(cout << "1\n");
    int n2 = n*n;
    int e = 2, o = 1;
    vector<vector<int>> grid(n,vector<int>(n,-1));
    grid[0][0] = o;
    o+=2;
    int rem;
    auto get_val = [&]() -> int {
        debug(rem);
        if (rem > 1 && o <= n2){
            o += 2;
            rem--;
            return o-2;
        }
        e += 2;
        rem--;
        return e-2;
    };

    rep(d,1,n-1,1){
        rem = (2*(d+1))-1;
        debug(d,o,e);
        grid[d][0] = get_val();
        grid[0][d] = get_val();
        rep(j,1,d-1,1)
            grid[d][j] = get_val();
        rep(i,1,d-1,1)
            grid[i][d] = get_val();
        grid[d][d] = get_val();
        debug(grid);
    }
    doassert(n,grid);
    rep(i,n)
        print_vec(grid[i]);
}