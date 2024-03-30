/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 22:52:09 IST 2023
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> edges(n+1);
    vector<int> deg(n+1,0);
    rep(i,m){
        ll u, v; cin >> u >> v;
        edges[u].push_back(v);
        deg[v]++;
    }
    vector<bool> vis(n+1,false);
    vector<bool> viscur(n+1,false);
    vector<bool> stat(n+1,false);
    vector<ll> rt;
    auto getct = [&] (auto &&self, ll node) -> void {
        rep(i,node,n,node){
            stat[i] = !stat[i];
        }
        rt.push_back(node);
        vis[node] = true;
        viscur[node] = true;
        for (auto ngb : edges[node]){
            if (viscur[ngb]) continue;
            self(self,ngb);
        }
    };
    ll mx = (n)/5ll;
    rep(i,1,n,1){
        if (deg[i] > 0) continue;
        rt.clear();
        fill(all(stat),false);
        // fill(all(viscur),false);
        getct(getct,i);
        ll cur = count(all(stat),true);
        debug(i,cur);
        for (auto ind : rt)
            viscur[ind] = false;
        if (cur > 0 && cur <= mx){
            cout << sz(rt) << endl;
            print_vec(rt);
            return;
        }
    }
    rep(i,1,n,1) assert(vis[i]);
    cout << "-1\n";
    debug(endl);
}

/*

4

1
4 0

1
5 2
4 1
5 1

15 9
7 8
8 9
9 10
10 9
11 1
12 2
13 3
14 4
15 5

5 4
1 2
2 3
3 4
4 5



*/