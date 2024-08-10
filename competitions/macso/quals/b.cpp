/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Aug  9 05:58:56 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = ll(1e9)+7l, maxn = 21ll;
vector<ll> facs(maxn), invfac(maxn);
ll inv(ll n) {
    if (n<=1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    facs[0] = facs[1] = invfac[0] = invfac[1] = 1ll;
    rep(f,2,(ll)maxn-1ll,1ll) {
        facs[f] = (f*facs[f-1ll])%mod;
        invfac[f] = (invfac[f-1ll]*inv(f))%mod;
    }
}

ll ways(ll a, ll b, ll c) {
    ll sol = (facs[a+b+c]*invfac[a])%mod;
    sol*=invfac[b];
    sol%=mod;
    return (sol*invfac[c])%mod;
}


void solve() {
    init();
    int n, m, k; cin >> n >> m >> k;
    ll sol = 0;
    for (int c = 0; c <= k; ++c)
        sol += ways(n-c,m-c,c);
    cout << sol << endl;
}