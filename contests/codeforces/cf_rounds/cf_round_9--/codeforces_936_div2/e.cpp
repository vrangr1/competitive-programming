/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 22 21:33:24 IST 2024
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

const ll mod = ((ll)1e9) + 7ll, maxn = (ll)2e5 + 10ll;

vector<ll> fac(maxn), invfac(maxn,-1ll);

ll inv(ll n) {
    if (n <= 1ll) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

ll invf(ll n) {
    if (invfac[n] != -1) return invfac[n];
    return invfac[n] = inv(fac[n]);
};

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    rep(i,2ll,maxn-1ll,1ll)
        fac[i] = (fac[i-1ll]*i)%mod;
}

ll ncr(ll n, ll r){
    assert(n>=r);
    ll sol = fac[n];
    sol *= invf(n-r);
    sol%=mod;
    sol*=invf(r);
    return sol%mod;
}

void solve(){
    init();
    ll n, m1, m2; cin >> n >> m1 >> m2;
    vector<ll> p(m1), s(m2);
    rep(i,m1) cin >> p[i];
    rep(i,m2) cin >> s[i];
    if (p.back() != s.front()) return void(cout << "0\n");
    ll sol = 1ll;
    auto get = [](auto &&self, ll n, ll ind, ll left, ll right, ll m1, ll m2, deque<ll> &p, deque<ll> &s) -> ll {
        ll sol = ncr(n-1ll,left);
        sol%=mod;
        if (m1 == 0){
            sol *= fac[left];
            sol%=mod;
            if (m2 == 0){
                sol *= fac[right];
                sol%=mod;
                return;
            }
            ll v = s.front();
            s.pop_front();
            deque<ll> t;
            sol *= self(self, right, v, v-ind-1ll, right-(v-ind-1ll)-1ll, 0ll, sz(s), t, s);
            sol%=mod;
            return sol;
        }
        ll v = p.back();
        sol *= self(self, left, )
        sol *= self(self,left,)
    };
    ll left = p.back()-1ll, right = n-left-1ll;
    assert(right == n-left-1ll);
    ll sol = ncr(n-1ll,left)%mod;
    sol*=fac[left-m1+1ll];
    sol%=mod;
    sol*=fac[right-m2+1ll];
    sol%=mod;
    cout << (sol) << endl;
}