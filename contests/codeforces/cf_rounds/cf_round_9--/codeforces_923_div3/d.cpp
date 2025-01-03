/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb  6 20:37:04 IST 2024
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

class maxtree{
private:
    int n;
    vector<int> tree, inds;
public:
    maxtree(const vector<int> &a){
        n = sz(a);
        int gn = n;
        gn*=2;
        if (gn - (gn&(-gn)) != 0)
            gn = (1<<bit_width((uint)gn));
        tree.resize(gn);
        inds.resize(gn);
        rep(i,n,(2*n)-1,1){
            tree[i] = a[i-n];
            inds[i] = i-n;
        }
        rep(i,n-1,1,-1){
            tree[i] = max(tree[i<<1],tree[i<<1|1]);
            if (tree[i<<1] >= tree[i<<1|1])
                inds[i] = inds[i<<1];
            else inds[i] = inds[i<<1|1];
        }
    }

    int query(int l, int r){
        int res = INT_MIN, resind = -1;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if (l&1){
                if (res < tree[l]){
                    res = tree[l];
                    resind = inds[l];
                }
                ++l;
            }
            if (r&1){
                --r;
                if (res < tree[r]){
                    res = tree[r];
                    resind = inds[r];
                }
            }
        }
        assert(resind != -1);
        return resind;
    }
};

class mintree{
private:
    int n;
    vector<int> tree, inds;
public:
    mintree(const vector<int> &a){
        n = sz(a);
        int gn = n;
        gn*=2;
        if (gn - (gn&(-gn)) != 0)
            gn = (1<<bit_width((uint)gn));
        tree.resize(gn);
        inds.resize(gn);
        rep(i,n,(2*n)-1,1){
            tree[i] = a[i-n];
            inds[i] = i-n;
        }
        rep(i,n-1,1,-1){
            tree[i] = min(tree[i<<1],tree[i<<1|1]);
            if (tree[i<<1] <= tree[i<<1|1])
                inds[i] = inds[i<<1];
            else inds[i] = inds[i<<1|1];
        }
    }

    int query(int l, int r){
        int res = INT_MAX, resind = -1;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if (l&1){
                if (res > tree[l]){
                    res = tree[l];
                    resind = inds[l];
                }
                ++l;
            }
            if (r&1){
                --r;
                if (res > tree[r]){
                    res = tree[r];
                    resind = inds[r];
                }
            }
        }
        assert(resind != -1);
        return resind;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int q; cin >> q;
    maxtree mx(a);
    mintree mn(a);
    while(q--){
        int l, r; cin >> l >> r;
        --l;--r;
        int i = mx.query(l,r+1), j = mn.query(l,r+1);
        if (i == j)
            cout << "-1 -1\n";
        else cout << i+1 << space << j+1 << endl;
    }
    cout << endl;
}