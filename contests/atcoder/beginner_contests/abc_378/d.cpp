/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 17:39:17 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
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

const vector<ll> dx = {1,-1,0,0};
const vector<ll> dy = {0,0,-1,1};


void solve() {
    ll h, w, k; cin >> h >> w >> k;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    ll sol = 0ll;
    auto valid = [&](ll x, ll y) -> bool {
        return x >= 0 && x < h && y >= 0 && y < w;
    };
    auto ct = [&](auto &&self, ll i, ll j, auto &vis, ll m) -> void {
        debug(i,j);
        if (m == k) {
            debug('I');
            sol++;
            return;
        }
        assert(m < k);
        rep(d,4) {
            ll x = i+dx[d], y = j+dy[d];
            if (!valid(x,y) || vis[x][y] || g[x][y] == '#') continue;
            vis[x][y] = true;
            self(self,x,y,vis,m+1);
            vis[x][y] = false;
        }
    };
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    rep(i,h)
        rep(j,w) {
            if (g[i][j] == '#') continue;
            debug(endl,i,j);
            vis[i][j] = true;
            ct(ct,i,j,vis,0);
            vis[i][j] = false;
            debug('F',endl);
        }
    cout << sol << endl;
}