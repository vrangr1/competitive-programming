/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun May 26 20:15:54 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
#endif
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
    vector<ll> lcms(n);
    auto lcm = [](ll a, ll b) -> ll {
        ll d = gcd(a,b);
        return (a*b)/d;
    };
    lcms[0] = a.front();
    rep(i,1,n-1,1)
        lcms[i] = lcm(lcms[i-1],a[i]);
    if (lcms.back() > a.back()) return void(cout << n << endl);
    vector<map<ll,ll>> mp(n);
    auto pf = [](ll v, map<ll,ll> &mp) -> void {
        ll f = 2, ct = 0;
        while((v%f) == 0ll) {
            v/=f;
            ct++;
        }
        if (ct) mp[f] = ct;
        ll sq = bsqrt(v);
        for(f=3;f <= sq; f+=2ll) {
            if (v%f) continue;
            ct = 0ll;
            while((v%f) == 0ll) {
                v/=f;
                ct++;
            }
            mp[f] = ct;
        }
        if (v > 1ll) mp[v]++;
    };
    rep(i,n) {
        pf(a[i],mp[i]);
    }
    auto proc = [&](ll i) {
        if (lcms[i] == a[i]) return 0ll;
        
        // ll sol = 0;
        // for (auto [f, ct] : mp[i]) {
        //     ll p = 0ll;
        //     rep(j,i) {
        //         if (mp[j].find(f) == mp[j].end()) continue;
        //         assert(mp[j][f] <= ct);
        //         p += (mp[j][f] == ct);
        //     }
        //     sol = max(i+1ll-p,sol);
        // }
        // return sol;
    };
    ll sol = 0;
    debug(a,lcms,endl);
    rep(i,n-1,1ll,-1) {
        debug(i,proc(i),endl);
        sol = max(sol,proc(i));
    }
    cout << sol << endl;
}