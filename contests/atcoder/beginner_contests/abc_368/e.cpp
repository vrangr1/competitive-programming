/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 24 18:05:08 IST 2024
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
    vector<ll> x(m,0ll); cin >> x[0];
    vector<vector<array<ll,4>>> go(n), rec(n); // {src/dest, s, t, index}
    vector<array<ll,4>> trs;
    vector<vector<ll>> g(m);
    rep(i,m) {
        ll a, b, s, t; cin >> a >> b >> s >> t;
        --a;--b;
        go[a].push_back({b,s,t,i});
        rec[b].push_back({a,s,t,i});
        trs.push_back({a,b,s,t});
    }
    rep(i,n) {
        sort(all(go[i]),[&](const array<ll,4> &a, const array<ll,4> &b) {
            auto &[ab,as,at,ai] = a;
            auto &[bb,bs,bt,bi] = b;
            return as < bs;
        });
        sort(all(rec[i]),[&](const array<ll,4> &a, const array<ll,4> &b) {
            auto &[ab,as,at,ai] = a;
            auto &[bb,bs,bt,bi] = b;
            return at < bt;
        });
    }
    vector<ll> tsorder;
    vector<bool> vis(m,false);
    auto ts = [&](auto &&self, ll i) -> void {
        vis[i] = true;
        auto it = lower_bound(all(go[trs[i][1]]), array<ll,4>(0,trs[i][2],trs[i][3],0), [&](const array<ll,4> &a, const array<ll,4> &b) {
            auto &[ab,as,at,ai] = a;
            auto &[bb,bs,bt,bi] = b;
            return as < bs;
        });
        for (;it!= go[trs[i][1]].end();++it) {
            auto [b,s,t,j] = *it;
            if (trs[i][3] > s || vis[j]) continue;
            debug(i,j);
            self(self,j);
        }
        tsorder.push_back(i);
    };
    // rep(i,m-1,0ll,-1) {
    rep(i,m) {
        if (vis[i]) continue;
        ts(ts,i);
    }
    debug(tsorder);
    reverse(all(tsorder));
    debug(tsorder);
    for (ll i : tsorder) {
        auto [a,b,s,t] = trs[i];
        auto it = lower_bound(all(rec[a]),array<ll,4>(0,s,t,0), [&](const array<ll,4> &a1, const array<ll,4> &b1) {
            auto &[ab,as,at,ai] = a1;
            auto &[bb,bs,bt,bi] = b1;
            return at < bt;
        });
        for (auto [a1,s1,t1,i1] : rec[a]) {
            if (t1 > s) continue;
            x[i] = max(x[i],x[i1]+t1-s);
        }
    }
    // return;
    // auto dfs = [&](auto &&self, ll i) -> void {
    //     auto [a,b,s,t] = trs[i];
    //     for (auto [b1,s1,t1,i1] : go[b]) {
    //         if (t > s1) continue;
    //         ll cur = x[i1];
    //         x[i1] = max(x[i1],(ll)(x[i]+t-s1));
    //         if (cur != x[i1]) self(self, i1);
    //     }
    // };
    // dfs(dfs,0);
    rep(i,1,m-1ll,1) cout << x[i] << " \n"[i==m-1];
}