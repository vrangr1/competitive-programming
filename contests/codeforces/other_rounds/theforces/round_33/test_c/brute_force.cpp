/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Aug 12 21:40:48 IST 2024
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
    auto perf = [](ll x, vector<ll> &h) -> bool {
        for (ll &v : h) {
            if (v < x) continue;
            v-=x;
            if (v == 0ll) return false;
            return true;
        }
        return false;
    };
    vector<ll> mxops;
    auto rec = [&](auto &&self, vector<ll> &h, vector<ll> &ops) -> void {
        ll mx = *max_element(all(h));
        rep(x,1,mx,1) {
            auto ch = h;
            auto cops = ops;
            if (perf(x,ch)) {
                cops.push_back(x);
                if (sz(cops) > sz(mxops)) {
                    mxops = cops;
                }
                self(self,ch,cops);
                continue;
            }
            cops.push_back(x);
            if (sz(cops) > sz(mxops)) mxops = cops;
        }
    };
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> ops;
    rec(rec,h,ops);
    cout << sz(mxops) << endl;
    debug(mxops);
}