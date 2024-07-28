/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 27 19:47:50 IST 2024
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

class DSU {
public:
    int n;
    vector<int> parent, rank;
    DSU(int gn) : parent(gn,-1), rank(gn,1) {
        n = gn;
    }

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) swap(px,py);
        parent[px] = py;
        if (rank[px] == rank[py]) rank[py]++;
    }
};

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int,int>> edges;
    rep(i,n) {
        int u, v; cin >> u >> v; --u;--v;
        edges.emplace_back(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int sol = 0;
    vector<bool> vis(n,false);
    DSU dsu(n);
    vector<int> loop;
    auto dfs = [&](auto &&self, int u, int p, auto &seen, vector<int> &nodes) -> void {
        // debug(u);
        assert(!vis[u]);
        vis[u] = true;
        seen.insert(u);
        nodes.push_back(u);
        for (int &v : g[u]) {
            if(v == p) continue;
            if (vis[v]) {
                if (seen.find(v) == seen.end()) continue;
                if (!loop.empty()) {
                    continue;
                }
                // assert(loop.empty());
                while(nodes.back() != v) {
                    loop.push_back(nodes.back());
                    nodes.pop_back();
                    assert(!nodes.empty());
                }
                reverse(all(loop));
                nodes.insert(nodes.end(),all(loop));
                loop.push_back(v);
                continue;
            }
            self(self, v, u, seen, nodes);
        }
        nodes.pop_back();
    };
    rep(i,n) {
        if (vis[i]) continue;
        // debug('s');
        vector<int> nodes;
        set<int> seen;
        dfs(dfs,i,-1,seen,nodes);
    }
    assert(!loop.empty());
    if(sz(loop) == n) return void(cout << n-2<<endl);
    int m = sz(loop);
    debug(n,loop,m);
    rep(i,1,sz(loop)-1,1)
        dsu.unite(loop[0],loop[i]);
    vector<int> deg(n,0);
    for (auto &[u,v] : edges) {
        int pu = dsu.find(u), pv = dsu.find(v);
        if (pu == pv) continue;
        deg[pu]++;
        deg[pv]++;
    }
    int k = int(count(all(deg),1));
    debug(k);
    ll rem = n-m+1-k;
    debug(rem);
    if (rem == 1) {
        cout << (m-2) << endl;
        return;
    }
    sol += m-1;
    sol += (n-m+1-k);
    cout << sol << endl;
}