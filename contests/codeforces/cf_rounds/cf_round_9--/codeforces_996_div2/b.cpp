/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Jan 12 20:08:22 IST 2025
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
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i,n) {
        if (a[i] > b[i]) c3++;
        else if (a[i] == b[i]) c2++;
        else c1++;
    }
    if (c1 == 0) cout << "YES\n";
    else if (c1 > 1) cout << "NO\n";
    else if (c1 == 1 && c2 == 0) {
        ll diff = -1, mn = LLONG_MAX;
        rep(i,n) {
            if (a[i] < b[i]) {
                diff = b[i]-a[i];
            } else {
                mn = min(mn,a[i]-b[i]);
            }
        }
        assert(diff != -1 && mn != LLONG_MAX);
        if (diff > mn) cout << "NO\n";
        else cout << "YES\n";
    }
    else cout << "NO\n";
}