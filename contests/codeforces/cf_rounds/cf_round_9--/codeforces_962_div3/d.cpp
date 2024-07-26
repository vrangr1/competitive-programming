/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jul 26 20:22:17 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll maxn = (ll)1e6;
vector<vector<ll>> facs(maxn);

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    rep(f,1ll,maxn-1ll,1ll) {
        rep(d,f,maxn-1ll,f) {
            facs[d].push_back(f);
        }
    }
}

void solve() {
    init();
    ll n, x; cin >> n >> x;
    auto get = [&](auto &cur, ll d, ll ab) -> ll {
        ll m = sz(cur), sol = 0ll;
        rep(i,(m+1ll)/2ll) {
            if (x-cur[i] < 2ll) break;
            ll o = ab/cur[i];
            ll apb = cur[i]+o;
            if (apb >= x) continue;
            sol += min(d/apb,x-apb)*(o == cur[i]?1ll:2ll);
        }
        return sol;
    };
    ll sol = 0ll;
    rep(ab,1ll,n-2ll,1ll) {
        auto &cur = facs[ab];
        ll d = n-ab;
        sol += get(cur, d, ab);
    }
    cout << sol << endl;
}