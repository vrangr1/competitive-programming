/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 31 18:31:22 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n,vector<ll>(n,LLONG_MAX));
    vector<tuple<ll,ll,ll>> bg(m);
    rep(i,m) {
        ll u, v, t; cin >> u >> v >> t;
        --u;--v;
        bg[i] = {u,v,t};
        adj[u][v] = adj[v][u] = min(adj[u][v],t);
    }
    rep(i,n) adj[i][i] = 0ll;
    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                if (adj[i][k] == LLONG_MAX || adj[k][j] == LLONG_MAX) continue;
                adj[j][i] = adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    debug(adj);
    ll q; cin >> q;
    auto comp = [&](auto &&self, auto &b, ll cur, ll i) -> ll {
        ll k = sz(b);
        if (i == k) return adj[cur][n-1ll];
        assert(i < k);
        ll ind = b[i];
        assert(ind < m);
        auto [u,v,t] = bg[ind];
        assert(u < n);
        assert(v < n);
        return min(t + adj[cur][u] + self(self,b,v,i+1ll), t + adj[cur][v] + self(self,b,u,i+1ll));
    };
    while(q--) {
        ll k; cin >> k;
        vector<ll> b(k);
        rep(i,k) {
            cin >> b[i];
            --b[i];
        }
        sort(all(b));
        ll sol = LLONG_MAX;
        do {
            sol = min(sol,comp(comp,b,0ll,0ll));
        } while(next_permutation(all(b)));
        cout << sol << endl;
    }
}