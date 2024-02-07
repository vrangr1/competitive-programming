/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Feb  7 20:46:20 IST 2024
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, k; cin >> n >> k;
    if (n == 1ll){
        if (k) return void(cout << "-1\n");
        cout << "1\n";
        return;
    }
    const ll low = ((n-1ll)*n)/2ll, high = (n-1ll)*(n-1ll);
    if (k < low || k > high) return void(cout << "-1\n");
    if (k == low){
        rep(i,1,n,1)
            cout << i << " \n"[i==n];
        return;
    }
    if (k == high){
        cout << "1 " << n;
        rep(i,2,n-1ll,1){
            cout << " " << i;
        }
        cout << endl;
        return;
    }
    vector<ll> p(n);
    p[0] = 1ll;
    ll diff = high - k;
    if (diff <= n-2ll){
        p[1] = n-1ll;
        p[diff+1ll] = n;
        ll cur = 2ll;
        rep(i,2ll,diff,1ll)
            p[i] = cur++;
        rep(i,diff+2ll,n-1ll,1ll)
            p[i] = cur++;
        assert(cur == n-1ll);
        print_vec(p);
        return;
    }
    ll prev = n-2ll, dec = 2ll, l = n-1ll, lval = n;
    while(diff > prev){
        diff -= prev;
        prev--;
        dec++;
        p[l] = lval;
        lval--;
        l--;
    }
    assert(diff >= 0ll && diff <= prev && dec < n);
    if (diff == 0ll){
        p[1] = lval;
        ll cur = 2ll;
        rep(i,2ll,l,1ll)
            p[i] = cur++;
        assert(cur == lval);
        print_vec(p);
        return;
    }
    p[1] = lval-1ll;
    p[diff+1ll] = lval;
    ll cur = 2ll;
    rep(i,2ll,diff,1ll)
        p[i] = cur++;
    rep(i,diff+2ll,l,1ll)
        p[i] = cur++;
    assert(cur == lval-1ll);
    print_vec(p);
}