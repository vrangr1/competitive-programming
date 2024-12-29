/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Dec 28 22:06:31 IST 2024
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
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    ll lc = 0, nlc = 0;
    rep(i,n) {
        if (sz(g[i]) == 1) lc++;
        else nlc++;
    }
    ll sol = lc*nlc;
    debug(sol);
    vector<ll> dist(n,LLONG_MAX);
    auto dfs = [&](auto &&self, ll u, ll p, ll cur) -> void {
        for (const ll &v : g[u]) {
            if (v == p) continue;
            self(self,v,u,min(cur+1ll,(ll)INT_MAX));
            dist[u] = min({dist[u],dist[v]+1ll,cur});
        }
        if (sz(g[u]) == 1) dist[u] = 0;
    };
    dfs(dfs,0,-1ll,(sz(g[0])==1?0ll:INT_MAX));
    debug(dist);
    vector<ll> d1(n,0ll), d2(n, 0ll);
    auto dfs2 = [&](auto &&self, ll u, ll p) -> void {
        for (const ll &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
            d1[u] += d1[v];
            d2[u] += d2[v];
            if (dist[v] == 1) {
                d1[u]++;
            } else if (dist[v] >= 2) {
                d2[u]++;
                d1[u]++;
            }
        }
    };
    dfs2(dfs2,0,-1);
    debug(d1,d2);
    auto dfs3 = [&](auto &&self, ll u, ll p, ll pd1, ll pd2) -> void {
        ll cd1 = 0, cd2 = 0;
        if (dist[u] == 1) cd1++;
        else if (dist[u] >= 2) {
            cd1++;
            cd2++;
        }
        d1[u] += pd1-cd1;
        d2[u] += pd2-cd2;
        for (const ll &v : g[u]) {
            if (v == p) continue;
            self(self,v, u, d1[u]-d1[v]+cd1, d2[u]-d2[v]+cd2);
        }
    };
    ll zd1 = 0, zd2 = 0;
    if (dist[0] == 1) zd1++;
    else if (dist[0] >= 2) {
        zd1++;
        zd2++;
    }
    dfs3(dfs3,0,-1,zd1,zd2);
    debug(d1,d2);
    auto dfs4 = [&](auto &&self, ll u, ll p) -> void {
        ll sd1 = 0, sd2 = 0;
        for (const ll &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
            sd1 += (dist[v] >= 1);
            sd2 += d2[v];
        }
        if (dist[u] != 1) return;
        ll cur = 0;
        for (const ll &v : g[u]) {
            if (v == p) continue;
            // ll cur = (sd2-d2[v]);
            cur += ll(dist[v] >= 1ll)*(sd2-d2[v]) + (sd1-ll(dist[v]>=1ll))*d2[v];
            // debug(u,v,cur);
            // sol += cur;
        }
        sol += cur/2ll;
    };
    dfs4(dfs4,0,-1);
    cout << sol << endl;
}