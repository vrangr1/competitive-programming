/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
// typedef long long int ull;
typedef long double ld;
typedef long long int i128;
// typedef __int128_t i128;
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = 1e9+7;
const i128 hmax = (1ll<<60ll);
inline ll get_msb(ll val){
    return (64-__builtin_clzll(val));
}

unordered_map<string, ll> up2;

i128 compute_pow(i128 a, i128 n){
    string k = to_string(a) + "," + to_string(n);
    if (up2.find(k) != up2.end()) return up2[k];
    if (get_msb(a)*n >= 61) return hmax;
    if (n == 0) return 1;
    if (n == 1) return a;
    if (a >= hmax) return hmax;
    i128 temp = compute_pow(a*a,n/2);
    if (temp >= hmax) return hmax;
    if (n%2) return a*temp;
    return up2[k] = temp;
}

ll bin_sch(ll val, ll fx, ll low, ll high){
    if (low == high) return low;
    ll mid = (low+high+1ll)/2ll;
    ll one = 1;
    i128 midval = compute_pow(fx,mid);
    if (midval <= val) return bin_sch(val, fx, mid, high);
    return bin_sch(val, fx, low, mid-one);
}

unordered_map<ll,ll> umap;

ll compute_ans(ll val){
    if (umap.find(val) != umap.end()) return umap[val];
    ll fx = get_msb(val)-1;
    ll gx1 = bin_sch(val,fx,  0, 61);
    // ll gx = 0;
    // ll prod = 1ll;
    // for (;gx <= 61ll; ++gx){
    //     if (prod > val) break;
    //     if (get_msb(prod) + get_msb(fx) >= 61) prod = hmax;
    //     else
    //         prod *= fx;
    // }
    // --gx;
    return umap[val] = gx1;
}

ll binary_search(ll low, ll high){
    if (low == high) return low;
    ll mid = (low+high+1ll)/2ll;
    ll cmid = compute_ans(mid);
    if (cmid == compute_ans(low))
        return binary_search(mid,high);
    return binary_search(low,mid-1ll);
}

inline ll compute_next(ll x){
    ll nxt = (1ll<<get_msb(x));
    return binary_search(x, nxt-1ll);
}

inline ll get_log2(ll val){
    return get_msb(val);
}

ll compute_sum(ll cur, const ll r){
    if (cur > r) return 0ll;
    if (cur == r) return compute_ans(cur);
    ll nxt = min(compute_next(cur),r);
    return ((((i128)compute_ans(cur))*((i128)(nxt-cur+((i128)1))))%mod + compute_sum(nxt+1ll,r))%mod;
}

void solve(){
    int q; cin >> q;
    
    while(q--){
        ll l, r; cin >> l >> r;
        cout << (ll)compute_sum(l,r) << endl;
    }
}