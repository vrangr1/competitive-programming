/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 11 20:26:38 IST 2024
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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    assert(sz(s) == n);
    vector<int> dp(n+2, INT_MAX);
    dp[0] = 0;
    assert(m>=1);
    rep(i,1,n,1) {
        if (s[i-1] == 'C') continue;
        rep(j,i-2,i-m,-1) {
            if (j < 0) break;
            assert(j >= 0 && j <= n);
            assert(i-j <= m);
            if (j == 0 || s[j-1] == 'L')
                dp[i] = min(dp[i],dp[j]);
        }
        if (dp[i-1] > k) continue;
        if (i == 1 || (i > 1 && s[i-2] == 'L')) dp[i] = min(dp[i],dp[i-1]);
        else if (s[i-2] == 'C') continue;
        else {
            assert(i>=2);
            assert(s[i-2] == 'W');
            if (dp[i-1] < k)
            dp[i] = min(dp[i],dp[i-1]+1);
        }
    }
    rep(i,n,n-m+1,-1) {
        if (i < 0) break;
        else if (dp[i] == INT_MAX) continue;
        else if (i == 0 || s[i-1] == 'L')
            dp[n+1] = min(dp[n+1],dp[i]);
        else if (i == n && dp[i] <= k-1) {
            assert(s[i-1] == 'W');
            dp[n+1] = min(dp[n+1],dp[i]+1);
        }
    }
    debug(dp);
    if (dp[n+1] <= k) cout << yes;
    else cout << no;
}