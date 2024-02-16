/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Feb 14 21:01:41 IST 2024
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
#ifndef IMPORT_HASH_SET_SNIPPET
#define IMPORT_HASH_SET_SNIPPET
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
typedef long long int ll;
using namespace std;

// Source: Neal Wu (codeforces handle: neal)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename type>
using hash_set = conditional_t <is_same<type,int>::value || is_same<type,ll>::value, unordered_set<type, custom_hash>, unordered_set<type>>;

template<typename t1, typename t2>
using hash_map = conditional_t<is_same<t1,ll>::value || is_same<t1,int>::value, unordered_map<t1, t2, custom_hash>, unordered_map<t1,t2>>;

template <typename type>
using hash_multiset = conditional_t<is_same<type,int>::value || is_same<type,ll>::value, unordered_multiset<type, custom_hash>, unordered_multiset<type>>;

template<typename t1, typename t2>
using hash_multimap = conditional_t<is_same<t1,int>::value || is_same<t2,ll>::value, unordered_multimap<t1, t2, custom_hash>, unordered_multimap<t1,t2>>;

#endif // IMPORT_HASH_SET_SNIPPET
// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class DSU{
private:
    const pair<int,int> null = {-1,-1};
    pair<int,int> get_parent(pair<int,int> pr){
        if (parent.find(pr) != parent.end()) return parent[pr];
        return parent[pr] = null;
    }
    int get_rank(pair<int,int> pr){
        if (rank.find(pr) != rank.end()) return rank[pr];
        return rank[pr] = 0;
    }
public:
    unordered_map<pair<int,int>,pair<int,int>,hash_pair> parent;
    unordered_map<pair<int,int>,int,hash_pair> rank;
    DSU(){
        parent.clear();
        rank.clear();
    }

    pair<int,int> find(pair<int,int> x){
        if (get_parent(x) == null) return x;
        else return parent[x] = find(parent[x]);
    }

    void unite(pair<int,int> x, pair<int,int> y){
        pair<int,int> px = find(x), py = find(y);
        if (px == py) return;
        if (get_rank(px) < get_rank(py)){
            parent[px] = py;
            rank[px] = rank[py];
        }
        else if (get_rank(px) > get_rank(py)){
            parent[py] = px;
            rank[py] = rank[px];
        }
        else{
            parent[px] = py;
            rank[px] = ++rank[py];
        }
    }
};

#define up 0
#define right 1
#define down 2
#define left 3
#define botleft 4
#define upright 5
#define none 6

void solve(){
    int n, m; cin >> n >> m;
    auto valid = [&](int x, int y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };
    auto getdir = [&](pair<int,int> pt){
        assert(pt.first != 1 || pt.second != 1);
        assert(pt.first != n || pt.second != n);
        if (pt.first == n && pt.second == 1) return botleft;
        if (pt.first == 1 && pt.second == n) return upright;
        if (pt.first == 1) return up;
        if (pt.first == n) return down;
        if (pt.second == 1) return left;
        if (pt.second == n) return right;
        return none;
    };
    vector<vector<pair<int,int>>> dirpts(none+1);
    DSU dsu;
    set<pair<int,int>> pts;
    rep(i,m){
        int x, y; cin >> x >> y;
        pair<int,int> pt = {x,y};
        if (valid(x+1,y)){
            pair<int,int> pr = {x+1,y};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x,y+1)){
            pair<int,int> pr = {x,y+1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x-1,y)){
            pair<int,int> pr = {x-1,y};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x,y-1)){
            pair<int,int> pr = {x,y-1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x-1,y-1)){
            pair<int,int> pr = {x-1,y-1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x+1,y-1)){
            pair<int,int> pr = {x+1,y-1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x+1,y+1)){
            pair<int,int> pr = {x+1,y+1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        if (valid(x-1,y+1)){
            pair<int,int> pr = {x-1,y+1};
            if (pts.find(pr) != pts.end())
                dsu.unite(pt,pr);
        }
        pts.emplace(x,y);
        dirpts[getdir(pt)].push_back(pt);
    }
    vector<vector<pair<int,int>>> parents(none);
    int mx = 0;
    rep(dir,none){
        for(auto &pr : dirpts[dir])
            parents[dir].push_back(dsu.find(pr));
        sort(all(parents[dir]));
        mx = max(mx,(int)sz(parents[dir]));
    }
    vector<pair<int,int>> ints(mx);
    auto block = [&](int dir1, int dir2){
        auto it = set_intersection(all(parents[dir1]),all(parents[dir2]),ints.begin());
        return it != ints.begin();
    };
    if (block(up,down)) return void(cout << no);
    if (block(up,left)) return void(cout << no);

    if (block(right,left)) return void(cout << no);
    if (block(right,down)) return void(cout << no);

    if (block(botleft,upright)) return void(cout << no);
    if (block(botleft,right)) return void(cout << no);
    if (block(botleft,up)) return void(cout << no);
    
    if (block(upright,down)) return void(cout << no);
    if (block(upright,left)) return void(cout << no);

    cout << yes;
}