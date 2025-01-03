/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Aug  9 06:14:01 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<vector<tuple<ll,ll>>> g(n);
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w;
        --u;--v;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    ll src, dest; cin >> src >> dest;
    --src;--dest;
    auto dijk = [&]() -> ll {
        auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, decltype(comp)> pq(comp);
        pq.emplace(src,0);
        vector<bool> vis(n,false);
        while(!pq.empty()) {
            auto [u,d] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if (u == dest) return d;
            for (auto [v,w] : g[u]) {
                if (vis[v]) continue;
                pq.emplace(v,w+d);
            }
        }
        return -1ll;
    };
    cout << dijk() << endl;
}