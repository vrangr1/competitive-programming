/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Apr 16 21:14:39 IST 2024
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

class segtree{
private:
    // both included
    ll n, dsum;
    vector<ll> tree,psum, left, right;
    ll get_sum(ll l, ll r) {
        if (l <= r) {
            if (l == 0ll) return psum[r];
            else return psum[r]-psum[l-1ll];
        }
        if (l == r+1ll || (l == n-1ll && r == 0ll)) return dsum;
        assert(l != 0ll);
        assert(r != n-1ll);
        return dsum - get_sum(r+1ll,l-1ll);
    }

    ll get_len(ll ind){
        assert(left[ind] <= right[ind]);
        return right[ind]-left[ind]+1ll;
    }

    ll get_len(ll l, ll r){
        ll curl = left[l], curr = right[r-1ll];
        return curr-curl+1ll;
    }

public:
    segtree(const vector<ll> &a){
        n = sz(a);
        ll gn = n;
        gn++;
        dsum = accumulate(all(a),0ll);
        gn<<=1ll;
        if (__builtin_popcountll(gn) != 1ll)
            gn = ((1ll<<(64ll-__builtin_clzll(gn))));
        tree.assign(gn,0ll);
        psum.assign(n,0ll);
        left.assign(gn,0);
        right.assign(gn,n-1ll);
        psum[0] = a[0];
        rep(i,1ll,n-1ll,1)
            psum[i] = psum[i-1ll]+a[i];
        rep(i,n) {
            tree[i+n] = a[i];
            left[i+n] = i;
            right[i+n] = i;
        }
        rep(i,n-1ll,1ll,-1){
            // tree[i<<1], tree[i<<1|1]
            ll ind = ((i<<1ll)|1ll);
            tree[i] = (tree[i<<1ll] + tree[ind] + (get_sum(left[ind],right[ind])*get_len(i<<1ll)));
            left[i] = left[i<<1ll];
            right[i] = right[i<<1ll|1ll];
        }
    }

    ll query(ll l, ll r){
        ll res = 0ll;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll){
            if (l&1ll) {
                res += tree[l];
                res += get_sum(left[l],right[r-1ll]);
                l++;
            }
            if (r&1ll){
                --r;
                res += tree[r];
                if (l != r)
                    res += get_len(l,r-1ll)*get_sum(left[r],right[r]);
            }
        }
        return res;
    }
};

void solve(){
    ll n; cin >> n;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    ll dsum = accumulate(all(d),0ll);
    
}