/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Oct  2 20:36:59 IST 2024
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
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    if (n%2 || n >= 4) cout << "0\n";
    else cout << "1\n";
    if (n == 2) return void(cout << "1 2 1\n");
    auto ans = [&](int u, int v, int x) -> void {
        cout << u+1 << " " << v+1 << " " << x << endl;
    };
    if (n%2) {
        auto dfs = [&](auto &&self, int u, int p) -> void {
            for (int v : g[u]) {
                if (v == p) continue;
                self(self,v,u);
                ans(u,v,v);
            }
        };
        return dfs(dfs,0,-1);
    }
    vector<int> subsize(n,-1);
    auto sizecal = [&](auto &&self, int u, int p) -> int {
        int &ct = subsize[u];
        ct = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            int cs = self(self,v,u);
            ct += cs;
        }
        return ct;
    };
    sizecal(sizecal,0,-1);
    bool done = false;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (int v : g[u]) {
            if (v == p) continue;
            if (!done && subsize[v] == 3) {
                ans(u,v,v);
            }
            self(self,v,u);
        }
    };
}
