/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Thu Oct 24 20:28:20 IST 2024
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


const ll maxn = ll(1e6) + 5ll;
vector<ll> dp(maxn);

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    dp[0] = dp[1] = dp[2] = 0ll;
    dp[3] = 1ll;
    dp[4] = 1ll;
    dp[5] = 2ll;
    rep(n,6,maxn-1ll,1ll) {
        ll x = n/2ll, y = n-n/2ll;
        dp[n] = dp[x] + dp[y] + 1ll;
    }
}

void solve() {
    init();
    ll n; cin >> n;
    vector<ll> p(n+1);
    rep(i,1,n,1)
        cin >> p[i];
    ll sol = 0ll;
    vector<bool> vis(n,false);
    rep(i,n) {
        if (vis[i]) continue;
        ll l = 0, ind = i;
        while(!vis[ind]) {
            l++;
            vis[ind] = true;
            ind = p[ind];
        }
        // debug(l,(64ll-__builtin_clzll((l>>1ll))));
        // if (l == 1ll) continue;
        // sol += (64ll-__builtin_clzll((l>>1ll)));
        // sol += (l-1ll)/2ll;
        debug(l,dp[l]);
        sol += dp[l];
    }
    cout << sol << endl;
}