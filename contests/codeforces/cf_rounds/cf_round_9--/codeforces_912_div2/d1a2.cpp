/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  2 10:10:18 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll m = 63;
    // assert(m <= 21);
    vector<ll> b(n), c(n);
    rep(i,n) c[i] = a[i];
    while(q--){
        ll k; cin >> k;
        ll sol = 0;
        rep(bit, m-1ll, 0ll, -1ll){
            i128 val = (1ll<<bit);
            i128 cost = 0ll;
            i128 temp = val-1ll;
            rep(i,n){
                if (a[i]&val){
                    b[i] = a[i];
                    continue;
                }
                cost += val - (a[i]&temp);
                b[i] = a[i] + val - (a[i]&temp);
            }
            if (cost <= k){
                sol += val;
                swap(b,a);
                k-=cost;
            }
        }
        cout << sol << endl;
        if (q != 0ll)
            rep(i,n) a[i] = c[i];
    }
}