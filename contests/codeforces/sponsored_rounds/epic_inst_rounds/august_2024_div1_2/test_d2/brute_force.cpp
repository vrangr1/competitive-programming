/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 13 15:29:01 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n+1);
    vector<int> pr(n+1,-1);
    rep(i,2,n,1) {
        int p; cin >> p;
        g[p].push_back(i);
        pr[i] = p;
    }
    vector<int> nsz(n+1,1);
    auto dfs = [&] (auto &&self, int u, int p) -> void {
        for (int &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
            nsz[u] += nsz[v];
        }
    };
    dfs(dfs,1,-1);
    vector<int> p(n+1), pind(n+1);
    rep(i,1,n,1) {
        cin >> p[i];
        pind[p[i]] = i; 
    }
    vector<bool> ok(n+1,false);
    int sum = 0;
    auto upd = [&](int u, bool cor) -> void {
        if (cor) {
            if (!ok[u]) sum++;
            ok[u] = true;
        } else {
            if (ok[u]) sum--;
            ok[u] = false;
        }
    };
    auto check = [&](int u) -> void {
        if (u == -1) return;
        // int uind = pind[u];
        // if (g[u].empty()) {
        //     upd(u,true);
        //     if (u == 1) return void(upd(u,true));
        //     if (uind >= pind[pr[u]]+1 && uind < pind[pr[u]]+nsz[pr[u]]) upd(pr[u],true);
        //     else upd(pr[u],false);
        //     return;
        // }
        // if (uind == n) return void(upd(u,false));
        // if (pr[p[uind+1]] == u) upd(u,true);
        // else upd(u,false);
        vector<int> inds;
        int uind = pind[u];
        for (int &v : g[u])
            inds.push_back(pind[v]);
        if (inds.empty()) return void(upd(u,true));
        sort(all(inds));
        // if (inds.back() < uind+nsz[u] && inds.front() == uind+1) upd(u,true);
        // else upd(u,false);
        int cur = uind+1;
        for (int &i : inds)
            if (i != cur) return void(upd(u,false));
            else cur += nsz[p[i]];
        upd(u,true);
    };
    rep(i,1,n,1) check(i);
    debug(ok,nsz);
    while(q--) {
        int x, y; cin >> x >> y;
        swap(p[x],p[y]);
        pind[p[x]] = x;
        pind[p[y]] = y;
        check(p[x]);
        check(p[y]);
        check(pr[p[x]]);
        check(pr[p[y]]);
        debug(endl,ok);
        if (sum == n) cout << "YES\n";
        else cout << "NO\n";
    }
}