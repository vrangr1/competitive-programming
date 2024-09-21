/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 21 20:55:10 IST 2024
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
    ll n, m, h; cin >> n >> m >> h;
    vector<bool> hs(n+1,false);
    rep(i,h) {
        ll l; cin >> l;
        hs[l] = true;
    }
    vector<vector<pair<ll,ll>>> g(n+1ll);
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<vector<pair<ll,ll>>> mar(3,vector<pair<ll,ll>>(n+1,{-1ll,-1ll})), rob(3,vector<pair<ll,ll>>(n+1ll,{-1ll,-1ll}));
    auto dijk = [&](ll src, vector<pair<ll,ll>> &dp, ll t) -> void {
        auto comp = [](const array<ll,3> &a, const array<ll,3> &b) -> bool {
            if (a[1] != b[1]) return a[1] > b[1];
            return a[2] < b[2];
        };
        priority_queue<array<ll,3>,vector<array<ll,3>>,decltype(comp)> pq(comp); // node, time, horses
        pq.emplace(src,0ll,0ll);
        while(!pq.empty()) {
            auto [u, d, cth] = pq.top();
            cth += hs[u];
            pq.pop();
            if (dp[u].first != -1 && (dp[u].first < d || (dp[u].first == d && dp[u].second >= cth))) {
                assert(dp[u].first <= d);
                continue;
            }
            dp[u] = {d,cth};
            for (auto [v, w] : g[u]) {
                
            }
        }
    };
}