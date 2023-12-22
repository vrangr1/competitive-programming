/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 16:12:53 IST 2023
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
#ifndef DSU_SNIPPET
#define DSU_SNIPPET
#include <iostream>
#include <vector>
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
class DSU{
private:
    const type neg = static_cast<type>(-1), z = static_cast<type>(0);
    type n;
public:
    std::vector<type> parent, rank;
    type compsize = 0;
    DSU(type gn):parent(gn,neg),rank(gn,z){
        this->compsize = gn;
        this->n = gn;
    }

    void rebuild(){
        fill(all(this->parent),neg);
        fill(all(this->rank),z);
        this->compsize = this->n;
    }

    type find(type x){
        if (this->parent[x] == neg) return x;
        return this->parent[x] = this->find(this->parent[x]);
    }

    void unite(type x, type y){
        type px = this->find(x), py = this->find(y);
        if (px == py) return;
        this->compsize--;
        if (this->rank[px] < this->rank[py]){
            this->rank[px] = this->rank[py];
            this->parent[px] = py;
        }
        else if (this->rank[px] > this->rank[py]){
            this->rank[py] = this->rank[px];
            this->parent[py] = px;
        }
        else{
            this->rank[px] = ++(this->rank[py]);
            this->parent[px] = py;
        }
    }
};
#endif
// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(m);
    rep(i,m){
        int u, v; cin >> u >> v; --u; --v;
        edges[i] = {u,v};
    }
    DSU<int> dsu(n);
    vector<int> cantmiss;
    rep(i,m){
        int u = edges[i][0], v = edges[i][1];
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u,v);
        cantmiss.push_back(i);
    }
    dsu.rebuild();
    rep(i,m-1,0,-1){
        int u = edges[i][0], v = edges[i][1];
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u,v);
        cantmiss.push_back(i);
    }
    int k; cin >> k;
    while(k--){
        int l, r; cin >> l >> r; --l;--r;
        dsu.rebuild();
        for (auto ind : cantmiss){
            if (ind >= l && ind <= r) continue;
            dsu.unite(edges[ind][0],edges[ind][1]);
        }
        cout << dsu.compsize << endl;
    }
}