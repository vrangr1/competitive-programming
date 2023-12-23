/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 20:10:09 IST 2023
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

void asserting(vector<ll> &a, ll val){
    set<ll> st;
    rep(i,sz(a))
        st.insert(a[i]%val);
    debug(a,val,st);
    assert(sz(st) == 2ll);
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(bit,1ll,63ll,1ll){
        ll val = 1ll<<bit;
        set<ll> st;
        rep(i,n) st.insert(a[i]%val);
        assert(sz(st) <= 2);
        if (sz(st) == 2) return void(cout << val << endl);
    }
}

void solve1(){
    int n; cin >> n;
    vector<ll> a(n);
    ll val;
    rep(i,n){
        cin >> a[i];
        if (i == 0) val = a[i];
        else val = gcd(val,a[i]);
    }
    vector<ll> cp = a;
    rep(i,n) a[i]/=val;
    debug(a,val);
    bool even = false, odd = false;
    rep(i,n){
        if (a[i]%2ll) odd = true;
        else even = true;
    }
    val*=2ll;
    if (odd && even){
        cout << val << endl;
        asserting(cp,val);
        return;
    }
    assert(odd && !even);
    val*=2ll;
    asserting(cp,val);
    cout << val << endl;
}

/*

5
1
4
8 15 22 30
5
60 90 98 120 308
6
328 769 541 986 215 734
5
1000 2000 7000 11000 16000
2
2 1


*/