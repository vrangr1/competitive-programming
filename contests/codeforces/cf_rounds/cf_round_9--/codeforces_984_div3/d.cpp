/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 20:17:17 IST 2024
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
    int n, m; cin >> n >> m;
    vector<string> g(n);
    rep(i,n)
        cin >> g[i];
    int sol = 0;
    auto add = [&](char a, char b, char c, char d) {
        // sol += (a == 1 && b == 5 && c == 4 && d == 3);
        sol += (a == '1' && b == '5' && c == '4' && d == '3');
    };
    rep(d,int(min(n/2,m/2))) {
        debug(d);
        string s;
        rep(j,d,m-d-1,1)
            s.push_back(g[d][j]);
        rep(i,d+1,n-d-1,1)
            s.push_back(g[i][m-d-1]);
        rep(j,m-d-2,d,-1)
            s.push_back(g[n-d-1][j]);
        rep(i,n-d-2,d+1,-1)
            s.push_back(g[i][d]);
        int k = sz(s);
        debug(s);
        rep(i,k) {
            add(s[i],s[(i+1)%k],s[(i+2)%k],s[(i+3)%k]);
        }
        // (d,d),     (d,m-d-1)
        // (n-d-1,d), (n-d-1,m-d-1)
        // rep(j,d,m-d-1-3,1) {
        //     int i = d;
        //     add(g[i][j],g[i][j+1],g[i][j+2],g[i][j+3]);
        //     i = n-d-1;
        //     add(g[i][j],g[i][j+1],g[i][j+2],g[i][j+3]);
        // }
        
        // rep(j,m-d-3,m-d-1,1) {
        //     int i = d;
        //     string vals;
        //     int left = m-d-1-j+1;
        //     rep(k,left)
        //         vals.push_back(g[i][j+k]);
        //     rep(k,1,4-left,1)
        //         vals.push_back(g[i+k][m-d-1]);
        //     assert(sz(vals)==4);
        //     add(vals[0],vals[1],vals[2],vals[3]);
        //     vals.clear();
        //     i = n-d-1;
        //     rep(k,4-left,1,-1)
        //         vals.push_back(g[i-k][m-d-1]);
        //     rep(k,left-1,0,-1)
        //         vals.push_back(g[i][j+k]);
        //     assert(sz(vals)==4);
        //     add(vals[0],vals[1],vals[2],vals[3]);
        // }
        // rep(j,d,d+2,1) {
        //     int i = d;
        //     int left = 4 - (j-d+1);
        //     string vals;
        //     rep(k,left,1,-1) {
        //         vals.push_back(g[i+k][d]);
        //     }
        //     rep(k,j-d+1)
        //         vals.push_back(g[i][d+k]);
        //     assert(sz(vals)==4);
        //     add(vals[0],vals[1],vals[2],vals[3]);
        //     vals.clear();
        //     i = n-d-1;
        //     rep(k,j-d,0,-1)
        //         vals.push_back(g[i][d+k]);
        //     rep(k,1,left,1)
        //         vals.push_back(g[i-k][d]);
        // }
        // rep(i,d,n-d-1-3,1) {
        //     int j = d;
        //     add(g[i+3][j],g[i+2][j],g[i+1][j],g[i][j]);
        //     j = m-d-1;
        //     add(g[i+3][j],g[i+2][j],g[i+1][j],g[i][j]);
        // }
    }
    cout << sol << endl;
}