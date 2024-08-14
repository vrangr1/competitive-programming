/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 13 20:32:53 IST 2024
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

/*



*/

void solve1() {
    ll n, m, k; cin >> n >> m >> k;
    ll w; cin >> w;
    vector<ll> a(w);
    rep(i,w) cin >> a[i];
    sort(rall(a));
    vector<vector<ll>> g(n,vector<ll>(m,0ll));
    vector<ll> col(n,0ll);
    rep(i,n-k+1ll) col[i]++;
    rep(i,k,n-1ll,1) col[i]--;
    rep(i,1,n-1ll,1) col[i]+=col[i-1ll];


    rep(i,n) {
        rep(j,m-k+1ll) g[i][j] += col[i];
    }
    rep(i,n)
        rep(j,k,m-1ll,1) g[i][j] -= col[i];
    
    
    vector<pair<ll,ll>> inds;
    rep(i,n)
        rep(j,m) {
            if (j) 
                g[i][j] += g[i][j-1];
            inds.emplace_back(i,j);
        }
    sort(rall(inds),[&](const pair<ll,ll> &i1, const pair<ll,ll> &i2) {
        auto [p,q] = i1;
        auto [l,r] = i2;
        return g[p][q] < g[l][r];
    });
    ll ind = 0, sol = 0ll;
    debug(a,g);
    for (auto [l,r] : inds) {
        if (ind == w || g[l][r] <= 0ll) break;
        // debug(l,r,g[l][r]);
        sol += g[l][r]*a[ind++];
    }
    cout << sol << endl;
}

// Shashwat's Solution
void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll w; cin >> w;
    vector<ll> a(w);
    rep(i,w) cin >> a[i];
    sort(rall(a));
    vector<vector<ll>> grid(n,vector<ll>(m,0ll));
    rep(i,n)
        rep(j,m) {
            // grid[i][j] = min({i+1,k,n-i})*min({j+1,k,m-j});
            ll ict = min(i+k-1ll,n-1ll) - max(i,k-1ll) + 1ll;
            ll jct = min(j+k-1ll,m-1ll) - max(j,k-1ll) + 1ll;
            grid[i][j] = ict*jct;
        }
    debug(grid);
    vector<pair<ll,ll>> inds;
    rep(i,n) rep(j,m) inds.emplace_back(i,j);
    sort(rall(inds),[&](const pair<ll,ll> &l, const pair<ll,ll> &r) {
        auto [l1, l2] = l;
        auto [r1, r2] = r;
        return grid[l1][l2] < grid[r1][r2];
    });
    ll sol = 0ll;
    rep(i,w){
        auto [l,r] = inds[i];
        sol += grid[l][r]*a[i];
    }
    cout << sol << endl;
}