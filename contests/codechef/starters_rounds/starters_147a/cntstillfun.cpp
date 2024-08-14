/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 14 20:37:21 IST 2024
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
const ll maxn = ll(3e5)+2ll;
vector<ll> fac(maxn), invfac(maxn);

ll inv(ll n) {
    if (n <= 1ll) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    fac[0]=fac[1]=invfac[0]=invfac[1] = 1;
    rep(f,2,maxn-1ll,1) {
        fac[f] = (fac[f-1]*f)%mod;
        invfac[f] = (invfac[f-1]*inv(f))%mod;
    }
}

ll ncr(ll n, ll r) {
    assert(n >= r);
    assert(r >= 0ll);
    return (((fac[n]*invfac[r])%mod)*invfac[n-r])%mod;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    vector<bool> seen(n+1,false);
    vector<ll> x, y;
    rep(i,n) {
        cin >> a[i];
        if (seen[a[i]]) x.push_back(a[i]);
        seen[a[i]] = true;
    }
    rep(i,1,n,1ll)
        if (!seen[i]) y.push_back(i);
    sort(all(x));
    ll k = sz(x);
    debug(x,y);
    auto pwr = [](auto &&self, ll v, ll m) -> ll {
        if (m == 0ll) return 1ll;
        ll a2 = (v*v)%mod;
        if (m%2ll) return (v*self(self,a2,m/2ll))%mod;
        return self(self,a2,m/2ll);
    };
    ll sol = 0ll, ct = 0ll;
    rep(i,k) {
        if (y[i] >= x[i]) 
            return void(cout << "0\n");
        ct++;
        if (i == k-1ll) continue;
        assert(ct >= x[i+1]-x[i]-1ll);
        sol += (ncr(ct,x[i+1ll]-x[i]-1ll)*pwr(pwr,2ll,x[i+1ll]-x[i]-1ll))%mod;
        ct -= x[i+1]-x[i]-1ll;
    }
    debug(sol,ct);
    sol += pwr(pwr,2ll,ct);
    cout << sol << endl;
    // cout << pwr(pwr,2ll,k) << endl;
}