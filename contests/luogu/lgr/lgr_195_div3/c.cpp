/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug  3 12:15:42 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1) return void(cout << m << endl);
    sort(all(a));
    vector<vector<ll>> left(n,vector<ll>(2,0)), right(n,vector<ll>(2,0));
    rep(i,n) {
        if (!i) {
            left[i] = {m,m};
            continue;
        }
        ll over = max(0ll,a[i-1]+m-1-a[i]+1ll);
        if (!over) {
            left[i] = {left[i-1][0]+m,m};
            continue;
        }
        if (left[i-1][1] >= over)
            left[i] = {left[i-1][0]-over+m-over,m-over};
        else
            left[i] = {left[i-1][0] - left[i-1][1] + m - over, m-over};
    }
    rep(i,n-1,0ll,-1) {
        if (i == n-1ll) {
            right[i] = {m,m};
            continue;
        }
        ll over = max(0ll,a[i]+m-1-a[i+1]+1ll);
        if (!over) {
            right[i] = {right[i+1][0]+m,m};
            continue;
        }
        if (right[i+1][1] >= over) {
            right[i] = {right[i+1][0]-over+m-over,m-over};
            continue;
        }
        right[i] = {right[i+1][0]-right[i+1][1]+m-over,m-over};
    }
    debug(m,a,left,right);
    ll sol = 0ll;
    rep(i,n) {
        ll cur;
        if (!i) {
            cur = right[i+1][0] + m;
            sol = max(sol,cur);
            continue;
        }
        if (i == n-1) {
            cur = left[i-1][0] + m;
            sol = max(sol,cur);
            continue;
        }
        ll over = max(0ll,a[i-1]+m-1-a[i+1]+1ll);
        if (!over) {
            cur = left[i-1][0] + right[i+1][0] + m;
            sol = max(sol,cur);
            continue;
        }
        cur = left[i-1][0] + right[i+1][0] + m;
        if (over <= left[i-1][1]) cur-=over;
        else cur -= left[i-1][1];
        if (over <= right[i+1][1]) cur-=over;
        else cur -= right[i+1][1];
        sol = max(sol,cur);
    }
    cout << sol << endl;
}