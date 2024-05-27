/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#include <random>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST cout << "1\n"
#define TEST1
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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
mt19937 rng((uint)chrono::steady_clock::now().time_since_epoch().count());
ull grng(const ull maxval){return rng()%maxval;}
void generate_test();

int main(){
	fastIO;
    TEST;
    generate_test();
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

vector<vector<int>> generate_tree(const int maxn, const int maxdepth = INT_MAX){
    assert(maxn >= 1);
    assert(maxdepth >= 1);
    int n = ((int)grng(maxn))+1, d = ((int)grng(min(maxdepth,n))) + 1;
    d=n;
    assert(n > 0);
    if (n == 1) return {{},{}};
    vector<int> nodes(n);
    iota(all(nodes),1);
    shuffle(all(nodes),rng);
    int root = nodes.back();
    nodes.pop_back();
    vector<vector<int>> g(n+1);
    assert(sz(nodes) == n-1);
    auto dfs = [&](auto &&self, int node, int depth) -> void {
        if (nodes.empty()) return;
        if (sz(nodes) == d-depth){
            int v = nodes.back();
            nodes.pop_back();
            g[node].push_back(v);
            self(self,v,depth+1);
            return;
        }
        int ct = ((int)grng(min(sz(nodes),sz(nodes)-(d-depth)+1))) + 1;
        while(ct--){
            assert(!nodes.empty());
            g[node].push_back(nodes.back());
            nodes.pop_back();
        }
        for (int v : g[node])
            self(self,v,depth+1);
    };
    dfs(dfs,root,1);
    assert(nodes.empty());
    return g;
}

const ll maxn = 10, maxq = 10;

// Generate just a singular test. The multitudinous nature of tests are implemented through a bash script
void generate_test(){
    vector<vector<int>> g = generate_tree(maxn);
    int n = sz(g)-1, q = (int)grng(maxq) + 1;
    cout << n << space << q << endl;
    rep(node,1,n,1)
        if (g[node].empty()) continue;
        else for(int v : g[node]) cout << node << " " << v << endl;
    while(q--){
        int t = (int)grng(2) + 1, u = (int)grng(n)+1;
        cout << t << " " << u << endl;
    }
}