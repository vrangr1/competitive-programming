/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 14 01:14:45 IST 2024
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

void solve1() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (x == 1) return void(cout << accumulate(all(a),0ll) << endl);
    sort(rall(a));
    vector<ll> ct(x-1,0ll);
    ll sol = 0ll;
    for (ll v : a) {
        rep(i,x-2,0ll,-1) {
            ll c = min(v,ct[i]);
            v -= c;
            ct[i]-=c;
            if (i != x-2) ct[i+1] += c;
            if (v == 0) break;
        }
        if (v) {
            sol += v;
            ct[0] += v;
        }
    }
    cout << sol << endl;
}

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    ll sum = accumulate(all(a),0ll), sol = max(a.front(),(sum+x-1ll)/x);
    debug(sum);
    cout << sol << endl;
}