/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 12 18:24:35 IST 2024
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

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> mat(n,vector<ll>(m,-1));
    vector<vector<pair<ll,ll>>> g(n);
    vector<array<ll,3>> edges(m);
    rep(i,m) {
        ll u, v, c; cin >> u >> v >> c;
        --u;--v;
        edges[i] = {u,v,c};
        g[u].emplace_back(v,c);
        g[v].emplace_back(u,c);
        mat[u][v] = mat[v][u] = c;
    }
    rep(i,n) mat[i][i] = 0;
    vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX));
    vector<bool> vis(n);
    [[maybe_unused]] auto dijk = [&](ll src) -> void {
        // auto comp = [&](const pair<int,int> &a, const pair<int,int> &b) -> bool {
        //     return a.first > b.first;
        // };
        // priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(comp)> pq(comp);
        priority_queue<pair<ll,ll>> pq;
        pq.emplace(0ll,src);
        fill(all(vis),false);
        ll ct = 0;
        rep(i,n) if (i != src)
            dist[i][src] = dist[src][i] = LLONG_MAX;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            d = -d;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            ct++;
            if (ct == n) break;
            for (auto &[v,c] : g[u]) {
                if (mat[u][v] == -1 || vis[v] || dist[src][v] <= c+d) continue;
                dist[src][v] = dist[v][src] = c+d;
                pq.emplace(-(d+c),v);
            }
        }
    };
    auto recompute = [&]() -> void {
        rep(u,n)
            dijk(u);
        // floyd-warshall:
        // rep(i,n)
        //     rep(j,n)
        //         if (mat[i][j] == -1) dist[i][j] = LLONG_MAX;
        //         else dist[i][j] = mat[i][j];
        // rep(i,n) {
        //     rep(j,n) {
        //         rep(k,n) {
        //             if (mat[i][k] == -1 || mat[k][j] == -1 || dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
        //             dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        //         }
        //     }
        // }
    };
    recompute();
    while(q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll i; cin >> i; --i;
            auto &[u,v,c] = edges[i];
            if (mat[u][v] == -1) continue;
            mat[u][v] = mat[v][u] = -1;
            recompute();
        } else {
            ll u, v; cin >> u >> v;
            --u;--v;
            if (u == v) cout << "0\n";
            else if (dist[u][v] == LLONG_MAX) cout << "-1\n";
            else cout << dist[u][v] << endl;
        }
    }
}