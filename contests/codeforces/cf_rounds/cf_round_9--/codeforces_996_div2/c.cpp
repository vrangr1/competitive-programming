/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Jan 12 20:13:03 IST 2025
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
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    vector<ll> rows(n,0), cols(m,0);
    rep(i,n) rep(j,m) {
        rows[i] += a[i][j];
        cols[j] += a[i][j];
    }
    ll x = 0, y = 0;
    rep(i,sz(s)) {
        ll dx, dy;
        switch(s[i]) {
            case 'D':
                dx = 1;
                dy = 0;
                break;
            default:
                dx = 0;
                dy = 1;
                break;
        }
        if (dx) {
            a[x][y] = -rows[x];
        } else {
            a[x][y] = -cols[y];
        }
        rows[x] += a[x][y];
        cols[y] += a[x][y];
        x+=dx;
        y+=dy;
        if (i == sz(s)-1) {
            if (dx) a[x][y] = -rows[x];
            else a[x][y] = -cols[y];
        }
    }
    rep(i,n) print_vec(a[i]);
}