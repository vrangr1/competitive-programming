/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 21:09:22 IST 2023
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

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = (ll)1e9+7;
ll maxfac = (ll)2e5+1ll;
vector<ll> fact(maxfac), invs(maxfac);

ll inv(ll n){
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fact[0] = fact[1] = 1ll;
    rep(i,2ll,maxfac-1ll,1ll){
        fact[i] = (fact[i-1ll]*i)%mod;
        invs[i] = inv(fact[i]);
    }
}


ll ncr(ll n, ll r){
    if (n < r) return 0ll;
    return ((fact[n]*invs[n-r])%mod * invs[r])%mod;
}

void solve(){
    init();
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll ect = 0ll, oct = 0ll;
    rep(i,n){
        cin >> a[i];
        if (a[i]%2ll) oct++;
        else ect++;
    }
    vector<ll> dp(n+1ll,-1);
    auto compute = [&](const ll r){
        if (dp[r] != -1ll) return dp[r];
        // Can be improved but currently keeping linear time:
        dp[r] = 0ll;
        rep(i,0ll,(ll)r,2ll){
            dp[r] += (ncr(ect,r-i)*ncr(oct,i));
            if (dp[r]) dp[r] %= mod;
        }
        dp[r] *= inv(ncr(n,r));
        if (dp[r]) dp[r] %= mod;
        return dp[r];
    };


}