/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jun 21 19:20:09 IST 2024
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
    vector<vector<ll>> g(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        if (u == v) continue;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<bool> vis(n,false);
    auto dijk = [&]() {
        auto comp = [](const tuple<ll,ll,ll> &a, const tuple<ll,ll,ll> &b) -> bool {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            return get<1>(a) > get<1>(b);
        };
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, decltype(comp)> pq(comp);
        pq.emplace(c[0],0,0);
        ll solv = LLONG_MIN, solm = LLONG_MAX;
        while(!pq.empty()) {
            auto [val, moves, u] = pq.top();
            pq.pop();
            vis[u] = true;
            if (u == n-1ll) {
                if (solv > val) {
                    cout << solv << " " << solm << endl;
                    return;
                }
                assert(solv == LLONG_MIN || solv == val);
                solv = val;
                solm = min(moves,solm);
                continue;
            }
            for (const ll &v : g[u]) {
                if (vis[v]) continue;
                pq.emplace(gcd(val,c[v]),moves+1,v);
            }
        }
        assert(vis[n-1]);
        assert(solv != LLONG_MIN);
        assert(solm != LLONG_MAX);
        cout << solv << " " << solm << endl;
    };
    dijk();
}