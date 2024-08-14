/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 13 20:23:53 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    string s; cin >> s;
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto get = [&](ll l, ll r) -> ll {
        assert(l < r);
        return psum[r] - (l?psum[l-1]:0ll);
    };
    stack<ll> stk;
    ll sol = 0ll;
    ll l = 0, r = n-1ll;
    vector<pair<ll,ll>> ops;
    while(l < r) {
        while(l < r && s[l] != 'L') {
            l++;
        }
        if (l == r) break;
        while(l < r && s[r] != 'R') {
            r--;
        }
        if (l == r) break;
        ops.emplace_back(l,r);
        l++;
        r--;
    }
    while(!ops.empty()) {
        auto [cl, cr] = ops.back();
        sol += get(cl,cr);
        ops.pop_back();
    }
    cout << sol << endl;
}