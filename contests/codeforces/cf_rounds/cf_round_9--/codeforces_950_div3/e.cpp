/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jun  3 21:00:12 IST 2024
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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m)), b(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    rep(i,n) rep(j,m) cin >> b[i][j];
    set<vector<int>> ra, rb, ca, cb;
    rep(r,n) {
        vector<int> ta = a[r], tb = b[r];
        sort(all(ta));
        sort(all(tb));
        ra.insert(ta);
        rb.insert(tb);
    }
    if (ra != rb) return void(cout << no);
    rep(c,m) {
        vector<int> ta, tb;
        rep(r,n) {
            ta.push_back(a[r][c]);
            tb.push_back(b[r][c]);
        }
        sort(all(ta));
        sort(all(tb));
        ca.insert(ta);
        cb.insert(tb);
    }
    if (ca != cb) return void(cout << no);
    cout << yes;
}