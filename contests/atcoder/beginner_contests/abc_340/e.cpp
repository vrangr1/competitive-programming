/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Feb 10 18:01:58 IST 2024
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
#include <atcoder/lazysegtree>
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    auto op = [](ll a, ll b) -> ll {
        return a + b;
    };
    auto e = []() -> ll {
        return 0;
    };
    struct F{
        ll val;
    };
    auto mapping = [](F f, ll x) -> ll {
        return x + f.val;
    };
    auto composition = [](F f, F g) -> F {
        return F{f.val + g.val};
    };
    auto id = []() -> F {
        return F{0ll};
    };
    atcoder::lazy_segtree<ll,op,e,F,mapping,composition,id> seg(a);
    rep(i,m){
        ll ind = b[i], val = seg.get(ind);
        seg.set(ind,0ll);
        seg.apply(0ll,n,F{val/n});
        val %= n;
        if (n-ind-1ll >= val){
            seg.apply(ind+1ll,ind+val+1ll,F{1ll});
        }
        else{
            seg.apply(ind+1ll,n,F{1ll});
            seg.apply(0,val-(n-ind-1ll),F{1ll});
        }
    }
    rep(i,n){
        cout << seg.get(i) << " \n"[i==n-1];
    }
}