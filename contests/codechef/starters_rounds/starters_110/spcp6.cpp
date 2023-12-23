/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Nov 29 20:32:08 IST 2023
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
    const bool DEBUG = false;
#endif

using namespace std;

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
#define pass (void)0
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

const ll mod = 1e9+7;

#define alice 0
#define bob 1
vector<ll> dp(1e5+1,-1);
vector<vector<ll>> dp2(2,vector<ll>(1e5+1,-1));

ll process(ll l, ll player){
    if (dp2[player][l] != -1) return dp2[player][l];
    if (l == 1ll) return dp2[player][l] = 0ll;
    if (l == 2ll && player == alice) return dp2[player][l] = 2ll;
    else if (l == 2ll) return dp2[player][l] = 0ll;
    if (l == 3ll && player == alice) return dp2[player][l] = 1ll;
    else if (l == 3ll) return dp2[player][l] = 3ll;
    if (l == 4ll && player == alice) return dp2[player][l] = 6ll;
    else if (l == 4ll) return dp2[player][l] = 2ll;
    if (l == 5ll && player == alice) return dp2[player][l] = 5ll;
    else if (l == 5ll) return dp2[player][l] = 10ll;
    dp2[player][l] = (process(l-4ll,player) + process(l-3ll,player))%mod + process(l-2ll,player);
    dp2[player][l]%=mod;
    dp2[player][l] += (process(l-1ll,1ll-player));
    // dp2[player][l] = process(l-5ll,1ll-player) + process(l-4ll,1ll-player) + process(l-3ll, 1ll-player) + process(l-1ll, 1ll-player);
    dp2[player][l]%=mod;
    return dp2[player][l];
}

ll get_moves(ll l){
    if (l <= 3ll) return 0ll;
    if (l == 4ll) return 1ll;
    return process(l-4ll, alice);
}

void debug_print(ll l){
    if (!DEBUG) return;
    cout << "alice: ";
    rep(i,1ll,l,1ll) cout << dp2[alice][i] << space;
    cout << "\nbob: ";
    rep(i,1ll,l,1ll) cout << dp2[bob][i] << space;
    cout << endl;
}

void solve(){
    ll l; cin >> l;
    ll moves = get_moves(l) + get_moves(l+1ll) + get_moves(l+2ll) + get_moves(l+3ll);
    debug_print(l+3ll);
    debug(l, get_moves(l), get_moves(l+1ll), get_moves(l+2), get_moves(l+3));
    moves %= mod;
    cout << moves << endl;
    debug(endl);
}

/*


10
1
2
3
4
5
6
7
8
9
10

1
1
3
4
9




*/