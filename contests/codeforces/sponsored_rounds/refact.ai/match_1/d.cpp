/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  9 20:32:26 IST 2024
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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    auto ans = [&](vector<array<int,3>> &ops) -> void {
        int k = sz(ops);
        assert(k <= 2*max(n,m));
        cout << k << endl;
        for (auto [u,v,w] : ops) {
            cout << u+1 << " " << v+1 << " " << w+1 << endl;
        }
    };
    rep(i,m) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<array<int,3>> ops;
    map<pair<int,int>,bool> mp;
    set<pair<int,int>> fwd;
    auto fedge = [&](int u, int v) -> bool {
        if (u > v) swap(u,v);
        assert(u < v);
        return fwd.find({u,v}) != fwd.end();
    };
    auto feins = [&](int u, int v) -> void {
        if (u > v) swap(u,v);
        assert(u < v);
        assert(fwd.find({u,v}) == fwd.end());
        fwd.insert({u,v});
    };
    auto ins = [&](int u, int v) -> void {
        if (u > v) swap(u,v);
        assert(u < v);
        // if (mp.find({u,v}) != mp.end()) {
        //     debug(u,v);
        //     exit(0);
        // }
        assert(mp.find({u,v}) == mp.end());
        mp[{u,v}] = true;
    };
    auto get = [&](int u, int v) -> bool {
        if (u > v) swap(u,v);
        assert(u < v);
        if (mp.find({u,v}) == mp.end()) {
            debug(u,v);
            exit(0);
        }
        assert(mp.find({u,v}) != mp.end());
        return mp[{u,v}];
    };
    auto flip = [&](int u, int v) -> void {
        if (u > v) swap(u,v);
        assert(u < v);
        assert(mp.find({u,v}) != mp.end());
        mp[{u,v}] = !mp[{u,v}];
    };
    vector<bool> vis2(n,false);
    auto dfs = [&](auto &&self, int u, int p, unordered_set<int> &vis) -> unordered_set<int> {
        debug(endl,u);
        assert(!vis2[u]);
        vis2[u] = true;
        vis.insert(u);
        unordered_set<int> fp;
        for (int v : g[u]) {
            if (v == p || fedge(u,v)) continue;
            if (vis.find(v) == vis.end()) {
                ins(u,v);
                auto vfp = self(self,v,u,vis);
                for (int vp : vfp) {
                    if (vp == p) {
                        flip(u,p);
                    } else {
                        if (fp.find(vp) == fp.end()) fp.insert(vp);
                        else fp.erase(vp);
                    }
                }
            } else {
                feins(u,v);
                assert(p != -1);
                assert(v != u && u != p && p != v);
                if (fp.find(v) == fp.end()) fp.insert(v);
                else fp.erase(v);
            }
        }
        vis.erase(u);
        for (int v : fp) {
            assert(v != p);
            assert(p != -1);
            assert(u != v);
            // ops.emplace_back(u,v,p);
            ops.push_back({u,v,p});
            flip(u,p);
        }
        return fp;
    };
    unordered_set<int> vis;
    rep(u,n) {
        if (vis2[u]) continue;
        assert(vis.empty());
        auto rp = dfs(dfs,u,-1,vis);
        assert(rp.empty());
    }
    fill(all(vis2),false);
    vector<int> rt;
    int fd = -1, fdc = -1;
    auto dfs2 = [&](auto &&self, int u, int p, bool crt) -> void {
        assert(!vis2[u]);
        vis2[u] = true;
        int cd = -1;
        for (int v : g[u]) {
            if (v == p || fedge(u,v)) continue;
            if (get(u,v)) {
                self(self,v,u,false);
                cd = v;
            } else {
                self(self,v,u,true);
            }
        }
        if (cd != -1 && crt && fd == -1) {
            fd = u;
            fdc = cd;
        } else if (crt) {
            rt.push_back(u);
        }
    };
    rep(u,n) {
        if (vis2[u]) continue;
        dfs2(dfs2,u,-1,true);
    }
    if (fd == -1) {
        assert(sz(rt) == n);
    } else {
        assert(fd != -1);
        assert(fdc != -1);
        for (int v : rt) {
            assert(v != fd);
            assert(v != fdc);
            // ops.emplace_back(fd,fdc,v);
            ops.push_back({fd,fdc,v});
            fdc = v;
        }
    }
    ans(ops);
}