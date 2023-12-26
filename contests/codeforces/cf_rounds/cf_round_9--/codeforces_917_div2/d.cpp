/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec 25 12:43:14 IST 2023
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

const ll mod = 998244353ll;

class segtree{
private:
    ll n;
    vector<ll> tree;
public:
    segtree(ll gn){
        n = gn;
        gn++;
        gn*=2ll;
        if (gn - (gn&(-gn)) != 0ll)
            gn = 1ll<<bit_width((ull)gn);
        tree.assign(gn,0ll);
    }

    void update(ll ind){
        for (tree[ind+=n]++; ind > 0ll; ind>>=1ll)
            tree[ind>>1ll] = (tree[ind]+tree[ind^1ll])%mod;
    }

    ll query(ll l, ll r){
        ll res = 0ll;
        r = min(n,r);
        for (l+=n,r+=n; l < r; l>>=1ll,r>>=1ll){
            if (l&1ll) res = (res+tree[l++])%mod;
            if (r&1ll) res = (res+tree[--r])%mod;
        }
        return res;
    }
};

class fentree{
private:
    ll n;
    vector<ll> tree;
    
    ll query(ll ind){
        ll res = 0ll;
        for(ind++;ind > 0ll; ind -= (ind&(-ind)))
            res += tree[ind];
        return res;
    }
public:
    fentree(ll gn){
        tree.assign(gn+1ll,0);
        n = gn;
    };

    ll query(ll l, ll r){
        r = min(n,r);
        return query(r-1ll) - query(l-1ll);
    }

    void update(ll ind){
        for(++ind; ind <= n; ind += (ind&(-ind)))
            tree[ind]++;
    }
};

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> p(n), q(k);
    rep(i,n) cin >> p[i];
    rep(i,k) cin >> q[i];
    ll inv = 0ll;
    {
        // segtree st(k);
        fentree st(k);
        rep(i,k-1ll,0ll,-1ll){
            inv += st.query(0,q[i]);
            st.update(q[i]);
        }
    }
    inv *= n;
    inv %= mod;
    // segtree st(2ll*n);
    fentree st(2ll*n);
    ll mxp = 2ll*n-1ll;
    vector<ll> gct(30,0ll);
    rep(i,30ll){
        if (k < i)
            break;
        gct[i] = (((k-i)*(k-i+1ll))/2ll)%mod;
    }
    vector<ll> lct(30,0ll);
    rep(i,30ll){
        lct[i] = gct[0];
        if (k >= i){
            lct[i] += (((k-i)*i)%mod + (i*(i-1ll))/2ll)%mod;
            lct[i] %= mod;
        }
        else{
            lct[i] += ((k*(k-1ll))/2ll)%mod;
            lct[i] %= mod;
        }
    }
    auto process_bigger = [&] (ll ind) {
        ll x = p[ind];
        rep(bit, 1ll, 30ll, 1ll){
            ll cur = x<<bit;
            ll last = x<<(bit-1ll);
            if (last > mxp) break;
            ll ct = st.query(last,cur);
            inv += (ct*gct[bit])%mod;
            inv %= mod;
        }
    };
    auto process_lesser = [&] (ll ind) {
        ll x = p[ind];
        rep(bit, 1ll, 30ll, 1ll){
            ll cur = x>>bit;
            ll last = x>>(bit-1ll);
            if (last == 0ll) break;
            ll ct = st.query(cur+1ll,last+1ll);
            inv += (ct*lct[bit-1ll])%mod;
            inv %= mod;
        }
    };
    auto process = [&] (ll ind){
        process_bigger(ind);
        process_lesser(ind);
        st.update(p[ind]);
    };
    rep(i,n-1ll,0ll,-1ll) process(i);
    cout << inv << endl;
}