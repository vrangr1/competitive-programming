/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct  5 22:40:39 IST 2024
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
void solve(int test_case);

int main() {
	fastIO;
	int T;cin>>T;rep(t,T)solve(t+1);
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
const int maxn = (int)1e7+5;
vector<bool> isp(maxn,true);
vector<int> dp(maxn,0);

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    isp[0] = isp[1] = false;
    rep(f,4,maxn-1,2)
        isp[f] = false;
    rep(v,3,maxn-1,2) {
        if (!isp[v]) continue;
        rep(f,2*v,maxn-1,v)
            isp[f] = false;
    }
    dp[5] = dp[6] = 2;
    dp[7] = dp[8] = 3;
    rep(i,9,maxn-1,1) {
        dp[i] += dp[i-1];
        if (isp[i] && isp[i-2]) {
            dp[i]++;
        }
    }
}

void solve(int test_case) {
    init();
    cout << "Case #" << test_case << ": ";
    int n; cin >> n;
    if (n < 5) return void(cout << "0\n");
    cout << dp[n] << endl;
}