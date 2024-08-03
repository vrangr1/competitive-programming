/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug  3 13:01:01 IST 2024
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

class segtree {
public:
    ll n;
    vector<ll> tree, inds, h;
    segtree(vector<ll> &et, vector<ll> &ht, vector<ll> &fst) {
        n = sz(et);
        inds = fst;
        h = ht;
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        tree.assign(gn,-1);
        rep(i,n)
            tree[i+n] = et[i];
        rep(i,n-1,1ll,-1) {
            if (h[tree[i<<1ll]] <= h[tree[i<<1ll|1ll]])
                tree[i] = tree[i<<1ll];
            else tree[i] = tree[i<<1ll|1ll];
        }
    }

    ll query(ll l, ll r) {
        ll res = (h[tree[l+n]] <= h[tree[r+n]]?tree[l+n]:tree[r+n]);
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                if (h[res] >= h[tree[l]])
                    res = tree[l];
                l++;
            }
            if (r&1ll) {
                --r;
                if (h[res] >= h[tree[r]])
                    res = tree[r];
            }
        }
        return res;
    }

    ll lca(ll u, ll v) {
        ll l = inds[u], r = inds[v];
        return query(min(l,r),max(l,r));
    }
};

void solve() {
    ll n, m, k, s, t; cin >> n >> m >> k >> s >> t;
    --s; --t;
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,n-1ll) {
        ll u, v, w; cin >> u >> v >> w;
        --u;--v;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<ll> dist(n,LLONG_MAX);
    vector<ll> et, fst(n,-1), h(n);
    auto dfs = [&](auto &&self, ll u, ll p, ll cost, ll ht) -> void {
        assert(fst[u] == -1);
        fst[u] = sz(et);
        h[u] = ht;
        et.push_back(u);
        dist[u] = cost;
        for (auto &[v, w] : g[u]) {
            if (v == p) continue;
            self(self,v,u,cost+w,ht+1);
            et.push_back(u);
        }
    };
    dfs(dfs,s,-1,0,0);
    debug(s,t,m,k,et,fst,h);
    if (dist[t] >= k || m >= (((n-1ll)*n) - 2ll*(n-1ll))) return void(cout << dist[t] << endl);
    segtree seg(et, h, fst);
    set<ll> sadj, tadj;
    for (auto &[v,_] : g[s]) sadj.insert(v);
    for (auto &[v,_] : g[t]) tadj.insert(v);
    auto get_dist = [&](ll u, ll v) -> ll {
        ll lca = seg.lca(u,v);
        assert(lca >= 0ll);
        assert(lca < n);
        if (lca == u)
            return dist[v]-dist[u];
        if (lca == v) return dist[u]-dist[v];
        return dist[v]+dist[u]-2ll*dist[lca];
    };
    vector<ll> pos;
    if (sadj.find(t) == sadj.end()) pos.push_back(k);
    auto dfs2 = [&](auto &&self, ll u, ll p, ll d) -> void {
        if (d >= dist[t]-k) return;
        
        for (auto &[v,w] : g[u]) {
            if (v == p) continue;
            if (d+w >= dist[t]-k) continue;
            
        }
    };



    set<pair<ll,ll>> seen;
    seen.emplace(s,t);
    rep(i,n) {
        if (i == s || i == t) continue;
        if (i != s && sadj.find(i) == sadj.end()) { // s ~> i -> t
            debug(endl,i,get_dist(i,t)+k);
            assert(seen.find({s,i}) == seen.end());
            seen.emplace(s,i);
            pos.push_back(get_dist(i,t)+k);
        }
        if (i!=t && tadj.find(i) == tadj.end()) { // s -> i ~> t
            debug(endl,i,get_dist(s,i)+k);
            assert(seen.find({i,t}) == seen.end());
            seen.emplace(i,t);
            pos.push_back(k+get_dist(s,i));
        }
    }
    sort(all(pos));
    debug(dist,pos);
    if (sz(pos) <= m) return void(cout << dist[t] << endl);
    rep(i,m) {
        if (dist[t] <= pos[i]) {
            cout << dist[t] << endl;
            return;
        }
    }
    cout << min(dist[t],pos[m]) << endl;
}