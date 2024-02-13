/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Feb 11 15:30:07 IST 2024
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
    ll n, x; cin >> n >> x;
    --n;
    ll cur = n-(x-1ll), other = n+(x-1ll);
    ll sq = bsqrt(other);
    set<ll> st;
    debug(cur,other);
    auto validate = [n,x](ll k) -> bool {
        if (k < x) return false;
        ll r = (n%((2ll*k)-2ll));
        return (r == x-1ll || r == (2ll*k) - 2ll - (x-1ll));
    };
    rep(f,1ll,sq+1ll,1ll){
        // debug(f);
        if ((cur%f) && (other%f)) continue;
        if ((cur%f) == 0ll){
            if (f%2ll == 0ll){
                ll k = (f/2ll)+1ll;
                if (validate(k))
                    st.insert(k);
            }
            ll t = cur/f;
            if (t%2ll == 0ll){
                ll k = (t/2ll)+1ll;
                if (validate(k))
                    st.insert(k);
            }
        }
        if (other%f == 0ll){
            if (f%2ll == 0ll){
                ll k = (f/2ll)+1ll;
                if (validate(k))
                    st.insert(k);
            }
            ll t = other/f;
            if (t%2ll == 0ll){
                ll k = (t/2ll)+1ll;
                if (validate(k))
                    st.insert(k);
            }
        }
    }
    debug(st);
    cout << sz(st) << endl;
}