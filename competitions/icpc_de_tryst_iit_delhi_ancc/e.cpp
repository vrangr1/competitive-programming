/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Mar 31 20:10:20 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<"\n\n"[i==sz(v)-1];}
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

class segtree{
public:
    int m,n;
    vector<int> tree, low, high;
    vector<pair<int,int>> ops;
    segtree(int nodes, vector<int> &lind, vector<int> &rind, int tourlen){
        n = tourlen;
        int gn = n<<1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,0);
        low = lind;
        high = rind;
        m = nodes;
        assert(sz(low) == m);
        assert(sz(high) == m);
    }

    void clear(){
        while(!ops.empty()){
            auto [ind,v] = ops.back();
            ops.pop_back();
            update(ind,-v,false);
        }
    }

    void update(int ind, int v, bool record = true){
        if (record) ops.emplace_back(ind,v);
        for(tree[ind+=n]+=v;ind>1;ind>>=1)
            tree[ind>>1] = tree[ind]+tree[ind^1];
    }

    int query(int l, int r){
        int res = 0;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }

    int query(int node){
        return query(low[node],high[node]+1);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> c(n);
    vector<vector<int>> init(n);
    rep(i,n){
        cin >> c[i];
        --c[i];
        init[c[i]].push_back(i);
    }
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<vector<tuple<int,int,int>>> qrs(n);
    vector<int> sol;
    {
        vector<int> cp = c;
        rep(i,q){
            int t, v, x; cin >> t >> v >> x; --v;--x;
            if (t == 1){
                qrs[cp[v]].emplace_back(3,v,-1);
                cp[v] = x;
                qrs[x].emplace_back(1,v,-1);
            }
            else{
                qrs[x].emplace_back(2,v,sz(sol));
                sol.push_back(-1);
            }
        }
    }
    int tind = 0;
    vector<int> tour(n,-1), low(n,-1), high(n,-1);
    auto dfs = [&](auto &&self, int node, int parent) -> void {
        tour[node] = tind++;
        int l = tour[node], r = l;
        for (int v : g[node]){
            if (v == parent) continue;
            self(self,v,node);
            l = min(low[v],l);
            r = max(high[v],r);
        }
        low[node] = l;
        high[node] = r;
    };
    dfs(dfs,0,-1);
    segtree st(n, low, high, tind);
    rep(color,n){
        st.clear();
        for (int v : init[color])
            st.update(tour[v],1);
        for (auto [t,v,ind] : qrs[color]){
            if (t == 1)
                st.update(tour[v],1);
            else if (t == 3)
                st.update(tour[v],-1);
            else sol[ind] = st.query(v);
        }
    }
    print_vec(sol);
}