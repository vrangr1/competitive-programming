/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jun 25 21:03:03 IST 2024
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
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    vector<string> wsnow(n);
    rep(i,n) cin >> wsnow[i];
    ll ssum = 0ll, wssum = 0;
    vector<vector<vector<ll>>> sums(n,vector<vector<ll>>(m,vector<ll>(2,0ll)));
    rep(i,n) {
        rep(j,m) {
            int ws = wsnow[i][j]-'0';
            if (ws) wssum += a[i][j];
            else ssum += a[i][j];
            if (!i && !j) {
                sums[i][j][ws] = 1ll;
                continue;
            }
            if (!i) {
                sums[i][j][ws] = sums[i][j-1][ws] + 1ll;
                sums[i][j][1-ws] = sums[i][j-1][1-ws];
                continue;
            }
            if (!j) {
                sums[i][j][ws] = sums[i-1][j][ws] + 1ll;
                sums[i][j][1-ws] = sums[i-1][j][1-ws];
                continue;
            }
            sums[i][j][ws] = sums[i][j-1][ws] + sums[i-1][j][ws] - sums[i-1][j-1][ws] + 1ll;
            sums[i][j][1-ws] = sums[i][j-1][1-ws] + sums[i-1][j][1-ws] - sums[i-1][j-1][1-ws];
        }
    }
    debug(a,wsnow,sums,ssum,wssum);
    ll d = llabs(ssum-wssum);
    if (d == 0ll) return void(cout << yes);
    ll g = 0ll;
    auto get = [&sums,k](ll i, ll j) -> ll {
        assert(i >= k-1ll && j >= k-1ll);
        if (i == k-1ll && j == k-1ll) return llabs(sums[i][j][0]-sums[i][j][1]);
        ll cs = 0, cws = 0ll;
        if (i == k-1ll) {
            cs = sums[i][j][0] - sums[i][j-k][0];
            cws = sums[i][j][1] - sums[i][j-k][1];
            return llabs(cws-cs);
        }
        if (j == k-1ll) {
            cs = sums[i][j][0] - sums[i-k][j][0];
            cws = sums[i][j][1] - sums[i-k][j][1];
            return llabs(cs-cws);
        }
        cs = sums[i][j][0] - sums[i-k][j][0] - sums[i][j-k][0] + sums[i-k][j-k][0];
        cws = sums[i][j][1] - sums[i-k][j][1] - sums[i][j-k][1] + sums[i-k][j-k][1];
        return llabs(cs-cws);
    };
    rep(i,k-1ll,n-1ll,1ll) {
        rep(j,k-1,m-1ll,1) {
            debug(endl,i,j,get(i,j));
            g = gcd(g,get(i,j));
        }
    }
    debug(d,g);
    if (g == 0ll) cout << no;
    else if (d%g) cout << no;
    else cout << yes;
}