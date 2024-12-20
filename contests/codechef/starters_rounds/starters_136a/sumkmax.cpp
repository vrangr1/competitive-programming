/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 29 21:26:46 IST 2024
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
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = (ll)1e9+7ll, mxf = (ll)3e5+3ll;
vector<ll> fac(mxf), invfac(mxf);

ll inv(ll n) {
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    invfac[0] = invfac[1] = 1ll;
    rep(i,2,mxf-1ll,1) {
        fac[i] = (fac[i-1]*i)%mod;
        invfac[i] = (invfac[i-1]*inv(i))%mod;
    }
}

ll ncr(ll n, ll r) {
    assert(n >= r);
    ll sol = (fac[n]*invfac[r])%mod;
    return (sol*invfac[n-r])%mod;
}

void solve(){
    init();
    ll n; cin >> n;
    auto get = [n](ll k) -> ll {
        ll s = n/k;
        if (((n-k+1ll)%k) == 0ll)
            return (fac[s]*fac[n-s])%mod;
        ll f = (k*s - (n-k+1ll)+1ll);
        return (((fac[s]*fac[n-s])%mod)*f)%mod;
    };
    rep(k,1,n,1) 
        cout << get(k) << " \n"[k==n];
}