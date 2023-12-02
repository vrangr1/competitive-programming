/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  2 18:03:50 IST 2023
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

ll ubound(ll low, ll high, ll val, const vector<ll> &a, const vector<ll> &order, const vector<ll> &psum){
    if (val == 2 && low == high) debug('s',low,psum,endl);
    if (low == high) return psum[high];
    assert(low < high);
    assert(a[order[high]] > val);
    ll mid = (low+high)/2ll;
    if (val == 2ll) debug(low,high,mid,a[order[mid]],endl);
    if (a[order[mid]] > val)
        return ubound(low, mid, val, a, order, psum);
    return ubound(mid+1ll, high, val, a, order, psum);
}

void dprint(vector<ll> a){
    sort(all(a));
    debug(a);
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    stable_sort(all(order),[&](const ll &i, const ll &j){
        return a[i] < a[j];
    });
    vector<ll> psum(n);
    psum.back() = a[order.back()];
    rep(i,n-2ll,0ll,-1ll)
        psum[i] = psum[i+1ll] + a[order[i]];
    vector<ll> sol(n);
    dprint(a);
    debug(order,psum);
    rep(i,n){
        ll val = a[order[i]];
        if (val == a[order.back()]){
            sol[order[i]] = 0ll;
            continue;
        }
        assert(val < a[order.back()]);
        if (val == 2) debug(order[i]);
        sol[order[i]] = ubound(0,n-1ll, val, a, order, psum);
    }
    print_vec(sol);
}