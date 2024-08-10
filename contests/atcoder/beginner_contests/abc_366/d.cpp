/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug 10 17:45:49 IST 2024
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
    ll n; cin >> n;
    vector<vector<vector<ll>>> a(n,vector<vector<ll>>(n,vector<ll>(n))), s(n,vector<vector<ll>>(n,vector<ll>(n,0ll)));
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                cin >> a[i][j][k];
                s[i][j][k] = a[i][j][k];
                if (!i && !j && !k) {
                    continue;
                }
                if (!i && !j) {
                    s[i][j][k] += s[i][j][k-1];
                    continue;
                }
                if (!i && !k) {
                    s[i][j][k] += s[i][j-1][k];
                    continue;
                }
                if (!j && !k) {
                    s[i][j][k] += s[i-1][j][k];
                    continue;
                }
                if (!i) {
                    s[i][j][k] += s[i][j-1][k] + s[i][j][k-1] - s[i][j-1][k-1];
                    continue;
                }
                if (!j) {
                    s[i][j][k] += s[i-1][j][k] + s[i][j][k-1] - s[i-1][j][k-1];
                    continue;
                }
                if (!k) {
                    s[i][j][k] += s[i-1][j][k] + s[i][j-1][k] - s[i-1][j-1][k];
                    continue;
                }
                s[i][j][k] += s[i-1][j][k] + s[i][j-1][k] - s[i-1][j-1][k];
                s[i][j][k] += s[i][j][k-1] - (s[i-1][j][k-1] + s[i][j-1][k-1] - s[i-1][j-1][k-1]);
            }
        }
    }
    ll q; cin >> q;
    while(q--) {
        ll lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; rx--; ly--; ry--; lz--; rz--;
        ll sol = s[rx][ry][rz];
        if (!lx && !ly && !lz) {
            cout << sol << endl;
            continue;
        }
        if (!lx && !ly) {
            cout << sol-s[rx][ry][lz-1] << endl;
            continue;
        }
        if (!lx && !lz) {
            cout << sol - s[rx][ly-1][rz] << endl;
            continue;
        }
        if (!ly && !lz) {
            cout << sol - s[lx-1][ry][rz] << endl;
            continue;
        }
        if (!lx) {
            sol -= s[rx][ly-1][rz] + s[rx][ry][lz-1] - s[rx][ly-1][lz-1];
            cout << sol << endl;
            continue;
        }
        if (!ly) {
            sol -= s[lx-1][ry][rz] + s[rx][ry][lz-1] - s[lx-1][ry][lz-1];
            cout << sol << endl;
            continue;
        }
        if (!lz) {
            sol -= s[lx-1][ry][rz] + s[rx][ly-1][rz] - s[lx-1][ly-1][rz];
            cout << sol << endl;
            continue;
        }
        sol -= s[lx-1][ry][rz] + s[rx][ly-1][rz] - s[lx-1][ly-1][rz];
        sol -= s[rx][ry][lz-1] - (s[lx-1][ry][lz-1] + s[rx][ly-1][lz-1] - s[lx-1][ly-1][lz-1]);
        cout << sol << endl;
    }
}