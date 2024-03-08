/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

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
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    auto isgood = [&c](ll l, ll r) -> bool {
        if (l == r) return false;
        vector<ll> a(c.begin()+l,c.begin()+r+1ll);
        sort(all(a));
        ll n = sz(a);
        ll cur = -1ll, ct = 0ll, mx = 0, mxval;
        for (ll val : a)
            if (val == cur){
                ct++;
                if (mx < ct) mxval = val;
                mx = max(mx,ct);
            }
            else{
                cur = val;
                ct = 1;
                if (mx < ct) mxval = val;
                mx = max(mx,ct);
            }
        if (mx <= n/2ll) return true;
        if (*min_element(all(a)) > 1) return true;
        if (mxval != 1) return true;
        ll sum = accumulate(all(a),0ll);
        if (sum-n >= mx) return true;
        return false;
    };
    while(q--){
        ll l, r; cin >> l >> r; --l;--r;
        if (isgood(l,r)) cout << yes;
        else cout << no;
    }
}