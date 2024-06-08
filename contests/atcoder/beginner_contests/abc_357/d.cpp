/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun  8 17:44:56 IST 2024
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

const ll mod = 998244353ll;
const i128 mod2 = 998244353;

void solve() {
    ll n; cin >> n;
    map<ll,ll> save;
    auto pwr = [](auto &&self, i128 a, i128 m) -> ll {
        if (m == 0ll) return 1ll;
        assert(m>0ll);
        i128 a2 = (a*a)%mod2;
        if (m%2ll) return (ll)((a*self(self,a2,m/(i128)2ll))%mod2);
        return (ll)self(self,a2,m/(i128)2);
    };
    i128 len = sz(to_string(n));
    auto get = [&](auto &&self, ll m) -> ll {
        assert(m >= 0ll);
        if (save.find(m) != save.end()) return save[m];
        if (m == 0ll) return save[m] = 0ll;
        if (m == 1ll) return save[m] = n%mod;
        ll right = self(self,m/2ll)%mod, left = self(self,m-(m/2ll))%mod;
        return save[m] = (((pwr(pwr,10ll,((i128)(m/2ll))*len)%mod)*left)%mod + right)%mod;
    };
    ll sol = get(get,n);
    cout << sol << endl;
}