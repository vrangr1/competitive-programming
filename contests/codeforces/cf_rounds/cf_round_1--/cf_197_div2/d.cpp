/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 13 17:38:33 IST 2023
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
    bool oddxor;
    void update_ind(uint index){
        if (bit_width(index)%2 == oddxor)
            tree[index] = (tree[index<<1] ^ tree[index<<1|1]);
        else tree[index] = (tree[index<<1] | tree[index<<1|1]);
    }
public:
    segtree(const vector<int> &arr){
        n = sz(arr);
        assert(n - (n&(-n)) == 0);
        tree.assign(2*n,0);
        rep(i,n,2*n-1,1)
            tree[i] = arr[i-n];
        oddxor = bit_width((uint)n)%2;
        rep(i,n-1,1,-1)
            update_ind(i);
    }

    void update(int ind, int val){
        for (tree[ind+=n] = val; ind > 1; ind >>= 1)
            update_ind(ind>>1);
    }

    int query(){
        return tree[1];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    n = (1<<n);
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree st(a);
    while(m--){
        int i, b; cin >> i >> b; --i;
        st.update(i,b);
        cout << st.query() << endl;
    }
}