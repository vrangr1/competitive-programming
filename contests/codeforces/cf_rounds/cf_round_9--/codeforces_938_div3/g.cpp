/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Apr  8 20:42:42 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
#endif
// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class DSU{
public:
    int n;
    vector<int> parent,rank;
    DSU(int gn):parent(gn,-1),rank(gn,0){
        n = gn;
    }

    void clear(){
        fill(all(parent),-1);
        fill(all(rank),0);
    }

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) swap(px,py);
        parent[px] = py;
        if (rank[px] == rank[py]) ++rank[py];
        rank[px] = rank[py];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n)
        rep(j,m)
            cin >> a[i][j];
    auto get_fac = [](int val) -> vector<int> {
        set<int> facs;
        int sq = bsqrt(val);
        rep(f,1,sq+10,1){
            if (f > val) break;
            if (val%f) continue;
            facs.insert(f);
            facs.insert(val/f);
        }
        return vector<int>(all(facs));
    };
    vector<int> f1 = get_fac(a[0][0]), f2 = get_fac(a[n-1][m-1]), facs;
    assert(is_sorted(all(f1)));
    assert(is_sorted(all(f2)));
    facs.resize(max(sz(f1),sz(f2)));
    facs.erase(set_intersection(all(f1),all(f2),facs.begin()),facs.end());
    if (facs.empty()) return void(cout << "1\n");
    sort(rall(facs));
    auto get = [&](int x, int y) -> int {
        return x*m+y;
    };
    DSU dsu(get(n-1,m-1)+1);
    auto eval = [&](int f) -> bool {
        dsu.clear();
        rep(i,n){
            rep(j,m){
                if (!i && !j) continue;
                if (a[i][j]%f) continue;
                if (!i){
                    if (a[i][j-1]%f == 0)
                        dsu.unite(get(i,j),get(i,j-1));
                    continue;
                }
                if (!j){
                    if (a[i-1][j]%f == 0)
                        dsu.unite(get(i,j),get(i-1,j));
                    continue;
                }
                if (a[i][j-1]%f == 0)
                    dsu.unite(get(i,j),get(i,j-1));
                if (a[i-1][j]%f == 0)
                    dsu.unite(get(i,j),get(i-1,j));
            }
        }
        return dsu.find(get(0,0)) == dsu.find(get(n-1,m-1));
    };
    for (int f : facs){
        if (eval(f)) return void(cout << f << endl);
    }
    cout << "1\n";
}