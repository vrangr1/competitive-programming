/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 04:29:40 IST 2023
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

#define left 0
#define right 1
#define both 2
#define open '('

class segtree{
private:
    int n;
    vector<vector<int>> tree;
    vector<int> resleft, resright;
    inline int get_ind(const char ch){
        if (ch == open) return left;
        else return right;
    }
public:
    segtree(const string &s){
        resleft.assign(3,0);
        resright.assign(3,0);
        n = sz(s);
        n*=2;
        if (n - (n&(-n)) != 0)
            n = 1<<bit_width((uint)n);
        tree.assign(n,vector<int>(3,0));
        n = sz(s);
        rep(i,n,(2*n)-1,1){
            tree[i][get_ind(s[i-n])]++;
        }
        rep(i,n-1,1,-1){
            int match = min(tree[i<<1][left],tree[i<<1|1][right]);
            tree[i][both] = 2*match + tree[i<<1][both] + tree[i<<1|1][both];
            tree[i][left] = tree[i<<1][left]+tree[i<<1|1][left]-match;
            tree[i][right] = tree[i<<1][right] + tree[i<<1|1][right] - match;
        }
    }

    int query(int l, int r){
        fill(all(resleft),0);
        fill(all(resright),0);
        for (l+=n,r+=n; l < r; l>>=1, r>>=1){
            if (l&1){
                int match = min(tree[l][right], resleft[left]);
                resleft[left] += tree[l][left] - match;
                resleft[both] += tree[l][both] + 2*match;
                ++l;
            }
            if (r&1){
                --r;
                int match = min(tree[r][left], resright[right]);
                resright[right] += tree[r][right] - match;
                resright[both] += tree[r][both] + 2*match;
            }
        }
        return resleft[both] + resright[both] + 2*min(resleft[left],resright[right]);
    }
};

void solve(){
    string s; cin >> s;
    int m; cin >> m;
    segtree st(s);
    while(m--){
        int l, r; cin >> l >> r;--l;
        cout << st.query(l,r) << endl;
    }
}