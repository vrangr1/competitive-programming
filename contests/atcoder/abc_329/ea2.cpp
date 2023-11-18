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
#define yes "Yes\n"
#define no "No\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

bool match(const string &s, const string &t, int i, int ind){
    while(i < sz(s) && ind < sz(t)){
        if (s[i++] == t[ind++]) continue;
        else return false;
    }
    return ind == sz(t);
}

void solve(){
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<vector<int>> dp(n,vector<int>(5,-1));
    auto recurse = [&](auto self, int start, int ind) -> int {
        if (start == n-1) return dp[start][ind] = ((ind == m-1) && s.back() == t.back());
        assert(start < n);
        assert(ind < m);
        if (dp[start][ind] != -1) return dp[start][ind];
        if (s[start] != t[ind]) return dp[start][ind] = false;
        dp[start][ind] = false;
        if (ind == m-1){
            rep(i,m){
                dp[start][ind] = self(self,start+1, i);
                if (dp[start][ind]) break;
            }
            return dp[start][ind];
        }
        dp[start][ind] = self(self,start+1,ind+1);
        if (dp[start][ind]) return true;
        dp[start][ind] = self(self,start+1,0);
        return dp[start][ind];
    };
    int ans = recurse(recurse,0,0);
    if (ans == 1) cout << yes;
    else cout << no;
    debug(ans, dp);
}