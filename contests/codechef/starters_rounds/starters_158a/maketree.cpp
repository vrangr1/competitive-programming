/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Oct 30 20:23:41 IST 2024
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

void solve1() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    int root = -1, mnd = INT_MAX;
    auto fd = [&](auto &&self, int u, int p) -> int {
        int d = 1;
        for (int &v : g[u]) {
            if (v == p) continue;
            d = max(d,self(self,v,u)+1);
        }
        return d;
    };
    rep(i,n) {
        int d = fd(fd,i,-1);
        if (d < mnd) {
            mnd = d;
            root = i;
        }
    }
    assert(root != -1);
    vector<vector<int>> sol;
    int ct = 0;
    // auto dfs = [&](auto &&self, int u, int p, bool last = false) -> void {

    // };
    while(ct != n-1) {

    }
}

void solve2() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<pair<vector<int>,int>> sol,oth;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (int &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
        }
        if (p == -1) return;
        assert(u >= 0 && u < n && p >= 0 && p < n);
        bool done = false;
        for (auto &[vec,cur] : sol) {
            assert(sz(vec) == n);
            if (vec[u] != -1 || vec[p] != -1) continue;
            vec[u] = vec[p] = cur++;
            done = true;
            break;
        }
        if (!done) {
            vector<int> vec(n,-1);
            int cur = 1;
            vec[u] = vec[p] = cur++;
            sol.emplace_back(vec,cur);
        }
    };
    dfs(dfs,0,-1);
    rep(i,1,n-1,1) {
        swap(sol,oth);
        dfs(dfs,i,-1);
        if (sz(oth) > sz(sol)) swap(sol,oth);
    }
    swap(sol,oth);
    for (auto &[vec,cur] : sol) {
        for (int & v : vec)
            if (v == -1) v = cur++;
        assert(cur <= n+1);
    }
    cout << sz(sol) << endl;
    for (auto &[vec,cur] : sol)
        print_vec(vec);
}

