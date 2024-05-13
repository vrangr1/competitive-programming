/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Apr 14 20:34:01 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int x, y; cin >> x >> y;
    if (x > 36 || y == 0) return void(cout << "0\n");
    vector<vector<vector<int>>> dp(7,vector<vector<int>>(101,vector<int>(11,-1)));
    auto get = [&dp](auto &&self, int b, int x, int y) -> int {
        if (x <= 0) return 1;
        assert(x>0);
        if (b == 0) return 0;
        if (x > 6*b || y == 0) return 0;
        if (dp[b][x][y] != -1) return dp[b][x][y];
        int sol = self(self,b-1,x-1,y);
        sol += self(self,b-1,x-2,y);
        sol += self(self,b-1,x-3,y);
        sol += self(self,b-1,x-4,y);
        sol += self(self,b-1,x-6,y);
        sol += self(self,b-1,x,y-1);
        sol += self(self,b-1,x,y);
        return dp[b][x][y] = sol;
    };
    cout << get(get,6,x,y) << endl;
}