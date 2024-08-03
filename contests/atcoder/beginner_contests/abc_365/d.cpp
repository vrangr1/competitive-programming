/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug  3 17:41:19 IST 2024
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
    auto get = [&](char ch) -> char {
        switch(ch) {
            case 'R': return 'P';
            case 'P': return 'S';
            default: return 'R';
        }
        assert(false);
    };
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n,vector<int>(2,0));
    int sol = 1;
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1) {
            dp[i][1] = 1;
            dp[i][0] = 0;
            continue;
        }
        char cw = get(s[i]), nw = get(s[i+1]);
        if (cw == nw) {
            dp[i][1] = dp[i+1][0]+1;
            dp[i][0] = dp[i+1][1];
        }
        else {
            dp[i][1] = dp[i+1][1]+1;
            dp[i][0] = dp[i+1][0];
            if (cw != s[i+1]) dp[i][1] = max(dp[i][1],dp[i+1][0]+1);
            if (s[i] != nw) dp[i][0] = max(dp[i][0], dp[i+1][1]);
        }
    }
    sol = max(dp[0][0],dp[0][1]);
    cout << sol << endl;
}