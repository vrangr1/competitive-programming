/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Mar 19 11:07:03 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll l, r; cin >> l >> r;
    if (a[0] == 1ll) return void(cout << r-l+1ll << endl);
    ll m = a[0];
    vector<ll> inds(m,LLONG_MAX);
    inds[0] = 0ll;
    rep(i,n){
        ll k = a[i]%m;
        if (k == 0) continue;
        ll s = 1ll;
        while(true){
            bool upd = false;
            rep(j,m){
                s++;
                ll cur = (s%m);
                ll prev = cur-k;
                if (prev < 0) prev += m;
                if (inds[prev] == LLONG_MAX) continue;
                if (inds[cur] > inds[prev]+a[i])
                    upd = true;
                inds[cur] = min(inds[cur],inds[prev]+a[i]);
            }
            if (!upd) break;
        }
    }
    debug(m,a,inds);
    auto get = [&](ll rem) -> ll {
        assert(rem < m);
        ll st = inds[rem];
        if (st == LLONG_MAX) return 0ll;
        assert(st%m == rem);
        ll sol;
        if (st > r) sol = 0ll;
        else if (st < l) sol = max((r-rem)/m,0ll) - max((l-1ll-rem)/m,0ll);
        else sol = max((r-rem)/m,0ll) - (st-rem)/m + 1ll;
        debug(rem,sol);
        return sol;
    };
    ll sol = 0ll;
    rep(i,m) sol += get(i);
    cout << sol << endl;
}