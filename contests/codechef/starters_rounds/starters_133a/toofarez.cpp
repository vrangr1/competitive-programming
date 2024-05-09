/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  8 20:33:13 IST 2024
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

const ll mod = 998244353ll;

vector<ll> fac((int)5e5+1), invfac((int)5e5+1);

ll inv(ll n) {
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    invfac[0] = invfac[1] = 1ll;
    rep(f,2,sz(fac)-1ll,1){
        fac[f] = (fac[f-1]*f)%mod;
        invfac[f] = (invfac[f-1]*inv(f))%mod;
    }
}

ll ncr(ll n, ll r) {
    ll sol = (fac[n]*invfac[r])%mod;
    return (sol*invfac[n-r])%mod;
}

ll npr(ll n, ll r) {
    return (fac[n]*invfac[n-r])%mod;
}

void solve(){
    init();
    ll n, m; cin >> n >> m;
    auto pwr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0ll) return 1ll;
        ll a2 = (a*a)%mod;
        if (n%2ll) return (a*self(self,a2,n/2ll))%mod;
        return self(self,a2,n/2ll);
    };
    auto get = [n,m,&pwr](ll c) -> ll {
        if (c > n) return 0ll;
        ll f = fac[c], k = n/c;
        if (n%c) {
            ll sol = (pwr(pwr,f,k)*npr(c,n%c))%mod;
            sol *= ncr(m,c);
            sol%=mod;
            return sol;
        }
        return (ncr(m,c)*pwr(pwr,f,k))%mod;
    };
    ll sol = 0ll;
    rep(c,1,m,1){
        sol += get(c);
        sol%=mod;
    }
    cout << sol << endl;
}