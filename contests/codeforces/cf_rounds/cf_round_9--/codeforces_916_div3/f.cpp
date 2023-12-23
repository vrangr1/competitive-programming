/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec 19 21:13:35 IST 2023
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
// void solve(int t);
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	// int T;cin>>T;rep(t,T)solve(t);
    TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> edges(n);
    rep(i,n-1){
        int v; cin >> v; --v;
        edges[v].push_back(i+1);
    }
    vector<int> ss(n,0), cts(n,0);
    auto dfs = [&] (auto &&self, int node) -> void {
        if (sz(edges[node]) == 0) return void(++ss[node]);
        int mx = 0, mxind = -1;
        for (int ngb : edges[node]){
            self(self,ngb);
            ss[node] += ss[ngb];
            if (mx < ss[ngb]){
                mx = ss[ngb];
                mxind = ngb;
            }
        }
        int tot = ss[node]++;
        if (mx <= tot/2) return void(cts[node] = tot/2);
        cts[node] = tot - mx;
        cts[node] += min((mx-cts[node])/2, cts[mxind]);
    };
    dfs(dfs,0);
    cout << cts[0] << endl;
}