/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 29 03:46:22 IST 2024
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

const ll mod = 998244353ll, maxn = (ll)1e5+1ll;

vector<ll> fac(maxn), invfac(maxn,-1);

ll inv(ll n){
    if (n <= 1) return 1ll;
    return ((mod - mod/n)*inv(mod%n))%mod;
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    invfac[0] = invfac[1] = 1ll;
    rep(i,2ll,maxn-1ll,1ll){
        fac[i] = (fac[i-1]*i)%mod;
        invfac[i] = (invfac[i-1]*inv(i))%mod;
    }
}

ll ncr(ll n, ll r){
    if (n < r) return 0ll;
    ll sol = fac[n];
    sol *= invfac[n-r];
    sol%=mod;
    sol*=invfac[r];
    sol%=mod;
}

ll nc2(ll n) {
    return (n*(n-1ll))/2ll;
}


void solve(){
    ll n; cin >> n;
    
}