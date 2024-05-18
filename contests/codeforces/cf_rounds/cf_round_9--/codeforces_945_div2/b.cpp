/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri May 17 20:14:27 IST 2024
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

class segtree {
public:
    int n;
    vector<int> tree;
    segtree(const vector<int> &a) {
        int gn = sz(a);
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,0);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1,-1)
            tree[i] = tree[i<<1]|tree[i<<1|1];
    }

    int query(int l, int r) {
        int res = 0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res|=tree[l--];
            if (r&1) res|=tree[--r];
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sol = 1;
    rep(bit,20){
        int v = (1<<bit);
        int last = -1;
        rep(i,n) {
            if (a[i]&v) {
                sol = max(sol,i-last);
                last = i;
            }
        }
        if (last != -1)
            sol = max(sol,n-last);
    }
    cout << sol << endl;
}