/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 16 21:37:47 IST 2023
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
	TEST;
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
        gn++;
        if (gn - (gn&(-gn)) != 0ll)
            gn = (1<<bit_width((ull)gn));
        n = gn;
        tree.assign(2*n,0);
    }

    void update(ll ind, ll val){
        for (tree[ind+=n]=val; ind > 0ll; ind>>=1ll)
            tree[ind>>1ll] = tree[ind] + tree[ind^1ll];
    }

    ll query(ll l, ll r){
        ll res = 0ll;
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll){
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int z;
    rep(i,n){
        cin >> a[i];
        if (a[i] == 0) z = i;
    }
    rotate(a.begin(),a.begin()+z,a.end());
    // debug(a);
    ll s = 0, mx = 0;
    vector<ll> mex(n);
    set<ll> st;
    rep(i,n){
        st.insert(a[i]);
        while(st.find(mx) != st.end())
            mx++;
        mex[i] = mx;
        s += mx;
    }
    segtree segt(n);
    // rep(i,1ll,n-1ll,1ll) segt.update(mex[i],mex[i]);
    rep(i,n) segt.update(mex[i],mex[i]);
    ll cur = s, sol = s;
    mx = 0;
    st.clear();
    st.insert(0);
    rep(i,n-1,1ll,-1){
        st.insert(a[i]);
        while(st.find(mx) != st.end())
            mx++;
        
        
    }
}