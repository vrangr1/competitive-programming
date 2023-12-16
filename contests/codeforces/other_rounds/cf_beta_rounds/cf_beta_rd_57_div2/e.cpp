/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 16 19:50:56 IST 2023
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

class segtree{
private:
    ll n;
    vector<ll> tree;
public:
    segtree(ll gn){
        ++gn;
        if (gn - (gn&(-gn)) != 0ll)
            gn = (1ll<<bit_width((ull)gn));
        n = gn;
        tree.assign(2ll*n,0ll);
    }

    void update(ll val){
        for (tree[val+=n]++; val > 0ll; val>>=1ll)
            tree[val>>1ll] = tree[val] + tree[val^1ll];
    }

    ll query(ll l, ll r){
        ll res = 0ll;
        for(l+=n,r+=n; l < r; l>>=1ll,r>>=1ll){
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j){
        return a[i] < a[j];
    });
    segtree stl(n),str(n);
    vector<ll> lbig(n), rsm(n);
    lbig[0] = rsm[n-1ll] = 0ll;
    stl.update(order[0]);
    str.update(order[n-1ll]);
    rep(i,1ll,n-1ll,1ll){
        lbig[i] = stl.query(order[i]+1ll, n);
        stl.update(order[i]);
    }
    rep(i,n-2ll,0ll,-1ll){
        rsm[i] = str.query(0ll,order[i]);
        str.update(order[i]);
    }
    ll sol = 0ll;
    rep(i,n)
        sol += lbig[i]*rsm[i];
    cout << sol << endl;
}