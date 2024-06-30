/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 30 20:26:53 IST 2024
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

void solve1() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    debug(a);
    vector<int> ct(n+1,0);
    int k = 0;
    rep(i,n) {
        ct[a[i]]++;
        if (ct[a[i]] == 1) k++;
    }
    vector<int> time(n+1,INT_MAX);
    int last = 0;
    rep(i,1,n,1) {
        if (ct[i]) time[i] = ++last;
    }
    vector<int> order(n+1);
    iota(all(order),0);
    stable_sort(all(order),[&](const int &i, const int &j) {
        return ct[i] < ct[j];
    });
    int op = 0;
    debug(k,ct,order,time);
    for (int i : order) {
        if (time[i] != INT_MAX && time[i] > op+ct[i]) {
            debug(endl,i);
            op += ct[i];
            rep(j,i+1,n,1)
                if (time[j] != INT_MAX) time[j]--;
            k--;
            debug(op,time);
        }
    }
    cout << k << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vector<vector<int>> dp(n,vector<int>(2,0)), mx(n,vector<int>(2,0));
    dp[0][0] = 1;
    mx[0][0] = a[0];
    mx[0][1] = INT_MIN;
    int sol = 1;
    rep(i,1,n-1,1) {
        dp[i][0] = 1;
        mx[i][0] = a[i];
        dp[i][1] = dp[i-1][0];
        mx[i][1] = mx[i-1][0];
        rep(j,i) {
            if (dp[i][1] >= dp[j][0]) {
                dp[i][1] = dp[j][0];
                mx[i][1] = max(mx[i][1],mx[j][0]);
            }
            if (a[i] > mx[j][1]) {
                if (dp[j][1]+1 > dp[i][0]) {
                    dp[i][0] = dp[j][1]+1;
                    mx[i][0] = max(mx[j][1],a[i]);
                    continue;
                }
                if (dp[j][1]+1 == dp[i][0]) {
                    mx[i][0] = min(mx[i][0],max(mx[j][1],a[i]));
                }
                continue;
            }
        }
        sol = max({sol,dp[i][0],dp[i][1]});
    }
    debug(a,dp,mx);
    cout << sol << endl;
}