/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 17:33:24 IST 2024
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
#define yes "Yes\n"
#define no "No\n"
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
    ll n, a, b; cin >> n >> a >> b;
    ll lh = 1, hh = a, lw = a+1, hw = a+b;
    bool hol = true, work = true;
    ll w = a+b;
    rep(i,n){
        ll d; cin >> d;
        if (d >= a+b){
            d%=w;
        }
        if (d < a){
            if (hol){
                hh = min(hh,a-d);
                hol = lh <= hh;
            }
            if (work){
                lw = max(lw, a+b-d+1);
                work = lw <= hw;
            }
            continue;
        }
        else if (d < a+b){
            ll low = a+b+1ll-d;
            ll high = min(2ll*a + b - d,a+b);
            if (low >= a) hol = false;
            else if (hol) {
                lh = max(low, lh);
                hh = min(high,hh);
                hol = lh <= hh;
            }
            if (high < a) work = false;
            else if (work){
                hw = min(hw,high);
                lw = max(lw,low);
                work = lw <= hw;
            }
        }
        else assert(false);
    }
    if (hol || work) cout << yes;
    else cout << no;
}