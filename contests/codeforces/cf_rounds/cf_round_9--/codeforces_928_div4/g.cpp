/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Feb 19 21:41:00 IST 2024
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

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

#define party 0
#define sil 1
#define both 2

void solve(){
    int n; cin >> n;
    vector<vector<int>> edges(n);
    rep(i,1,n-1,1){
        int a; cin >> a;
        --a;
        edges[i].push_back(a);
        edges[a].push_back(i);
    }
    string t; cin >> t;
    vector<int> s(n);
    rep(i,n)
        if (t[i] == 'P') s[i] = party;
        else if (t[i] == 'S') s[i] = sil;
        else s[i] = both;
    int sol = 0;
    auto dfs = [&](auto &&self, int node, int parent) -> int {
        int type = s[node];
        if (sz(edges[node]) == 1 && edges[node][0] == parent)
            return type;
        vector<int> ct(3,0);
        for (int ngb : edges[node]){
            if (ngb == parent) continue;
            ct[self(self,ngb,node)]++;
        }
        if (type == sil){
            sol += ct[party];
        }
        else if (type == party){
            sol += ct[sil];
        }
        else{
            sol += min(ct[party],ct[sil]);
            if (ct[party] == ct[sil]){
                if (parent == -1) return type;
                if (s[parent] == sil) return sil;
                else if (s[parent] == party) return party;
                return type;
            }
            if (ct[party] > ct[sil]) return party;
            else return sil;
        }
        return type;
    };
    dfs(dfs,0,-1);
    cout << sol << endl;
}