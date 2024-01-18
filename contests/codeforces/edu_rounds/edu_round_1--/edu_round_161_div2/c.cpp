/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jan 18 20:16:34 IST 2024
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

#define ldir 0
#define rdir 1

class segtree{
private:
    ll n;
    vector<ll> left, right, a;
    vector<vector<ll>> tree;
    ll get_dir(ll i){
        if (i == 0ll) return rdir;
        if (i == n-1ll) return ldir;
        if (a[i+1ll]-a[i] < a[i]-a[i-1ll]) return rdir;
        return ldir;
    }
public:
    segtree(const vector<ll> &arr){
        a = arr;
        n = sz(a);
        ll gn = 2ll*n;
        if (n - (n&(-n)) != 0ll){
            n = (1ll<<bit_width((ull)n));
            rep(i,sz(a),n-1ll,1ll)
                a.push_back(LLONG_MAX);
            assert(sz(a) == n);
            gn = 2ll*n;
        }
        tree.assign(2,vector<ll>(gn,0ll));
        left.assign(gn,-1ll);
        right.assign(gn,-1ll);
        rep(i,n,2ll*n-1ll,1ll){
            left[i] = i-n;
            right[i] = i-n;
        }
        // debug(left,right);
        rep(i,n-1ll,1ll,-1ll){
            tree[ldir][i] = tree[ldir][i<<1ll]+tree[ldir][i<<1ll|1ll];
            tree[rdir][i] = tree[rdir][i<<1ll]+tree[rdir][i<<1ll|1ll];
            left[i] = left[i<<1ll];
            right[i] = right[i<<1ll|1ll];
            ll lind = right[i<<1ll];
            ll rind = left[i<<1ll|1ll];
            assert(lind == -1 || rind == -1ll || lind+1ll == rind);
            if (lind == -1ll || rind == -1ll) continue;
            if (get_dir(lind) == rdir) tree[rdir][i] += min(1ll,a[rind-a[lind]]);
            else tree[rdir][i] += a[rind]-a[lind];
            if (get_dir(rind) == ldir) tree[ldir][i]+= min(1ll,a[rind-a[lind]]);
            else tree[ldir][i] += a[rind]-a[lind];
        }
    }

    ll query(ll l, ll r, ll dir){
        if (dir == 0ll){
            --r;
            swap(l,r);
            ++r;
        }
        // debug(l,r,dir);
        ll res = 0ll;
        for(l+=n,r+=n; l < r; l>>=1ll,r>>=1ll){
            if (l&1ll){
                res += tree[dir][l];
                if (l+1ll == r)
                    break;
                ll lind = right[l];
                ll rind = right[l+1ll];
                if (lind != -1 && rind != -1){
                    if (dir == rdir){
                        if (get_dir(lind) == rdir) res += min(1ll,a[rind]-a[lind]);
                        else res += a[rind]-a[lind];
                    }
                    else{
                        if (get_dir(rind) == ldir) res += min(1ll,a[rind]-a[lind]);
                        else res += a[rind]-a[lind];
                    }
                }
                ++l;
            }
            if (r&1ll){
                --r;
                res += tree[dir][r];
                if (l >= r) break;
                assert(r>1ll);
                ll lind = right[r-1ll];
                ll rind = left[r];
                if (lind != -1 && rind != -1){
                    if (dir == rdir){
                        if (get_dir(lind) == rdir) res += min(1ll,a[rind]-a[lind]);
                        else res += a[rind]-a[lind];
                    }
                    else{
                        if (get_dir(rind) == ldir) res += min(1ll,a[rind]-a[lind]);
                        else res += a[rind]-a[lind];
                    }
                }
            }
        }
        return res;
    }
};

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree st(a);
    ll m; cin >> m;
    while(m--){
        ll x, y; cin >> x >> y; --x; --y;
        cout << st.query(x,y+1ll,(x<y)) << endl;
    }
}

/*


1
5
0 8 12 15 20

5
1 4
1 5
3 4
3 2
5 1


*/