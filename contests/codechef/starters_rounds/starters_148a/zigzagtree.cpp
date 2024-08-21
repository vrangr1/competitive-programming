/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 21 21:18:51 IST 2024
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

const ll mod = ll(1e9) + 7ll;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> g(n);
    // vector<ll> p(n,-1);
    rep(i,n-1) {
        // cin >> p[i+1];
        ll p; cin >> p;
        p--;
        g[i+1].push_back(p);
        g[p].push_back(i+1);
    }
    vector<vector<ll>> down(n,vector<ll>(2,0ll));
    ll sol = 0ll;
    auto dfs = [&](auto &&self, ll u, ll p) -> void {
        for (ll &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
            if (a[v] == a[u]) continue;
            else if (a[u] > a[v]) {
                down[u][0] = 1ll+down[v][1ll];
            }
            else {
                down[u][1] = 1ll+down[v][0];
            }
        }
    };
    dfs(dfs,0,-1ll);
    debug(down);
    auto dfs2 = [&](auto &&self, ll u, ll p, pair<ll,ll> up) -> void {
        auto [cdown, cup] = up;
        debug(u,cdown,cup);
        sol += (down[u][0]+down[u][1])%mod;
        sol%=mod;
        sol += (cup+cdown)%mod;
        sol%=mod;
        sol += (down[u][0]*cdown)%mod;
        sol%=mod;
        sol += (down[u][1]*cup)%mod;
        sol%=mod;
        for (ll &v : g[u]) {
            if (v == p) continue;
            ll curup = down[u][1], curdown = down[u][0ll];
            if (a[v] == a[u]) {
                self(self,v,u,{0ll,0ll});
                continue;
            }
            if (a[u] > a[v]) {
                curdown -= down[v][1ll]+1ll;
                self(self,v,u,{curdown,0ll});
                continue;
            }
            assert(a[u] < a[v]);
            curup -= down[v][0]+1ll;
            self(self,v,u,{0ll,curup});
        }
    };
    dfs2(dfs2,0,-1ll,{0ll,0ll});
    cout << sol << endl;
}