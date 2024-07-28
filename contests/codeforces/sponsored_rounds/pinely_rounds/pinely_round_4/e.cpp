/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 28 21:33:19 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
#include <stdlib.h>
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n, m; cin >> n;
    if (n == -1) exit(0);
    cin >> m;
    vector<vector<ll>> g(n+1);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> color(n+1,-1);
    auto two_color = [&]() -> bool {
        auto dfs = [&](auto &&self, ll u, ll p) -> bool {
            assert(color[u] != -1);
            for (ll &v : g[u]) {
                if (v == p) continue;
                if (color[v] != -1 && color[v] == color[u]) return false;
                if (color[v] != -1) continue;
                color[v] = 3-color[u];
                if (!self(self,v,u)) return false;
            }
            return true;
        };
        color[1] = 1;
        bool can_color = dfs(dfs,1,-1);
        return can_color;
    };
    bool can_color = two_color();
    auto get_alice = [&]() -> pair<ll,ll> {
        ll a, b; cin >> a;
        if (a == -1) exit(0);
        cin >> b;
        return {a,b};
    };
    auto get_bob = [&]() -> pair<ll,ll> {
        ll u, c; cin >> u;
        if (u == -1) exit(0);
        cin >> c;
        return {u,c};
    };
    auto put_alice = [&](ll a, ll b) -> void {
        cout << a << " " << b << endl;
        cout.flush();
    };
    auto put_bob = [&](ll u, ll c) -> void {
        cout << u << " " << c << endl;
        cout.flush();
    };
    if (!can_color) {
        cout << "Alice\n";
        cout.flush();
        rep(i,n) {
            put_alice(1,2);
            get_bob();
        }
        return;
    }
    cout << "Bob\n";
    cout.flush();
    vector<vector<ll>> vs(3);
    rep(i,1,n,1) vs[color[i]].push_back(i);
    auto trycolor = [&](ll c, ll p = -1) -> bool {
        if (p == -1) p = c;
        assert(c >= 1 && c <= 2);
        if (vs[c].empty()) return false;
        put_bob(vs[c].back(),p);
        vs[c].pop_back();
        return true;
    };
    rep(i,n) {
        auto [c1,c2] = get_alice();
        if (c1 + c2 == 3) {
            if (trycolor(c1)) continue;
            assert(trycolor(c2));
            continue;
        }
        if (c1 == 3) {
            if (trycolor(c2)) continue;
            c1 = 3-c2;
            assert(c1 >= 1 && c1 <= 2);
            assert(trycolor(c1,3));
            continue;
        }
        assert(c2 == 3);
        assert(c1 >= 1 && c1 <= 2);
        if (trycolor(c1)) continue;
        c2 = 3-c1;
        assert(trycolor(c2,3));
    }
}