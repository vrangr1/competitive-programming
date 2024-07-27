/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 27 17:40:48 IST 2024
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
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> o1(n), o2(n);
    iota(all(o1),0);
    iota(all(o2),0);
    sort(all(o1), [&](const ll &i, const ll &j) {
        return a[i] > a[j];
    });
    sort(all(o2), [&](const ll &i, const ll &j) {
        return b[i] > b[j];
    });
    ll s1 = n, s2 = n, cur = 0ll;
    rep(i,n) {
        ll ind = o1[i];
        cur += a[ind];
        if (cur > x) {
            s1 = i+1ll;
            break;
        }
    }
    cur = 0ll;
    rep(i,n) {
        ll ind = o2[i];
        cur += b[ind];
        if (cur > y) {
            s2 = i+1ll;
            break;
        }
    }
    cout << min(s1,s2) << endl;
}