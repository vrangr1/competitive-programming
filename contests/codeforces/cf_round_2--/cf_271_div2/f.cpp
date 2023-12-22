/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 11:26:41 IST 2023
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
    int n;
    vector<int> tree;
public:
    segtree(const vector<int> &a){
        n = sz(a);
        n*=2;
        if (n - (n&(-n)) != 0)
            n = 1<<bit_width((uint)n);
        tree.assign(n,0);
        n = sz(a);
        rep(i,n,2*n-1,1)
            tree[i] = a[i-n];
        rep(i,n-1,1,-1)
            tree[i] = gcd(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r){
        int res = 0;
        for (l += n, r+=n; l < r; l>>=1,r>>=1){
            if (l&1){
                if (res == 0) res = tree[l++];
                else res = gcd(res,tree[l++]);
            }
            if (r&1){
                if (res == 0) res = tree[--r];
                else res = gcd(res,tree[--r]);
            }
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int t; cin >> t;
    map<int,vector<int>> mp;
    rep(i,n) mp[a[i]].push_back(i);
    auto get_count = [&](const int val, const int l, const int r) -> int {
        if (mp.find(val) == mp.end()) return 0;
        return (int)(upper_bound(all(mp[val]), r) - lower_bound(all(mp[val]), l));
    };
    segtree st(a);
    while(t--){
        int l, r; cin >> l >> r; --l;
        int val = st.query(l,r);
        debug(l,r,val,get_count(val,l,r-1));
        cout << r-l-get_count(val,l,r-1) << endl;
        debug(endl);
    }
}