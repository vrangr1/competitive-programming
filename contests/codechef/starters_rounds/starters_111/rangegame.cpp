/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec  6 21:45:01 IST 2023
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

ll pr(ll a, ll n){
    if (n == 0ll) return 1ll;
    if (n%2ll) return a*pr(a*a,n/2ll);
    return pr(a*a,n/2ll);
}

void solve(){
    ll l, r, p; cin >> l >> r >> p;
    ll temp = r, ct = -1;
    while(temp > 0){
        temp/=p;
        ct++;
    }
    temp = pr(p,ct);
    if (ct == 0ll) return void(cout << "Second\n");
    ct = (r/temp) - ((l-1ll)/temp);
    debug(temp,ct);
    if (ct%2ll) return void(cout << "First\n");
    cout << "Second\n";
}

/*

207 273 5
210 215 220 225 230 235 240 245 250 255 260 265 270
42 43 44 45 46 47 48 49 50 51 52 53 54
1 1 1 2 1 1 1 1 3 1 1 1 1
11 x 1
1 x 2
1 x 3

11 x 1
2 x 2

12 x 1
// 2 x 1
*/