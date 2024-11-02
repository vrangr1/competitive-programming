/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 18:18:11 IST 2024
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
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    // vector<ll> deg(n);
    rep(i,n-1ll) {
        ll u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    ll sol = 0ll;
    debug(g[3]);
    auto dfs = [&](auto &&self, ll u, ll p) -> ll {
        ll ct = 0ll, oct = 0;
        // vector<ll> rem;
        for (ll &v : g[u]) {
            if (v == p) continue;
            ll cur = self(self,v,u);
            if (sz(g[v]) == 2) oct++;
            if (sz(g[u]) == 3) {
                debug(endl,u,v,ct,cur);
                sol += ct*cur;
            }
            // rem.push_back(cur);
            ct+=cur;
        }
        if (sz(g[u]) == 2) {
            debug(endl,u,sz(g[u]),ct);
            sol += ct-oct;
            return 1ll;
        }
        if (sz(g[u]) == 3) {
            return ct;
        }
        return 0ll;
    };
    dfs(dfs,0,-1ll);
    cout << sol << endl;
}