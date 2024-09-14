/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 14 21:18:03 IST 2024
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
    int l, n, m; cin >> l >> n >> m;
    vector<int> a(l);
    rep(i,l) cin >> a[i];
    vector<vector<int>> b(n,vector<int>(m)), stat(n,vector<int>(m,0));
    int cur = 0;
    rep(i,n) rep(j,m) {
        cin >> b[i][j];
        if (b[i][j] == a.back()) {
            stat[i][j] = 1;
            cur = 1;
        }
    }
    rep(i,l-2,0,-1) {
        int v = a[i];
        vector<vector<int>> nxt(n,vector<int>(m,0)), mx(n,vector<int>(m,0));
        cur = 0;
        rep(j,n-1,0,-1) {
            rep(k,m-1,0,-1) {
                // if (j != n-1) mx[j][k] = max(mx[j][k],mx[j+1][k]);
                // if (k != m-1) mx[j][k] = max(mx[j][k],mx[j][k+1]);
                if (j != n-1 && k != m-1) mx[j][k] = max(mx[j][k],mx[j+1][k+1]);
                if (b[j][k] != v) {
                    mx[j][k] = max(mx[j][k],stat[j][k]);
                    if (j != n-1) mx[j][k] = max(mx[j][k],mx[j+1][k]);
                    if (k != m-1) mx[j][k] = max(mx[j][k],mx[j][k+1]);
                    continue;
                }
                if (mx[j][k] == 0) {
                    nxt[j][k] = 1;
                    cur = 1;
                    mx[j][k] = max(mx[j][k],stat[j][k]);
                    if (j != n-1) mx[j][k] = max(mx[j][k],mx[j+1][k]);
                    if (k != m-1) mx[j][k] = max(mx[j][k],mx[j][k+1]);
                    continue;
                }
                mx[j][k] = max(mx[j][k],stat[j][k]);
                if (j != n-1) mx[j][k] = max(mx[j][k],mx[j+1][k]);
                if (k != m-1) mx[j][k] = max(mx[j][k],mx[j][k+1]);
            }
        }
        swap(nxt,stat);
    }
    if (cur) cout << "T\n";
    else cout << "N\n";
}

void solve1() {
    int l, n, m; cin >> l >> n >> m;
    vector<int> a(l);
    rep(i,l) cin >> a[i];
    vector<vector<int>> b(n,vector<int>(m)), stat(n,vector<int>(m,0));
    rep(i,n) rep(j,m) cin >> b[i][j];
    rep(i,l) {
        debug(endl,i,a[i],stat);
        vector<vector<int>> mx(n,vector<int>(m,0)), nxt(n,vector<int>(m,0));
        bool found = false;
        rep(j,n) {
            rep(k,m) {
                if (i == 0) {
                    if (b[j][k] != a[i]) continue;
                    nxt[j][k] = 1;
                    found = true;
                    continue;
                }
                int &cmx = mx[j][k];
                if (j && k) cmx = max(cmx,mx[j-1][k-1]);
                // if (k) cmx = max(cmx,mx[j][k-1]);
                if (b[j][k] != a[i]) {
                    cmx = max(cmx,stat[j][k]);
                    if (j) cmx = max(cmx,mx[j-1][k]);
                    if (k) cmx = max(cmx,mx[j][k-1]);
                    continue;
                }
                if (cmx) {
                    nxt[j][k] = 1;
                    found = true;
                    cmx = max(cmx,stat[j][k]);
                    if (j) cmx = max(cmx,mx[j-1][k]);
                    if (k) cmx = max(cmx,mx[j][k-1]);
                    continue;
                }
                cmx = max(cmx,stat[j][k]);
                if (j) cmx = max(cmx,mx[j-1][k]);
                if (k) cmx = max(cmx,mx[j][k-1]);
            }
        }
        if (!found) {
            if (i%2) cout << "T\n";
            else cout << "N\n";
            return;
        }
        swap(nxt,stat);
    }
    if (l%2) cout << "T\n";
    else cout << "N\n";
}