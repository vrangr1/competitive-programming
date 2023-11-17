/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> ogedges, edges(n);
    int u, v;
    rep(i,n-1){
        cin >> u >> v; --u; --v;
        ogedges.push_back({u,v});
    }
    vector<int> p(n), mapping(n);
    rep(i,n){
        cin >> p[i]; --p[i];
        mapping[p[i]] = i;
    }
    rep(i,n-1){
        u = mapping[ogedges[i][0]];
        v = mapping[ogedges[i][1]];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<vector<vector<int>>> queries(n);
    int l, r, x;
    rep(i,q){
        cin >> l >> r >> x;
        --l; --r; --x;
        x = mapping[x];
        queries[x].push_back({l,r,i});
    }
    // vector<int> enc;
    // set<int> enc;
    int root = mapping[0];
    vector<bool> sol(q,false);
    // vector<int>::iterator iter;
    set<int>::iterator iter;
    auto dfs = [&](auto self, const int &node, const int parent) -> set<int>{
        set<int> enc, temp;
        for (int ngb : edges[node]){
            if (ngb == parent) continue;
            temp = self(self,ngb,node);
            enc.insert(all(temp));
        }
        // enc.push_back(node);
        enc.insert(node);
        debug(node,enc,queries[node]);
        for (const vector<int> &query : queries[node]){
            // iter = lower_bound(all(enc), query[0]);
            iter = enc.lower_bound(query[0]);
            if (iter == enc.end() || *iter > query[1]){
                sol[query[2]] = false;
            }
            else{
                sol[query[2]] = true;
            }
        }
        return enc;
    };
    dfs(dfs,root,-1);
    rep(i,q){
        if (sol[i]) cout << yes;
        else cout << no;
    }
    cout << endl;
}


/*

1
10 10
2 6
2 7
2 4
1 7
2 8
10 6
8 5
9 4
3 4
10 2 5 9 1 7 6 4 3 8
8 9 8
7 8 1
7 10 6
4 8 9
5 5 10
7 10 1
9 9 2
9 10 6
6 6 2
10 10 6

*/