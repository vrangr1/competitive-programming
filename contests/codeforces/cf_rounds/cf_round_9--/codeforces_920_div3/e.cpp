/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jan 15 20:32:46 IST 2024
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

#define alice "Alice\n"
#define bob "Bob\n"
#define draw "Draw\n"

void solve(){
    ll h,w,ax,ay,bx,by; cin >> h >> w >> ax >> ay >> bx >> by;
    if (ax >= bx) return void(cout << draw);
    if ((bx-ax)%2ll){
        ll m = (bx-ax)/2ll;
        if (ay < by){
            by = min(by+m,w);
            ay = min(ay+m,w);
            if (abs(ay-by) <= 1ll) return void(cout << alice);
            return void(cout << draw);
        }
        by = max(by-m,1ll);
        ay = max(ay-m,1ll);
        if (abs(ay-by) <= 1ll) return void(cout << alice);
        return void(cout << draw);
    }
    ll m = (bx-ax)/2ll;
    if (ay < by){
        ay = max(ay-m,1ll);
        by = max(by-m,1ll);
        if (ay == by) return void(cout << bob);
        return void(cout << draw);
    }
    by = min(by+m,w);
    ay = min(ay+m,w);
    if (ay == by) return void(cout << bob);
    return void(cout << draw);
}