/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Mar 26 20:08:09 IST 2024
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
    ll n,k; cin >> n >> k;
    vector<ll> a(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> c[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order), [&](const ll &i, const ll &j){
        return a[i] < a[j];
    });
    map<ll,ll> mp, cur;
    vector<ll> ne(n);
    debug(order);
    ne.back() = 0;
    mp[c[order[n-1]]]++;
    for(ll i = n-2ll; i >= 0; --i){
        ne[i] = (n-i-1-mp[c[order[i]]]);
        mp[c[order[i]]]++;
        assert(ne[i] >= 0ll);
    }
    debug(ne);
    ll sol = LLONG_MAX;
    rep(i,n){
        if (i-cur[c[order[i]]] > k) break;
        ll rem = k-(i-cur[c[order[i]]]);
        // debug(i,sol,rem,(ne[i]-rem));
        assert(rem>=0ll);
        sol = min(sol,max(ne[i]-rem,0ll));
        cur[c[order[i]]]++;
        mp[c[order[i]]]--;
    }
    cout << sol << endl;
}


/*
2

2 1
2 4
1 2

1
5 1
1 2 3 5 4
1 2 3 4 1



*/