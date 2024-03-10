/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar  9 17:39:11 IST 2024
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    string t; cin >> t;
    int n; cin >> n;
    int m = sz(t);
    vector<int> dp(m,-1);
    auto match = [&](string &s, int ind){
        int l = sz(s);
        rep(i,l)
            if (s[i] != t[ind+i]) return false;
        return true;
    };
    rep(i,n){
        int a; cin >> a;
        vector<pair<int,int>> updates;
        rep(j,a){
            string s; cin >> s;
            int l = sz(s);
            rep(k,m-l+1){
                if (s[0] != t[k]) continue;
                int cost = (k==0?0:dp[k-1]);
                if (cost == -1) continue;
                if (match(s,k)) updates.emplace_back(k+l-1,cost+1);
            }
        }
        for (auto [ind,cost] : updates)
            if (dp[ind] == -1) dp[ind] = cost;
            else dp[ind] = min(dp[ind],cost);
    }
    cout << dp[m-1] << endl;
}