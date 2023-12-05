/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec  5 20:59:10 IST 2023
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

// vector<ll> dp(1e7+1ll,-1);

// ll get_triplets(ll n){
//     assert(n < sz(dp));
//     if (dp[n] != -1) return dp[n];
//     if (n <= 2ll) return dp[n] = 0ll;
//     if (n == 3ll) return dp[n] = 1ll;

// }

ll pr(ll a, ll n){
    if (n == 0ll) return 1ll;
    if (n == 1ll) return a;
    if (n%2ll)
        return a*pr(a*a,n/2ll);
    return pr(a*a,n/2ll);
}

ll get_ct(ll d){
    switch(d){
        case 0: return 1ll;
        case 1: return 3ll;
        case 2: return 6;
        case 3: return 10;
        case 4: return 15;
        case 5: return 21;
        case 6: return 28;
        case 7: return 36;
        case 8: return 45;
        case 9: return 55;
    }
    return 1;
}

void solve(){
    ll n; cin >> n;
    if (n == 0ll) return void(cout << "1\n");
    ll sol = 1ll;
    while(n > 0ll){
        ll d = n%10ll;
        n/=10ll;
        sol *= get_ct(d);
    }
    cout << sol << endl;
}