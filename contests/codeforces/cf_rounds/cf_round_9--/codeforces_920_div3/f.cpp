/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jan 15 21:29:30 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = static_cast<type>(1), two = static_cast<type>(2);
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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    const ll dmax = bsqrt(q)+1ll;
    debug(dmax);
    vector<vector<ll>> psum(dmax,vector<ll>(n)), msum(dmax,vector<ll>(n));
    rep(d,1ll,dmax-1ll,1ll){
        rep(i,n){
            if (i < d){
                psum[d][i] = a[i];
                msum[d][i] = a[i];
                continue;
            }
            psum[d][i] = psum[d][i-d] + a[i];
            msum[d][i] = msum[d][i-d] + a[i]*(i/d + 1ll);
        }
    }
    auto gpsum = [&](ll l, ll r, ll d) -> ll {
        assert(d < dmax);
        if (l < d) return psum[d][r];
        return psum[d][r]-psum[d][l-d];
    };
    auto gmsum = [&](ll l, ll r, ll d) -> ll {
        assert(d < dmax);
        debug(l,r,d,msum[d]);
        if (l < d) return msum[d][r];
        return msum[d][r] - msum[d][l-d] - gpsum(l,r,d)*(l/d);
    };
    while(q--){
        ll s, d, k; cin >> s >> d >> k; --s;
        ll r = min(n-1ll,s+(k-1ll)*d);
        debug(q,s,d,k,r);
        if (d < dmax) cout << gmsum(s,r,d) << " \n"[q==0];
        else{
            ll sol = 0ll;
            rep(i,s,r,d)
                sol += a[i]*((i-s)/d + 1ll);
            cout << sol << " \n"[q==0];
        }
    }
}