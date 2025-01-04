/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Jan  4 21:32:02 IST 2025
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

class DSU {
public:
    int n;
    vector<int> parent, rank;
    DSU(int gn) {
        n = gn;
        parent.assign(n,-1);
        rank.assign(n,0);
    }

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x,y);
        parent[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    // DSU dsu(n);
    vector<array<int,3>> edges(m);
    vector<vector<pair<int,int>>> g(n);
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        --u;
        --v;
        // dsu.unite(u,v);
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
    auto dijk = [&](int src) -> void {
        auto comp = [](const tuple<int,vector<int>,int> &v1, const tuple<int,vector<int>,int> &v2) -> bool {
            return get<2>(v1) > get<2>(v2);
        };
        priority_queue<tuple<int,vector<int>,int>,vector<tuple<int,vector<int>,int>>,decltype(comp)> pq(comp);
        pq.emplace(src,vector<int>{},0);
        vector<bool> vis(n,false);
        while(!pq.empty()) {
            auto [u, vec, mx] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            dp[src][u] = vec;
            vis[u] = true;
            for (auto [v, w] : g[u]) {
                if (vis[v]) continue;
                vec.push_back(w);
                pq.push({v,vec,max(mx,w)});
                vec.pop_back();
            }
        }
    };
    rep(u,n) {
        dijk(u);
        for (auto &vec : dp[u])
            sort(all(vec));
    }
    debug(dp);
    sort(all(edges),[](const array<int,3> &v1, const array<int,3> &v2) {
        return v1[2] > v2[2];
    });
    while(q--) {
        int u, v, k; cin >> u >> v >> k;
        --u;--v;
        int ind = max(0,sz(dp[u][v])-k);
        cout << dp[u][v][ind] << " \n"[q==0];
    }
}