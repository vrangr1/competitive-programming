/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec 10 18:11:21 IST 2023
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

const ll mod = 998244353ll;
vector<ll> segtree, lazy, mult;


void update_range_util(ll index, ll cl, ll cr, ll l, ll r, ll diff){
    if (lazy[index] != 0ll){
        segtree[index] += ((cr-cl+1ll)*lazy[index])%mod;
        if (cl != cr){
            lazy[index*2ll+1ll] += lazy[index];
            lazy[index*2ll+2ll] += lazy[index];
            lazy[index*2ll+1ll] %= mod;
            lazy[index*2ll+2ll] %= mod;
        }
        lazy[index] = 0ll;
    }

    if (cl > cr || cl > r || cr < l) return;
    if (cl >= l && cr <= r){
        segtree[index] += ((cl-cr+1ll)*diff)%mod;
        segtree[index] %= mod;
        if (cl != cr){
            lazy[index*2ll+1ll] += diff;
            lazy[index*2ll+2ll] += diff;
            lazy[index*2ll+1ll] %= mod;
            lazy[index*2ll+2ll] %= mod;
        }
        return;
    }
    ll mid = (cl+cr)/2ll;
    update_range_util(index*2ll+1ll, cl, mid, l, r, diff);
    update_range_util(index*2ll+2ll,mid+1ll,cr,l,r,diff);
    segtree[index] = (segtree[index*2ll+1ll] + segtree[index*2ll+2ll])%mod;
}

void update_range(ll n, ll l, ll r, ll diff){
    update_range_util(0ll, 0ll, n-1ll, l, r, diff);
}

ll get_sum_util(ll cl, ll cr, ll l, ll r, ll index){
    if (lazy[index] != 0ll){
        segtree[index] += ((cr-cl+1ll)*lazy[index])%mod;
        segtree[index] %= mod;
        if (cl != cr){
            lazy[index*2ll+1ll] += lazy[index];
            lazy[index*2ll+2ll] += lazy[index];
            lazy[index*2ll+1ll] %= mod;
            lazy[index*2ll+2ll] %= mod;
        }
        lazy[index] = 0ll;
    }
    if (cl > cr || cl > r || cr < l) return 0ll;
    if (cl >= l && cr <= r)
        return segtree[index];
    ll mid = (cl+cr)/2ll;
    return (get_sum_util(cl,mid,l,r,2ll*index+1ll) + get_sum_util(mid+1ll,cr,l,r,2ll*index+2ll))%mod;
}

ll get_sum(ll n, ll l, ll r){
    if (l < 0ll || r > n-1ll || l > r){
        assert(false);
        return -1ll;
    }
    return get_sum_util(0ll,n-1ll,l,r,0ll);
}

void construct_util(vector<ll> &arr, ll l, ll r, ll index){
    if (l > r) return;
    if (l == r){
        segtree[index] = arr[l];
        return;
    }
    ll mid = (l+r)/2ll;
    construct_util(arr,l,mid,index*2ll+1ll);
    construct_util(arr, mid+1ll, r, index*2ll+2ll);
    segtree[index] = (segtree[index*2ll+1ll] + segtree[index*2ll+2ll])%mod;
}

void construct_segtree(vector<ll> &arr, ll n){
    segtree.assign(2*n+3ll,0ll);
    lazy.assign(2*n+3ll,0ll);
    mult.assign(2*n+3ll,1ll);
    construct_util(arr,0ll,n-1ll,0ll);
}
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
    auto inv = [](auto self, ll n) -> ll {
        if (n <= 1ll) return n;
        return ((mod - mod/n)*self(self,mod%n))%mod;
    };
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    construct_segtree(a,n);
    rep(i,n){
        ll l, r, x; cin >> l >> r >> x; --l;--r;
        ll val = (x*inv(inv,r-l+1ll))%mod;
        update_range(n,l,r,val);
    }
    rep(i,n) cout << get_sum(n,i,i) << " \n"[i==n-1];
}