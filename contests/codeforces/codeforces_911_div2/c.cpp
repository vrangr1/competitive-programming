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

const char up = 'U', lchar = 'L', rchar = 'R';

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> edges(n);
    rep(i,n){
        int l, r;
        cin >> l >> r;
        --l;--r;
        edges[i].push_back(l);
        edges[i].push_back(r);
    }
    vector<ll> minmoves(n,INT_MAX);
    auto dfs = [&](auto self, int node) -> void {
        assert(node < edges.size());
        assert(edges[node].size() == 2);
        int l = edges[node][0];
        int r = edges[node][1];

        if (l == -1 && r == -1){
            minmoves[node] = 0;
            return;
        }
        if (l != -1){
            if (l >= minmoves.size() || l < 0){
                debug(l);
                exit(0);
            }
            assert(l < minmoves.size() && l > 0);
            self(self,l);
            assert(minmoves[l] != INT_MAX);
            assert(node < (int)s.size());
            minmoves[node] = minmoves[l] + (s[node] != lchar);
        }
        if (r != -1){
            assert(r < minmoves.size() && r > 0);
            self(self,r);
            assert(minmoves[r] != INT_MAX);
            assert(node < (int)s.size());
            if (minmoves[node] != INT_MAX)
                minmoves[node] = min(minmoves[node], minmoves[r] + (s[node] != rchar));
            else minmoves[node] = minmoves[r] + (s[node] != rchar);
        }
    };
    dfs(dfs,0);
    assert(minmoves[0] != INT_MAX);
    cout << minmoves[0] << endl;
}