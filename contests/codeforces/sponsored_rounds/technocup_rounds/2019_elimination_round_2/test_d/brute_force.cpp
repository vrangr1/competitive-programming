/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Aug 23 00:01:59 IST 2024
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
    int n, k; cin >> n >> k;
    k = min(k,2*n-1);
    string sol;
    vector<string> g(n);
    rep(i,n) cin >> g[i];
    vector<vector<vector<string>>> dp(n,vector<vector<string>>(n,vector<string>(k+1)));
    auto rec = [&](auto &&self, int i, int j, int r) -> void {
        if (!dp[i][j][r].empty()) return;
        if (i == n-1 && j == n-1) {
            if (r) dp[i][j][r] = "a";
            else dp[i][j][r] = g[i][j];
            return;
        }
        if (i == n-1) {
            if (r && g[i][j] != 'a') {
                self(self,i,j+1,r-1);
                dp[i][j][r] = "a"+dp[i][j+1][r-1];
            }
            else {
                self(self,i,j+1,r);
                dp[i][j][r] = g[i][j]+dp[i][j+1][r];
            }
            return;
        }
        if (j == n-1) {
            if (r && g[i][j] != 'a') {
                self(self,i+1,j,r-1);
                dp[i][j][r] = "a" + dp[i+1][j][r-1];
            }
            else {
                self(self,i+1,j,r);
                dp[i][j][r] = g[i][j] + dp[i+1][j][r];
            }
            return;
        }
        if (r && g[i][j] != 'a') {
            self(self,i,j+1,r-1);
            self(self,i+1,j,r-1);
            dp[i][j][r] = min("a"+dp[i][j+1][r-1],"a"+dp[i+1][j][r-1]);
        }
        else {
            self(self,i,j+1,r);
            self(self,i+1,j,r);
            dp[i][j][r] = min(g[i][j]+dp[i][j+1][r],g[i][j]+dp[i+1][j][r]);
        }
    };
    rec(rec,0,0,k);
    debug(dp);
    cout << dp[0][0][k] << endl;
}