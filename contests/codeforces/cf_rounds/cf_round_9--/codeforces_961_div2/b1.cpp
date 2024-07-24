/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jul 23 20:16:31 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sol = 0ll;
    sort(all(a));
    vector<ll> b, c;
    rep(i,n) {
        if (b.empty() || b.back() != a[i]) {
            b.push_back(a[i]);
            c.push_back(1);
        }
        else c.back()++;
    }
    n = sz(b);
    debug(b,c);
    rep(i,n-1ll) {
        if (b[i+1] > b[i]+1ll) {
            sol = max(sol,min((m/b[i]),c[i])*b[i]);
            continue;
        }
        if (b[i]*c[i] + b[i+1]*c[i+1] <= m) {
            sol = max(sol,b[i]*c[i] + b[i+1]*c[i+1]);
            continue;
        }
        rep(ct,c[i]+1ll) {
            if (b[i]*ct > m) break;
            ll cur = (m-(b[i]*ct))/b[i+1];
            cur = min(cur,c[i+1]);
            sol = max(b[i]*ct+cur*b[i+1],sol);
        }
    }
    sol = max(sol,min((m/b.back()),c.back())*b.back());
    cout << sol << endl;
}