/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 21:34:31 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    ll sol = 0ll;
    ll i = n-1ll, j = m-1ll;
    while(i >= 0ll) {
        while(j >= 0ll && a[i] > b[j]) {
            j--;
        }
        if (j < 0) break;
        ll cur = 0ll;
        while(cur <= b[j] && i >= 0ll) {
            cur += a[i];
            --i;
        }
        if (cur <= b[j]) {
            assert(i < 0ll);
            sol += m-j-1ll;
            break;
        }
        cur -= a[++i];
        assert(cur <= b[j]);
        assert(cur > 0ll);
        sol += m-j-1ll;
    }
    if (i >= 0ll) return void(cout << "-1\n");
    cout << sol << endl;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    vector<vector<array<ll,2>>> dp(n,vector<array<ll,2>>(m,{LLONG_MAX,LLONG_MAX}));
    auto get = [&](ll l, ll r) -> ll {
        if (l == 0ll) return psum[r];
        return psum[r] - psum[l-1];
    };
    auto add = [&](ll v1, ll v2) -> ll {
        if (v1 == LLONG_MAX || v2 == LLONG_MAX) return LLONG_MAX;
        return v1+v2;
    };
    rep(j,m) {
        rep(i,n) {
            if (j) dp[i][j] = dp[i][j-1];
            if (a[i] > b[j]) continue;
            ll low = 0ll, high = i;
            while(low < high) {
                ll mid = (low+high)/2ll;
                if (get(mid,high) <= b[j]) high = mid;
                else low = mid+1ll;
            }
            if (j == 0ll) {
                if (high == 0ll) dp[i][j] = {m-j-1ll,m-j-1ll};
                else {
                    dp[i][j] = {add(m-j-1ll,dp[high-1ll][j][0]),min(dp[i][j-1][0],dp[i][j-1][1])};
                    // dp[i][j] = add(m-j-1ll,dp[high-1ll][j]);
                }
            } else {
                // if (high == 0ll) dp[i][j] = min(dp[i][j-1],m-j-1ll);
                // else dp[i][j] = min(dp[i][j-1],add(m-j-1ll,dp[high-1ll][j]));
                if (high == 0ll) dp[i][j] = {m-j-1ll,min(dp[i][j-1][0],dp[i][j-1][1])};
                else {
                    
                }
            }
        }
    }
    ll sol = LLONG_MAX;
    debug(dp);
    rep(j,m) sol = min(sol,dp[n-1ll][j]);
    if (sol == LLONG_MAX) cout << "-1\n";
    else cout << sol << endl;
}