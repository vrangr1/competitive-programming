/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug  6 20:29:39 IST 2024
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

const ll mod = ll(1e9)+7ll;
const ll maxn = ll(2e5)+2ll;
vector<ll> fac(maxn), invfac(maxn);

ll inv(ll n) {
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
    rep(n,2,(ll)maxn-1ll,1ll) {
        fac[n] = (fac[n-1]*n)%mod;
        invfac[n] = (invfac[n-1]*inv(n))%mod;
    }
}

ll ncr(ll n, ll r) {
    assert(n>=r);
    assert(r>=0ll);
    ll sol = (fac[n]*invfac[r])%mod;
    sol*=invfac[n-r];
    return sol%mod;
}

void solve() {
    init();
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    ll z = 0, o = 0;
    rep(i,n) {
        cin >> a[i];
        if (a[i]) o++;
        else z++;
    }
    if (o < (k+1ll)/2ll) return void(cout << "0\n");
    ll sol = 0ll;
    rep(s,(k+1ll)/2ll,(ll)min(o,k),1ll) {
        if (z < k-s) continue;
        sol += (ncr(o,s)*ncr(z,k-s))%mod;
        sol%=mod;
    }
    cout << sol << endl;
}