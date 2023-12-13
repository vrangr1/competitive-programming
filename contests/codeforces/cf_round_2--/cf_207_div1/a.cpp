/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 13 18:31:02 IST 2023
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
    vector<int> ts;
public:
    segtree(int sz){
        n = sz;
        n*=2;
        if (n - (n&(-n)) != 0)
            n = (1<<bit_width((uint)n));
        tree.assign(n,-1);
        ts.assign(n,-1);
        n = sz;
    }

    void modify(int l, int r, int x, int curts){
        // debug(l,r,x,curts);
        l+=n;
        r+=n;
        for(; l < r; l>>=1, r>>=1){
            if ((l&1) && tree[l] == -1){
                tree[l] = x;
                ts[l++] = curts;
            }
            else if (l&1) l++;
            if ((r&1) && tree[r-1] == -1){
                tree[--r] = x;
                ts[r] = curts;
            }
            else if (r&1) --r;
        }
        // debug(tree,ts);
    }

    void push(){
        rep(i,1,n-1,1){
            if (tree[i] == -1) continue;
            if (tree[i<<1] == -1 || ts[i<<1] > ts[i]){
                tree[i<<1] = tree[i];
                ts[i<<1] = ts[i];
            }
            if (tree[i<<1|1] == -1 || ts[i<<1|1] > ts[i]){
                tree[i<<1|1] = tree[i];
                ts[i<<1|1] = ts[i];
            }
            tree[i] = -1;
            ts[i] = -1;
        }
    }

    void print(){
        debug('p',tree,ts);
        rep(i,n,2*n-1,1)
            if (tree[i] != -1 && tree[i] != (i-n+1)) cout << tree[i] << " \n"[i==2*n-1];
            else cout << 0 << " \n"[i==2*n-1];
        debug(endl);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segtree sg(n);
    // sg.print();
    rep(i,m){
        int l, r, x; cin >> l >> r >> x;
        --l;
        if (l <= x-1 && r > x-1){
            sg.modify(l,x-1,x,i);
            sg.modify(x,r,x,i);
        }
        else sg.modify(l,r,x,i);
        debug(i);
        // sg.print();
    }
    // sg.print();
    sg.push();
    sg.print();
}