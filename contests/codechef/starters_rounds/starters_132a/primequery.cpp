/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  1 20:19:20 IST 2024
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
#define debug(...) 42
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> oct(n,0), tct(n,0);
    rep(i,n){
        if (i){
            oct[i] = oct[i-1];
            tct[i] = tct[i-1];
        }
        oct[i] += (a[i]==1);
        tct[i] += (a[i]==2);
    }
    auto get = [&](ll l, ll r) -> pair<ll,ll> {
        if (!l) return {oct[r],tct[r]};
        return {oct[r]-oct[l-1],tct[r]-tct[l-1]};
    };
    int q; cin >> q;
    while(q--) {
        ll l, r, k; cin >> l >> r >> k;
        --l;--r;
        auto [o, t] = get(l,r);
        assert(o+t <= r-l+1ll);
        ll rem = min(k,r-l+1ll-o-t), x = k-rem;
        assert(rem>=0ll);
        if (o > t) swap(o,t);
        if (rem <= t-o) {
            o+=rem;
            assert(o <= t);
            if (o < t) {
                ll v = (t-o)/2ll;
                v = min(v,x);
                o += v;
                t-=v;
            }
            cout << o*t << endl;
            continue;
        }
        rem -= t-o;
        o = t;
        o+=rem/2ll;
        t+=rem/2ll;
        t += (rem%2ll);
        cout << o*t << endl;
    }
}