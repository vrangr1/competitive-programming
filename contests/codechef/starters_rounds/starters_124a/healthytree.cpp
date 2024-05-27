/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar  6 20:38:28 IST 2024
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

// Subtask 1 only
void solve1(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n,-1), ct(n,0), stat(n,0);
    depth[0] = 0;
    auto procdepth = [&](auto &&self, int node, int parent, int d) -> void {
        depth[node] = d;
        for (int v : g[node]){
            if (v == parent) continue;
            self(self,v,node,d+1);
        }
    };
    procdepth(procdepth,0,-1,0);
    debug(n,depth,ct,stat);
    int oct = 0;
    while(q--){
        int t, u;
        cin >> t >> u;
        --u;
        if (t == 1){
            // assert(u==0);
            if(u==0)
            cout << oct << endl;
        }
        else{
            assert(u>=0);
            assert(u < sz(stat));
            stat[u] = 1-stat[u];
            if (u == 0) continue;
            assert(u < sz(depth));
            assert(depth[u] < sz(ct));
            assert(depth[u] >= 0);
            assert(ct[depth[u]] >= 0);
            if (ct[depth[u]] == 1) oct--;
            if (stat[u])
                ct[depth[u]]++;
            else
                ct[depth[u]]--;
            assert(ct[depth[u]] >= 0);
            if (ct[depth[u]] == 1) oct++;
        }
    }
}

// Subtasks 1,2
void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> stat(n,0), queries, depth(n,0);
    vector<pair<int,int>> updates;
    auto procdepth = [&](auto &&self, int node, int parent, int d) -> void {
        depth[node] = d;
        for (int v : g[node]){
            if (v == parent) continue;
            self(self,v,node,d+1);
        }
    };
    procdepth(procdepth,0,-1,0);
    auto subtask1 = [&]() -> void {
        vector<int> ct(n,0);
        int oct = 0;
        fill(all(stat),0);
        for (auto [t,u] : updates){
            if (t == 1){
                assert(u==0);
                cout << oct << endl;
            }
            else{
                stat[u] = 1-stat[u];
                if (u == 0) continue;
                if (ct[depth[u]] == 1) oct--;
                if (stat[u]) ct[depth[u]]++;
                else ct[depth[u]]--;
                if (ct[depth[u]] == 1) oct++;
            }
        }
    };
    while(q--){
        int t, u;
        cin >> t >> u;
        --u;
        if (t == 1){
            queries.push_back(u);
            updates.emplace_back(1,u);
        }
        else{
            stat[u] = 1-stat[u];
            updates.emplace_back(2,u);
        }
    }
    if (*max_element(all(queries)) == 0){
        subtask1();
        return;
    }
    vector<int> sol(n,0);
    auto dfs = [&](auto &&self, int node, int p) -> unordered_set<int> {
        unordered_set<int> st;
        for (int v : g[node]){
            if (v == p) continue;
            unordered_set<int> temp = self(self,v,node);
            if (sz(temp) > sz(st)) swap(st,temp);
            for (int nd : temp){
                if (st.find(nd) == st.end()) st.insert(nd);
                else st.erase(nd);
            }
        }
        sol[node] = sz(st);
        assert(st.find(depth[node]) == st.end());
        if (stat[node])
        st.insert(depth[node]);
        return st;
    };
    dfs(dfs,0,-1);
    for (int qr : queries)
        cout << sol[qr] << endl;
}

// All subtasks
void solve3(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v; cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

}