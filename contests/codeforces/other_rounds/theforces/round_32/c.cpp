/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 21 20:25:13 IST 2024
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
    sort(all(a));
    ll l = 0, r = n/2ll-1ll, sol = (a[r]-a[l])*(a.back()-a[n/2ll]);
    rep(i,1,n/2ll,1ll) {
        ll cur = (a[i+n/2ll-1]-a[i])*(a.back()-a.front());
        if (sol > cur) {
            sol = cur;
            l = i;
            r = i+n/2ll-1ll;
        }
    }
    vector<ll> b(n);
    ll j = 0ll;
    assert((r-l+1ll)==n/2ll);
    rep(i,l,r,1ll) {
        assert(j < sz(b));
        b[j] = a[i];
        j+=2ll;
    }
    j = 1ll;
    rep(i,0,l-1ll,1ll) {
        assert(j < sz(b));
        b[j] = a[i];
        j+=2ll;
    }
    rep(i,r+1ll,n-1ll,1ll) {
        assert(j < sz(b));
        b[j] = a[i];
        j+=2ll;
    }
    debug(sol);
    print_vec(b);
}