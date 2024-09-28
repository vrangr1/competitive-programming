/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 28 17:34:40 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll ninf = -ll(1e18);

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w;
        --u;--v;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,-w);
    }
    vector<bool> vis(n,false);
    vector<ll> x(n,LLONG_MIN);
    auto dfs = [&](auto &&self, ll u) -> void {
        assert(!vis[u]);
        assert(x[u] != LLONG_MIN);
        vis[u] = true;
        for (auto [v,w] : g[u]) {
            if (vis[v]) {
                assert(x[v]-x[u] == w);
                continue;
            }
            x[v] = x[u] + w;
            self(self,v);
        }
    };
    rep(u,n) {
        if (vis[u]) continue;
        x[u] = 0ll;
        dfs(dfs,u);
    }
    print_vec(x);
}