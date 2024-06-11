/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun  9 20:31:13 IST 2024
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

// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = 998244353ll;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> dp(n,vector<ll>(4));
    rep(i,n) {
        if (!i) {
            dp[i][0] = llabs(a[i]);
            dp[i][1] = a[i];
            dp[i][2] = (a[i] >= 0ll?2ll:1ll);
            dp[i][3] = (a[i] >= 0ll?2ll:1ll);
            continue;
        }
        dp[i][1] = dp[i-1][1] + a[i];
        if (dp[i][1] >= 0ll)
            dp[i][3] = (dp[i-1][3]*2ll)%mod;
        else dp[i][3] = dp[i-1][3];
        ll v1 = llabs(dp[i-1][0]+a[i]), v2 = llabs(llabs(dp[i-1][1]) + a[i]), v3 = llabs(dp[i-1][1]+a[i]);
        dp[i][0] = max({v1,v2,v3});
        debug(i,v1,v2,v3);
        if (v3 > v1 && v3 > v2) {
            dp[i][2] = dp[i-1][3];
            continue;
        }
        if (v2 > v3 && v2 > v1) {
            dp[i][2] = dp[i-1][3];
            continue;
        }
        if (v2 == v3 && v2 > v1) {
            assert(a[i] == 0 || dp[i-1][1] >= 0ll);
            // if (dp[i-1][1] >= 0ll) {
            ll p = (dp[i-1][1]+a[i]>=0ll?2ll:1ll);
            dp[i][2] = (dp[i-1][3]*p)%mod;
            continue;
            // }
            // assert(a[i] == 0ll);
            // ll p = (dp[i-1][1]+a[i]>=0ll?2ll:1ll);
        }
        assert(v1 >= v2 && v1 >= v3);
        // if (v1 < v2 || v1 < v3) {
        //     exit(0);
        // }
        if (v1 > v2 && v1 > v3) {
            if (dp[i-1][0] + a[i] >= 0ll) dp[i][2] = (dp[i-1][2]*2ll)%mod;
            else dp[i][2] = dp[i-1][2];
            continue;
        }
        if (v1 > v2) {
            assert(a[i] < 0 && dp[i-1][1] < 0);
            assert(dp[i-1][0]+a[i] >= 0ll);
            dp[i][2] = ((dp[i-1][2]*2ll)%mod + dp[i-1][3])%mod;
            continue;
        }
        if (v1 > v3) {
            assert(dp[i-1][1] < 0 && a[i] > 0);
            assert(dp[i-1][0]+a[i] >= 0ll);
            dp[i][2] = (dp[i-1][2]*2ll)%mod;
            // dp[i][2] = ((dp[i-1][2]*2ll)%mod + (dp[i-1][3]*2ll)%mod)%mod;
            continue;
        }
        assert(v1 == v2 && v1 == v3);
        assert(a[i] == 0 || dp[i-1][2] >= 0ll);
        if (a[i] < 0 && dp[i-1][0] > dp[i-1][1]) {
            ll prod = (dp[i-1][1]+a[i] >= 0ll? 2ll: 1ll);
            ll p1 = (dp[i-1][0]+a[i] >= 0ll?2ll:1ll);
            dp[i][2] = ((dp[i-1][2]*p1)%mod + (dp[i-1][3]*prod)%mod)%mod;
            continue;
        }
        if (a[i] == 0ll) {
            ll prod = (dp[i-1][1]+a[i] >= 0ll? 2ll: 1ll);
            ll p1 = (dp[i-1][0]+a[i] >= 0ll?2ll:1ll);
            if (dp[i-1][0] != dp[i-1][1])
                dp[i][2] = ((dp[i-1][2]*p1)%mod + (dp[i-1][3]*prod)%mod)%mod;
            else dp[i][2] = (dp[i-1][2]*2ll)%mod;
            continue;
        }
        if (dp[i-1][0]+a[i] >= 0ll) dp[i][2] = (dp[i-1][2]*2ll)%mod;
        else dp[i][2] = dp[i-1][2];
    }
    debug(dp);
    cout << dp.back().at(2) << endl;
}