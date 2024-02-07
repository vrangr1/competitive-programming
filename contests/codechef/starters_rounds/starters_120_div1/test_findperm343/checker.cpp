/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Feb  7 21:46:52 IST 2024
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
    ll n;
    vector<ll> tree;
public:
    segtree(ll gn){
        n = gn;
        gn *= 2ll;
        if (gn - (gn&(-gn)) != 0ll)
            gn = (1ll<<bit_width((ull)gn));
        tree.assign(gn,0ll);
    }

    ll query(ll l, ll r){
        ll res = 0ll;
        assert(l<r);
        assert(l >= 0ll && l < n && r >= 0ll && r < n);
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll){
            if (l&1ll)
                res += tree[l++];
            if (r&1ll)
                res += tree[--r];
        }
        return res;
    }

    void update(ll ind){
        assert(ind >= 0ll && ind < n);
        ind+=n;
        tree[ind]++;
        for(;ind>1ll;ind>>=1ll)
            tree[ind>>1ll] = tree[ind] + tree[ind^1ll];
    }
};

void solve(){
    ll n; cin >> n;
    ll n2 = (n<<1ll);
    vector<ll> a(n2);
    vector<vector<ll>> inds(n+1ll);
    rep(i,n2){
        cin >> a[i];
        inds[a[i]].push_back(i);
        assert(sz(inds[a[i]]) <= 2);
    }
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    segtree st(n2);
    rep(i,n-1,0ll,-1){
        ll v = p[i];
        assert(sz(inds[v]) == 2);
        if (inds[v][0] > inds[v][1])
            swap(inds[v][0],inds[v][1]);
        ll diff = inds[v][1]-inds[v][0]-1ll-st.query(inds[v][0],inds[v][1]);
        if (diff > n) return void(cout << "0\n");
        st.update(inds[v][1]);
        st.update(inds[v][0]);
    }
    cout << "1\n";
}