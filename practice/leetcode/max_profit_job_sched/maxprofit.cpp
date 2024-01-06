/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan  6 09:53:37 IST 2024
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> sts(n), edts(n), profit(n);
    rep(i,n) cin >> sts[i];
    rep(i,n) cin >> edts[i];
    rep(i,n) cin >> profit[i];
    auto compute = [&]{
        vector<int> order(n);
        iota(all(order),0);
        sort(all(order),[&](const int &i, const int &j){
            return edts[i] < edts[j];
        });
        vector<int> dp(n);
        dp[0] = profit[order[0]];
        for (int i = 1; i < n; ++i){
            int ind = order[i], st = sts[ind];
            int ind2 = (int)(lower_bound(order.begin(),order.begin()+i,st,[&](const int &j, const int val){
                return edts[j] <= val;
            }) - order.begin());
            debug(i,sts[ind],edts[ind],ind2);
            dp[i] = max(profit[ind],dp[i-1]);
            if (ind2 == 0 && edts[order[ind2]] > st) continue;
            if (ind2 == i || edts[order[ind2]] > st) --ind2;
            assert(edts[order[ind2]] <= st);
            dp[i] = max(dp[i], profit[ind]+dp[ind2]);
            debug(endl);
        }
        debug(dp);
        return dp[n-1];
    };
    cout << compute() << endl;
}

/*

4
1 2 3 3
3 4 5 6
50 10 40 70

5
1 2 3 4 6
3 5 10 6 9
20 20 100 70 60

3
1 1 1
2 3 4
5 6 4

6
12 7 1 17 3 2
13 11 3 19 7 3
17 4 1 16 8 5



*/