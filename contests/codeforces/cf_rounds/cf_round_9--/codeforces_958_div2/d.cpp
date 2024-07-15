/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jul 15 20:32:19 IST 2024
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

void solve1() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> g(n);
    rep(i,n-1ll) {
        ll u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    ll sol = LLONG_MAX;
    {
        ll cur = 0ll;
        auto dfs = [&](auto &&self, ll u, ll p, bool sel = true) -> void {
            if (sel) cur += a[u];
            for (ll &v : g[u]) {
                if (v == p) continue;
                self(self,v,u,!sel);
            }
        };
        dfs(dfs,0,-1);
        sol = cur;
        cur = 0ll;
        dfs(dfs,0,-1,false);
        sol = min(sol+2ll*cur,sol*2ll + cur);
    }
    ll sum = accumulate(all(a),0ll), cur = 0ll;
    vector<array<ll,2>> dp(n), sct(n);
    auto dfs =[&](auto &&self, ll u, ll p) -> void {
        sct[u][1] = 1ll;
        dp[u][1] = a[u];
        for (ll &v : g[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][1],dp[v][0]);
            sct[u][1] += sct[v][0];
            if (dp[v][1] == dp[v][0]) sct[u][0] = max(sct[v][0],sct[v][1]);
            else if (dp[v][1] > dp[v][0]) sct[u][0] = sct[v][1];
            else sct[u][0] = sct[v][0];
        }
    };
    auto cleanup = [&](auto &&self, ll u, ll p, bool sel) -> void {
        if (a[u] == 0ll) assert(!sel);
        if (sel) a[u] = 0;
        for (ll &v : g[u]) {
            if (v == p) continue;
            if (sel) self(self, v, u, !sel);
            else {
                if (a[v] == 0ll) self(self, v, u, false);
                else if (sct[v][1] < sct[v][0]) self(self,v, u, false);
                else self(self, v, u, true);
            }
        }
    };
    while(true) {
        cur += sum;
        if (cur >= sol) break;
        fill(all(dp),array<ll,2>{0,0});
        fill(all(sct),array<ll,2>{0,0});
        dfs(dfs,0,-1ll);
        // debug(dp,sct);
        sum -= max(dp[0][0],dp[0][1]);
        if (dp[0][0] > dp[0][1]) cleanup(cleanup,0,-1,false);
        else if (dp[0][0] < dp[0][1]) cleanup(cleanup,0,-1,true);
        else if (a[0] == 0ll) cleanup(cleanup,0,-1,false);
        else if (sct[0][1] >= sct[0][0]) cleanup(cleanup,0,-1,true);
        else cleanup(cleanup,0,-1,false);
        // if (accumulate(all(a),0ll) != sum) {
        //     debug('p');
        //     exit(0);
        // }
        // assert(accumulate(all(a),0ll) == sum);
        if (sum == 0ll) {
            break;
        }
    }
    cout << sol << endl;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> g(n);
    rep(i,n-1ll) {
        ll u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    const ll m = 20;
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    vector<ll> mns(m);
    auto dfs = [&](auto &&self, ll u, ll p) -> void {
        rep(i,(ll)m) dp[u][i] = (i+1ll)*a[u];
        for (ll &v : g[u]) {
            if (v == p) continue;
            self(self,v,u);
            ll mn = LLONG_MAX;
            mns.back() = LLONG_MAX;
            rep(i,m-2,0ll,-1)
                mns[i] = min(mns[i+1],dp[v][i+1ll]);
            rep(i,(ll)m) {
                dp[u][i] += min(mn,mns[i]);
                mn = min(mn,dp[v][i]);
            }
        }
    };
    dfs(dfs,0,-1);
    cout << *min_element(all(dp[0])) << endl;
}