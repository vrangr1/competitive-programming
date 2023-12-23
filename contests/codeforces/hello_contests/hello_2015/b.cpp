/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec  5 01:52:06 IST 2023
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

const ll mod = 1e9+7;

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> f(n);
    ll _;
    if (n > 1) cin >> f[0] >> f[1];
    else cin >> f[0] >> _;
    ll f1, f2;
    ll a, b; cin >> a >> b;
    rep(i,2,n-1ll,1ll) f[i] = ((a*f[i-2])%mod + (b*f[i-1])%mod)%mod;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> sts(n,0ll);
    vector<vector<ll>> ends(n+1ll);
    vector<ll> upds(n,0ll), seconds(n,0ll);
    debug(f);
    while(q--){
        ll l, r; cin >> l >> r; --l; --r;
        debug(l,r);
        if (l == r){
            x[l] += f[0];
            x[l] %= mod;
            continue;
        }
        if (r == l+1ll){
            x[l] += f[0];
            x[l] %= mod;
            x[r] += f[1];
            x[r] %= mod;
            continue;
        }
        upds[l] += f[0];
        upds[l+1ll] += f[1];
        seconds[l+1ll]++;
        ends[r+1ll].push_back(r-l+1ll);
    }
    if (n == 1ll){
        print_vec(x);
        return;
    }
    debug(upds,seconds);
    rep(i,2ll,n-1ll,1ll){
        f1 = upds[i-2];
        f2 = (upds[i-1]-(f[0]*seconds[i])%mod + mod)%mod;
        for (ll len : ends[i]){
            assert(len <= n);
            assert(len >= 3);
            f1 -= f[len-2ll];
            f1 = (f1+mod)%mod;
            f2 -= f[len-1ll];
            f2 = (f2+mod)%mod;
        }
        for (ll len : ends[i-1]){
            assert(len <= n);
            assert(len >= 3);
            f1 -= f[len-1ll];
            f1 = (f1+mod)%mod;
        }
        upds[i] += ((f1*a)%mod + (f2*b)%mod)%mod;
        upds[i] %= mod;
    }
    debug(x,upds);
    rep(i,n) x[i] = (x[i] + upds[i])%mod;
    print_vec(x);
}