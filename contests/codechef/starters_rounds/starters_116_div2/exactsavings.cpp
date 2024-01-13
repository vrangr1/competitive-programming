/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan 10 20:36:15 IST 2024
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

void solve(){
    ll n, x, z; cin >> n >> x >> z;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (z%x == 0ll) return void(cout << z/x << endl);
    vector<ll> b(n);
    ll r = x-(z%x);
    rep(i,n) b[i] = (a[i])%x;
    vector<bool> sums(x+1ll,false);
    vector<vector<ll>> adj(x,vector<ll>(x,LLONG_MAX));
    sums[0] = true;
    rep(i,n){
        assert(b[i] < x);
        rep(s,x-1ll,0ll,-1ll){
            ll sub = (s-b[i]+x)%x;
            if (!sums[sub]) continue;
            sums[s] = true;
            if (sub == 1 && b[i] == 0ll) debug(sub,s,b[i],a[i]);
            adj[sub][s] = min(adj[sub][s], a[i]);
        }
    }
    if (!sums[r]) return void(cout << "-1\n");
    vector<vector<vector<ll>>> edges(x);
    rep(i,x){
        rep(j,x){
            if (adj[i][j] == LLONG_MAX || i==j) continue;
            edges[i].push_back({j,adj[i][j]});
        }
    }
    debug(a,n,x,z,r,sums,adj,edges);
    auto dijkstra = [&](const ll src, const ll dest) -> ll {
        auto comp = [](const vector<ll> &a, const vector<ll> &b){
            return a[1] > b[1];
        };
        priority_queue<vector<ll>,vector<vector<ll>>, decltype(comp)>pq(comp);
        pq.push({src,0ll});
        vector<bool> vis(x,false);
        vector<ll> res(x,LLONG_MAX);
        res[src] = 0ll;
        while(!pq.empty()){
            vector<ll> cur = pq.top();
            ll node = cur[0];
            ll w = cur[1];
            pq.pop();
            if (node == dest) return w;
            if (vis[node]) continue;
            vis[node] = true;
            assert(w == res[node]);
            for (auto &edge : edges[node]){
                ll ngb = edge[0], ew = edge[1];
                if (vis[ngb]) assert(w+ew>=res[ngb]);
                if (vis[ngb] || w+ew >= res[ngb]) continue;
                res[ngb] = w+ew;
                pq.push({ngb,res[ngb]});
            }
        }
        return res[dest];
    };
    ll sol = dijkstra(0,r);
    debug(sol);
    assert(sol != LLONG_MAX && (sol+z)%x == 0ll);
    cout << (sol+z)/x << endl;
}