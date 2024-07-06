/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul  6 17:54:44 IST 2024
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

void solve() {
    ll n; cin >> n;
    vector<vector<tuple<ll,ll>>> g(n);
    ll sum = 0ll;
    rep(i,n-1) {
        ll u, v, w; cin >> u >> v >> w;
        g[--u].push_back({--v,w});
        g[v].push_back({u,w});
        sum += w;
    }
    vector<ll> dp(n,0);
    auto dfs = [&](auto &&self, ll u, ll p) -> void {
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u] = max(dp[u], w + dp[v]);
        }
    };
    dfs(dfs,0,-1);
    auto dfs2 = [&](auto &&self, ll u, ll p, ll pw) -> void {
        dp[u] = max(dp[u],pw);
        set<pair<ll,ll>> st;
        st.insert({pw,u});
        for (auto [v, w]: g[u]) {
            if (v == p) continue;
            st.insert({dp[v]+w,v});
            if (sz(st) > 2) st.erase(st.begin());
        }
        assert(sz(st) <= 2);
        ll mn1 = LLONG_MAX, mn2 = mn1, v1 = -1, v2 = -1;
        if (sz(st) >= 1) {
            mn1 = st.rbegin()->first;
            v1 = st.rbegin()->second;
        }
        if (sz(st) == 2) {
            mn2 = st.begin()->first;
            v2 = st.begin()->second;
        }
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            if (v1 == v) {
                assert(v2 != -1);
                self(self,v,u,mn2+w);
                continue;
            }
            assert(v1 != -1);
            self(self,v,u,mn1+w);
        }
    };
    dfs2(dfs2,0,-1,0ll);
    cout << sum*2ll - *max_element(all(dp)) << endl;
}