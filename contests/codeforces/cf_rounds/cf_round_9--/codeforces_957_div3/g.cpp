/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jul 12 03:35:56 IST 2024
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

const ll mod = (ll)1e9+7ll, maxn = (ll)5e3;
vector<ll> fac(maxn+1), invfac(maxn+1);

ll inv(ll n) {
    if (n <= 1) return 1;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
    rep(f,2,(ll)maxn,1) {
        fac[f] = (fac[f-1]*f)%mod;
        invfac[f] = (invfac[f-1]*inv(f))%mod;
    }
}

ll ncr(ll n, ll r) {
    if (n < r) return 0ll;
    if (n < 0 || r < 0) return 1;
    assert(n >= 0 && r >= 0 && n-r >= 0);
    assert(n <= maxn && r <= maxn && n-r <= maxn);
    return (((fac[n]*invfac[r])%mod)*invfac[n-r])%mod;
}

void solve() {
    init();
    ll n; cin >> n;
    ll sol = 0ll;
    rep(l,n+1ll) {
        rep(s,l+1ll,2ll*l+1ll,1ll) {
            if (s-1ll-l > n) continue;
            debug(endl,l,s);
            ll cur = ncr(min(s-1ll,n),s-1ll-l)*s;
            cur%=mod;
            if (2ll*l-s+1ll > 0ll)
            cur *= ncr(n-s,2ll*l-s+1ll);
            cur%=mod;
            debug(cur);
            sol+=cur;
            sol%=mod;
        }
    }
    cout << sol << endl;
}