/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 28 20:10:01 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
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
    vector<int> a(n), b(n-1);
    rep(i,n-1) cin >> b[i];
    a[0] = b[0];
    const int mx = (1<<30)-1;
    a[1] = mx;
    rep(i,2,n-1,1) {
        if ((b[i-1] - (b[i-1]&a[i-1])) > 0) return void(cout << "-1\n");
        a[i] = (b[i-1] | (mx^a[i-1]));
    }
    if (DEBUG) {
        assert(a[0] <= mx);
        rep(i,n-1) {
            assert((a[i]&a[i+1]) == b[i]);
            assert(a[i+1] <= mx);
        }
    }
    print_vec(a);
}

void solve2() {
    ll n; cin >> n;
    vector<ll> b(n-1);
    rep(i,n-1) cin >> b[i];
    vector<ll> a(n);
    a.back() = b.back();
    const ll mx = (1<<30)-1;
    a[n-2] = mx;
    rep(i,n-3ll,0ll,-1) {
        if ((b[i]&a[i+1]) != b[i]) return void(cout << "-1\n");
        a[i] = (b[i]|(mx^a[i+1]));
    }
    print_vec(a);
}

void solve() {
    ll n; cin >> n;
    vector<ll> b(n-1), a(n);
    rep(i,n-1) cin >> b[i];
    rep(i,1,n-2ll,1)
        a[i] = (b[i-1]|b[i]);
    a[0] = b[0];
    a.back() = b.back();
    rep(i,n-1) {
        if (b[i] != (a[i]&a[i+1])) return void(cout << "-1\n");
    }
    print_vec(a);
}