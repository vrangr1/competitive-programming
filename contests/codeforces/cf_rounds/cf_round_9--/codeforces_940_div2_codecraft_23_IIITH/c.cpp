/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Apr 21 20:22:33 IST 2024
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

const ll mod = (ll)1e9 + 7ll, maxn=(ll)3e5+10ll;

vector<ll> fac(maxn), invfac(maxn);

ll inv(ll n){
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = invfac[0] = invfac[1] = 1ll;
    rep(n,2,maxn-1ll,1ll){
        fac[n] = (fac[n-1]*n)%mod;
        invfac[n] = (invfac[n-1]*inv(n))%mod;
    }
}

ll ncr(ll n, ll r){
    assert(n>=r);
    ll sol = (fac[n]*invfac[r])%mod;
    sol*=invfac[n-r];
    return sol%mod;
}

void solve(){
    init();
    ll n, k; cin >> n >> k;
    ll r = n, c = n;
    rep(i,k){
        ll ri, ci; cin >> ri >> ci;
        --r;--c;
        if (ri != ci){
            --r;
            --c;
        }
    }
    assert(r==c);
    if (r == 0){
        cout << "1\n";
        return;
    }
    assert(r>0);
    ll sol = 0ll;
    rep(s,r+1ll){
        if ((r-s)%2ll) continue;
        ll cur = ncr(r,s), m = r-s;
        cur *= (ncr(m,m/2ll)*fac[m/2ll])%mod;
        cur%=mod;
        sol+=cur;
        sol%=mod;
    }
    cout << sol << endl;
}