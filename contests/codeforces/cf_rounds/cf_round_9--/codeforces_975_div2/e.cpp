/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Sep 27 20:08:34 IST 2024
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
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dps(n,-1);
    vector<vector<int>> mp(n+1);
    vector<int> cdct(n,0), pr(n,-1);
    int mn = n;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        if (p == -1) {
            dps[u] = 1;
            cdct[u] = sz(g[u]);
            pr[u] = -1;
        }
        else {
            dps[u] = dps[p]+1;
            cdct[u] = sz(g[u])-1;
            pr[u] = p;
        }
        if (p != -1 && sz(g[u]) == 1) {
            assert(dps[u] != -1);
            assert(dps[u] < sz(mp));
            mp[dps[u]].push_back(u);
            mn = min(mn,dps[u]);
        }
        for (int v : g[u]) {
            if (v == p) continue;
            else self(self,v,u);
        }
    };
    dfs(dfs,0,-1);
    sort(all(dps));
    int sol;
    {
        auto it = lower_bound(all(dps),mn+1);
        if (it == dps.end()) sol = 0;
        else sol = n - int(it-dps.begin());
    }
    vector<bool> del(n,false);
    int cur = 0;
    rep(d,dps.back()-1,1,-1) {
        for (int u : mp[d]) {
            while(!del[u] && cdct[u] == 0) {
                assert(u != 0);
                del[u] = true;
                cur++;
                cdct[pr[u]]--;
                u = pr[u];
            }
        }
    }
    assert(cur == int(count(all(del),true)));
    debug(sol,cur);
    sol = min(cur,sol);
    auto add = [&](int d) -> void {
        for (int u : mp[d]) {
            if (!del[u]) continue;
            while(del[u]) {
                assert(u != 0);
                cur--;
                del[u] = false;
                u = pr[u];
            }
        }
        // assert(cur == int(count(all(del),true)));
    };
    auto get = [&](int d) -> int {
        auto it = lower_bound(all(dps),d);
        if (it == dps.end()) return 0;
        return n-int(it-dps.begin());
    };
    rep(d,dps.back()-1,1,-1) {
        debug(endl,d,mp[d]);
        add(d);
        debug(cur);
        cur += get(d+1);
        debug(cur);
        sol = min(sol,cur);
        cur -= get(d+1);
    }
    cout << sol << endl;
}