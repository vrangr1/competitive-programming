/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Apr 29 20:31:51 IST 2024
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

void solve1(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    if (k == 0ll){
        ll sol = 0ll;
        rep(i,n) sol += max(b[i]-a[i],0ll);
        cout << sol << endl;
        return;
    }
    vector<ll> order(n);
    iota(all(order),0ll);
    stable_sort(all(order),[&](const ll &i, const ll &j) {
        return b[i]-a[i] < b[j]-a[j];
    });
    debug(order);
    vector<ll> loss(n,-1ll), profit(n,0);
    set<ll> vals;
    ll sum = 0ll;
    rep(i,k){
        ll ind = order[n-i-1ll];
        sum += a[ind];
        vals.insert(a[ind]);
    }
    loss[n-k] = sum;
    rep(i,n-k-1ll,0ll,-1ll){
        ll ind = order[i];
        sum += a[ind];
        vals.insert(a[ind]);
        sum -= *vals.rbegin();
        vals.erase(prev(vals.end()));
        loss[i] = sum;
    }
    rep(i,n){
        ll ind = order[i];
        ll cur = b[ind]-a[ind];
        if (cur <= 0ll) continue;
        profit[i] = max(cur+profit[i-1],cur);
    }
    debug(loss,profit);
    ll sol = 0;
    rep(i,n-k){
        sol = max(sol,profit[i]-loss[i+1ll]);
    }
    cout << sol << endl;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    if (k == 0ll){
        ll sol = 0ll;
        rep(i,n) sol += max(b[i]-a[i],0ll);
        cout << sol << endl;
        return;
    }
    if (k == n) return void(cout << "0\n");
    vector<ll> order(n);
    iota(all(order),0ll);
    stable_sort(all(order),[&](const ll &i, const ll &j) {
        return b[i] < b[j];
    });
    vector<ll> loss(n,LLONG_MIN), profit(n,0);
    multiset<ll> vals;
    ll sum = 0ll;
    rep(i,k){
        ll ind = order[n-i-1ll];
        sum += a[ind];
        vals.insert(a[ind]);
    }
    loss[n-k] = sum;
    rep(i,n-k-1ll,0ll,-1ll){
        ll ind = order[i];
        sum += a[ind];
        vals.insert(a[ind]);
        sum -= *vals.rbegin();
        vals.erase(prev(vals.end()));
        loss[i] = sum;
    }
    ll sol = 0;
    rep(i,n){
        ll ind = order[i];
        ll cur = b[ind]-a[ind];
        if (!i) profit[i] = max(profit[i],cur);
        else profit[i] = max({profit[i],profit[i-1],profit[i-1]+cur,cur});
    }
    debug(order,profit,loss);
    rep(i,n-k){
        sol = max(sol,profit[i]-loss[i+1ll]);
    }
    cout << sol << endl;
}

/*

4

1
2 0
2 1
1 2

1
4 1
1 2 1 4
3 3 2 3

1
4 2
2 1 1 1
4 2 3 2

1
6 2
1 3 4 9 1 3
7 6 8 10 6 8



*/