/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jun 21 19:00:00 IST 2024
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,0});
    vector<ll> dp(n+2);
    dp[0] = 0ll;
    rep(i,1ll,n,1ll) {
        while(!pq.empty() && pq.top().second < i-k){
            pq.pop();
        }
        assert(!pq.empty());
        if (pq.top().first < 0) dp[i] = -1;
        else dp[i] = pq.top().first + a[i-1];
        if (dp[i] < 0ll) dp[i] = -1;
        pq.emplace(dp[i],(ll)i);
    }
    while(!pq.empty() && pq.top().second < n+1ll-k){
        pq.pop();
    }
    assert(!pq.empty());
    dp[n+1ll] = pq.top().first;
    debug(dp);
    cout << dp[n+1] << endl;
}