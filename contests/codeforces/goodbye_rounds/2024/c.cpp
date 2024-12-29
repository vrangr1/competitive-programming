/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Dec 28 20:38:14 IST 2024
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

void solve() {
    map<ll,pair<ll,ll>> mp;
    auto get = [&](auto &&self, ll n, ll k) -> pair<ll,ll> {
        if (mp.find(n) != mp.end()) return mp[n];
        if (n < k) return mp[n] = {0,0};
        ll sol = 0ll, ct = 0;
        auto [rsum, rct] = self(self, n/2ll, k);
        if (n%2ll) {
            sol = n/2ll + 1ll + 2ll*rsum + rct*(n/2ll + 1ll);
            ct = 2ll*rct + 1ll;
        } else {
            sol = 2ll*rsum + (n/2ll)*rct;
            ct = 2ll*rct;
        }
        debug(n,rsum, rct, sol, ct, endl);
        return mp[n] = {sol, ct};
    };
    ll n, k; cin >> n >> k;
    cout << get(get,n, k).first << endl;
}