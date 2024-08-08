/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Aug  8 20:26:51 IST 2024
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

// source: iceknight1093, editorialist for codechef starters 146
// link: https://discuss.codechef.com/t/ctc-editorial/119286
void solve() {
    int n, m; cin >> n >> m;
    vector a(n, vector(m, 0));
    for (auto &v : a) for (auto &x : v)
        cin >> x;
    
    vector<ll> best(n, LLONG_MAX);
    ll ans1 = 0, ans2 = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll left = 0, right = accumulate(begin(a[i]), end(a[i]), 0ll);
        ans1 = max(ans1, right);
        for (int j = 0; j < m; ++j) {
            left += a[i][j];
            best[i] = min(best[i], max(left, right));
            right -= a[i][j];
        }
    }

    multiset<ll> bests(begin(best), end(best));
    for (int i = 0; i < n; ++i) {
        ll left = 0, right = accumulate(begin(a[i]), end(a[i]), 0ll);
        bests.erase(bests.find(best[i]));
        debug(endl,a[i]);
        for (int j = 0; j < m; ++j) {
            left += a[i][j];

            ll cur = 0;
            // this branch and something else
            cur = max(left, right) + *bests.rbegin();
            // two branches meeting here
            if (n > 2) {
                auto it = rbegin(bests);
                cur = max(cur, a[i][j] + *it + *next(it));
            }
            ans2 = min(ans2, cur);
            debug(cur);
            right -= a[i][j];
        }
        bests.insert(best[i]);
    }
    cout << max(ans1, ans2) << '\n';
}