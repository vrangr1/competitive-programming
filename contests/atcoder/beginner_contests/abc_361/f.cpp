/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul  6 18:15:52 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
#define yes "YES\n"
#define no "NO\n"
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

int main() {
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    auto pwr = [](auto &&self, i128 a, i128 n) -> i128 {
        if (n == 0) return 1;
        if (n%2) return a*self(self,a*a,n/((i128)2));
        return self(self,a*a,n/((i128)2));
    };
    auto bsch = [&pwr](auto &&self, i128 low, i128 high, const i128 n, const i128 r) -> i128 {
        assert(low <= high);
        if (low == high) {
            assert(pwr(pwr,low,r) <= n);
            return low;
        }
        i128 mid = (low+high+(i128)1)/((i128)2);
        i128 pr = pwr(pwr,mid,r);
        if (pr <= n) return self(self,mid,high,n,r);
        return self(self,low,mid-1ll,n,r);
    };
    auto rth_root = [&bsch, &pwr](i128 n, i128 r) -> i128 {
        i128 low = 1, high = (i128)powl((ld)n,((ld)1)/((ld)r));
        high+=(i128)2;
        assert(pwr(pwr,high,r) > n);
        i128 res = bsch(bsch,low,high,n,r);
        assert(pwr(pwr,res,r) <= n);
        assert(pwr(pwr,res+1ll,r) > n);
        // debug('r',(ll)n,(ll)r,(ll)res);
        return res;
    };
    auto is_prime = [](ll n) -> bool {
        if (n == 1) return false;
        if (n == 2) return true;
        ll sq = bsqrt(n);
        rep(f,2,sq,1)
            if ((n%f) == 0ll) return false;
        return true;
    };
    auto get = [&](auto &&self, ll n, ll pr = 18ll) -> ll {
        ll sol = 0ll;
        rep(r,2,pr,1) {
            if (!is_prime(r)) continue;
            ll lim = (ll)rth_root(n,r);
            if (lim == 1ll) break;
            lim -= self(self,lim,r-1ll);
            debug(endl,n,r,lim);
            sol += lim-1ll;
        }
        return sol;
    };
    ll n; cin >> n;
    cout << get(get,n) +1ll << endl;
}