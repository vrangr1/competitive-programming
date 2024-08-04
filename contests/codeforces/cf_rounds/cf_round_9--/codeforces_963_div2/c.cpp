/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug  4 20:22:52 IST 2024
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

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> ct(k,vector<ll>(2,0ll));
    rep(i,n) {
        ll x = a[i]/k, mod = a[i]%k;
        x%=2ll;
        ct[mod][x]++;
        if (ct[mod][1-x] > 0) return void(cout << "-1\n");
    }
    sort(all(a));
    debug(a,ct);
    ll b = a.back(), bmod = b%k, phase = (b/k)%2ll, root = b-bmod;
    vector<pair<ll,ll>> ints = {{b,b+k-1}};
    rep(i,n-1ll) {
        ll x = a[i]/k, mod = a[i]%k;
        x%=2ll;
        if (phase == x) {
            if (mod <= bmod){
                ints.emplace_back(b,root+mod+k-1);
                continue;
            }
            // sol = max(sol,root+mod);
            ints.emplace_back(root+mod,b+k-1);
            continue;
        }
        assert(mod != bmod);
        if (mod > bmod) {
            ints.emplace_back(b,root+mod-1);
            continue;
        }
        // sol = max(sol,root+mod+k);
        ints.emplace_back(root+mod+k,b+k-1);
    }
    sort(all(ints));
    auto [l,r] = ints.front();
    for (auto [cl,cr] : ints) {
        if (l > r) return void(cout << "-1\n");
        if (r < cl) return void(cout << "-1\n");
        if (l > cr) return void(cout << "-1\n");
        if (cl <= l && r <= cr)
            continue;
        l = max(cl,l);
        r = min(r,cr);
    }
    if (l > r) return void(cout << "-1\n");
    cout << l << endl;
}