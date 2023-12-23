/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 17:56:20 IST 2023
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

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    sort(all(a));
    if (k%2ll == 0ll){
        ll w = 0ll;
        rep(i,0ll,k-1ll,2ll)
            w += a[i+1ll]-a[i];
        cout << w << endl;
        return;
    }
    if (k == 1ll) return void(cout << "0\n");
    vector<ll> left(k), right(k);
    left[0] = a[0];
    left[1] = a[1];
    right.back() = a.back();
    right[k-2ll] = a[k-2ll];
    rep(i,2ll,k-1ll,1ll)
        left[i] = left[i-2ll]+a[i];
    rep(i,k-3ll,0ll,-1ll)
        right[i] = right[i+2ll]+a[i];
    ll mw = min(right[2ll]-right[1ll], left[k-2ll] - left[k-3ll]);
    rep(i,1ll,k-2ll,1ll){
        if (i%2ll){
            ll w = left[i] - left[i-1ll] - a[i] + a[i+1ll];
            if (i == k-2ll){
                mw = min(mw,w);
                continue;
            }
            w += right[i+3ll]-right[i+2ll];
            mw = min(mw,w);
        }
        else
            mw = min(mw, left[i-1ll]-left[i-2ll] + right[i+2ll]-right[i+1ll]);
    }
    cout << mw << endl;
}