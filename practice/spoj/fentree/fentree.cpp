/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec 11 02:31:14 IST 2023
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
// #include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
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

class segtree{
private:
    ll n;
    vector<ll> a, tree;
    void construct_tree(){
        tree.assign(2*n,0ll);
        // assert(n - (n&(-n)) == 0ll);
        rep(i,n,2ll*n-1ll,1ll){
            // assert(i < sz(tree) && i >= 0);
            // assert(i-n >= 0);
            // assert(i-n < n);
            tree[i] = a[i-n];
        }
        rep(i,n-1ll,1ll,-1ll){
            // assert(2ll*i+1ll < sz(tree));
            // assert(2ll*i < sz(tree));
            tree[i] = tree[2ll*i+1ll] + tree[2ll*i];
        }
    }

    ll get_sum_util(ll ind, ll cl, ll cr, const ll l, const ll r){
        // assert(cl <= cr);
        // assert(l <= r);
        if (cr <= l && cl >= r) return 0ll;
        if (ind >= sz(tree)) return 0ll;
        // assert(ind >= 0 && ind < sz(tree));
        if (cl >= l && cr <= r){
            // debug(ind);
            // debug(tree);
            return tree[ind];
        }
        ll mid = (cl+cr)/2ll;
        return get_sum_util(ind*2ll, cl, mid, l, r) + get_sum_util(ind*2ll+1ll, mid, cr, l, r);
    }

    void update_util(ll ind, ll x){
        // assert(ind < sz(tree));
        // assert(ind >= 0ll);
        // debug(ind);
        tree[ind] += x;
        if (ind == 0ll) return;
        update_util(ind/2ll,x);
    }
public:
    segtree(const vector<ll> &arr){
        n = arr.size();
        if (n - (n&(-n)) != 0)
            n = (1ll<<(64ll - __builtin_clzll(n)));
        // assert(n-(n&(-n)) == 0ll);
        a.assign(n,0ll);
        // assert(sz(a) == n);
        rep(i,sz(arr)){
            a[i] = arr[i];
            // assert(i<n);
        }
        construct_tree();
        // debug(tree);
        // debug(n);
    }

    void build(const vector<ll> &arr){
        n = arr.size();
        if (n - (n&(-n)) != 0)
            n = (1ll<<(64ll - __builtin_clzll(n)));
        
    }

    ll get_sum(ll l, ll r){
        return get_sum_util(1, 0, n, l, ++r);
    }

    void update(ll ind, ll x){
        a[ind] += x;
        // debug(ind,x);
        update_util(ind+n,x);
        // debug(endl);
    }
};

const ll N = 1e6;  // limit for array size
ll n;  // array size
vector<ll> t(2ll*N);

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1ll] + t[i<<1ll|1ll];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1ll; p >>= 1ll) t[p>>1ll] = t[p] + t[p^1ll];
}

ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1ll) res += t[l++];
    if (r&1ll) res += t[--r];
  }
  return res;
}

void solve(){
    // ll n; cin >> n;
    cin >> n;
    // vector<ll> a(n);
    // rep(i,n) cin >> a[i];
    rep(i,n) cin >> t[n+i];
    build();
    // segtree st(a);
    int q; cin >> q;
    // debug(query(0,1));
    // debug(query(1,2));
    // debug(query(2,3),query(3,4),query(2,4));
    while(q--){
        char op; cin >> op;
        if (op == 'q'){
            ll l, r; cin >> l >> r; --l;
            // --r;
            // cout << st.get_sum(l,r) << endl;
            cout << query(l,r) << endl;
        }
        else{
            ll i, x; cin >> i >> x; --i;
            // st.update(i,x);
            modify(i,t[i+n]+x);
        }
    }
}
