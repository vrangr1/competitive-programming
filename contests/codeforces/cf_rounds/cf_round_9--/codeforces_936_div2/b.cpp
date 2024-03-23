/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 22 20:23:57 IST 2024
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

const ll mod = (ll)1e9+7ll;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll mxsum = 0, sum = 0ll;
    rep(i,n){
        sum += a[i];
        mxsum = max(mxsum,sum);
        if (sum < 0){
            sum = 0ll;
            continue;
        }
    }
    auto pwr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0ll) return 1ll;
        ll a2 = (a*a)%mod;
        if (n%2ll) return (a*self(self,a2,n/2ll))%mod;
        return self(self,a2,n/2ll);
    };
    ll rest = accumulate(all(a),0ll);
    if (rest >= 0) rest %=mod;
    while(rest < 0) rest += mod;
    assert(rest >= 0ll);
    rest %= mod;
    assert(mxsum >= 0ll);
    mxsum %= mod;
    rest = (rest - mxsum + mod)%mod;
    ll sol = (mxsum*pwr(pwr,2ll,k))%mod;
    sol = (sol + rest + mod)%mod;
    cout << sol << endl;
}