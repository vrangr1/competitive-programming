/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 15:49:29 IST 2023
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
    vector<int> tree, ts, start;
public:
    segtree(int gn){
        n = gn;
        gn *= 2;
        if (gn - (gn&(-gn)) != 0)
            gn = 1<<bit_width((uint)gn);
        tree.assign(gn,-1);
        ts.assign(gn,-1);
        start.assign(gn,-1);
    }

    void update(int l, int r, int val, int y, int time){
        for (l+=n,r+=n; l < r; l>>=1,r>>=1){
            if (l&1){
                tree[l] = val;
                start[l] = y;
                ts[l++] = time;
            }
            if (r&1){
                tree[--r] = val;
                start[r] = y;
                ts[r] = time;
            }
        }
    }

    pair<int,int> query(int ind){
        int val = -1, time = -1, beg = -1;
        for (ind+=n;ind>0;ind>>=1){
            if (ts[ind] > time){
                val = tree[ind];
                beg = start[ind];
                time = ts[ind];
            }
        }
        return {val,beg};
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    segtree st(n);
    rep(i,m){
        int t; cin >> t;
        if (t == 1) {
            int x, y, k; cin >> x >> y >> k; --x;--y;
            st.update(y, y+k, x, y, i);
        } else {
            int x; cin >> x; --x;
            pair<int,int> q = st.query(x);
            if (q.first == -1){
                cout << b[x] << endl;
                continue;
            }
            cout << a[q.first + x - q.second] << endl;
        }
    }
}