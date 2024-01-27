/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 27 17:44:43 IST 2024
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
        n = gn;
        gn<<=1ll;
        if (gn - (gn&(-gn)) != 0ll)
            gn = 1ll<<bit_width((ull)gn);
        tree.assign(gn,0ll);
    }

    void update(ll l, ll r, ll val){
        assert(l!=r);
        if (l > r){
            update(l,n+1ll,val);
            if (r != 1ll)
                update(1,r,val);
            return;
        }
        --l;--r;
        assert(l<r);
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll){
            if (l&1ll){
                tree[l++] += val;
            }
            if (r&1ll){
                tree[--r] += val;
            }
        }
    }

    ll query(ll ind){
        --ind;
        ll res = 0ll;
        for(ind+=n;ind > 0ll;ind>>=1ll){
            res += tree[ind];
        }
        return res;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> x(m);
    segtree opt(n), other(n);
    ll sum = 0ll;
    rep(i,m){
        cin >> x[i];
        if (i == 0ll) continue;
        ll a = x[i-1], b = x[i];
        if (a > b) swap(a,b);
        ll reg = llabs(a-b), oth = min(a,b)+n-max(a,b);
        sum += min(reg,oth);
        if (reg <= oth){
            opt.update(a,b,reg);
            other.update(a,b,oth);
        }
        else{
            opt.update(b,a,oth);
            other.update(b,a,reg);
        }
    }
    ll mn = LLONG_MAX;
    debug(sum);
    rep(i,1ll,n,1ll){
        debug(i,opt.query(i),other.query(i),endl);
        mn = min(mn, sum - opt.query(i) + other.query(i));
    }
    cout << mn << endl;
}