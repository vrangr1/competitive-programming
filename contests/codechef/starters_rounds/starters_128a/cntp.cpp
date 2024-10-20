/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Apr  3 20:15:09 IST 2024
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

const ll mod = (ll)1e9+7ll, maxn = (ll)2e5 + 1ll;
vector<ll> fac(maxn), faci(maxn), invs(maxn,-1ll);

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = faci[0] = faci[1] = invs[0] = invs[1] = 1;
    rep(n,2,maxn-1ll,1ll){
        fac[n] = (fac[n-1]*n)%mod;
        assert(invs[mod%n] != -1);
        ll inv = ((mod-mod/n)*invs[mod%n])%mod;
        faci[n] = (faci[n-1]*inv)%mod;
        invs[n] = inv;
    }
}

ll ncr(ll n, ll r) {
    assert(n >= r);
    ll sol = (fac[n]*faci[r])%mod;
    sol *= faci[n-r];
    return sol%mod;
}

void solve(){
    init();
    ll n, m, k; cin >> n >> m >> k;
    auto pwr = [](ll a, ll n, bool add = true) -> ll {
        if (add){
            if (a == 0ll) return 0ll;
            if (n == 0ll) return 1ll;
        }
        else {
            if (n == 0ll) return 1ll;
            if (a == 0ll) return 0ll;
        }
        ll sol = 1ll;
        while(n>1ll){
            if (n%2ll) sol *=a;
            a = (a*a)%mod;
            n>>=1ll;
        }
        return (sol*a)%mod;
    };
    ll sol = 0ll;
    rep(x,1ll,n,1ll){
        ll val = ncr(n,x)*pwr(k-1ll,n-x,false);
        val%=mod;
        debug(n,m,k,x,val);
        if (x <= k)
            val *= (pwr(m-k+1ll,x)-pwr(m-k,x)+mod)%mod;
        else val *= (pwr(m-k+1ll,x) - (pwr(m-k,k,false)*pwr(m-k+1ll,x-k))%mod + mod)%mod;
        val%=mod;
        debug(val,sol,pwr(m-k+1ll,x), pwr(m-k,x));
        sol += val;
        sol%=mod;
        debug(endl);
    }
    cout << sol << endl;
}