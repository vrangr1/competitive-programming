/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar 20 21:08:48 IST 2024
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

const ll mod = (ll)1e9+7ll;

void solve1(){
    ll n, k; cin >> n >> k;
    auto get = [k](ll n) -> vector<ll> {
        if (n%k) return {};
        if (n == 1) return {1};
        vector<ll> facs;
        int f = 2;
        while (n%f == 0){
            if (facs.empty() || facs.back() != f)
                facs.push_back(f);
            n/=f;
        }
        for(f=3;f<=k;f+=2){
            if (n%f) continue;
            while(n%f == 0){
                if (facs.empty() || facs.back() != f)
                    facs.push_back(f);
                n/=f;
            }
        }
        if (n > 1 && n <= k) facs.push_back(n);
        return facs;
    };
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    {
        auto kfac = get(k);
        assert(sz(kfac) > 0);
        if (sz(kfac) > 1)
            return void(cout << "0\n");
    }
    ll kct = 0ll;
    rep(i,n){
        ll a = v[i];
        if (a%k) continue;
        vector<ll> p = get(a);
        if (sz(p) == 0) continue;
        ++kct;

    }
    

    auto pr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0) return 1ll;
        ll a2 = (a*a)%mod;
        if (n%2ll) return (a*self(self,a2,n/2ll))%mod;
        return self(self,a2,n/2ll);
    };
    ll sol = 0ll;
    // ll sol = pr(pr,2ll,ct)-1ll;
    cout << sol << endl;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
}