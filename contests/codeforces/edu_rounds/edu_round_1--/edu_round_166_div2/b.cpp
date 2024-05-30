/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 20:08:35 IST 2024
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
    vector<ll> a(n), b(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n+1) cin >> b[i];
    ll sol = 0;
    bool done = false;
    ll mn = LLONG_MAX;
    rep(i,n) {
        sol += llabs(a[i]-b[i]);
        if (done) continue;
        if (a[i] <= b[i] && b.back() <= b[i] && b.back() >= a[i]) {
            done = true;
            sol++;
            continue;
        }
        else if (a[i] <= b[i]) {
            if (b.back() > b[i]) {
                mn = min(mn,2ll*(b.back()-b[i]));
                mn = min(mn,b.back()-a[i]-llabs(a[i]-b[i]));
                continue;
            }
            assert(b.back() < a[i]);
            mn = min(mn,2ll*(a[i]-b.back()));
            mn = min(mn,b[i]-b.back()-llabs(a[i]-b[i]));
            continue;
        }
        if (a[i] >= b[i] && b.back() <= a[i] && b.back() >= b[i]) {
            done = true;
            sol++;
            continue;
        }
        assert(a[i] >= b[i]);
        if (b.back() > a[i]) {
            mn = min(2ll*(b.back()-a[i]),mn);
            mn = min(mn,b.back()-b[i]-llabs(a[i]-b[i]));
            continue;
        }
        assert(b.back() < b[i]);
        mn = min(2ll*(b[i]-b.back()),mn);
        mn = min(mn,a[i]-b.back()-llabs(a[i]-b[i]));
    }
    if (!done) {
        debug(mn);
        assert(mn != LLONG_MAX);
        sol += mn+1ll;
    }
    cout << sol << endl;

}

/*

1
2
1 3


*/