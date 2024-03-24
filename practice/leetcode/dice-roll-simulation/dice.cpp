/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Mar 25 03:17:20 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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

const ll mod = (ll)1e9 + 7ll;

class Solution1 {
public:
    int dieSimulator(int n, vector<int>& rm) {
        if (n == 1) return 6;
        vector<vector<ll>> dp(n+1,vector<ll>(6,0));
        for(int d = 0; d < 6; ++d)
            dp[0][d] = dp[1][d] = 1;
        for (ll m = 2; m <= n; ++m){
            for (ll d = 0; d < 6; ++d){
                if (m <= rm[d])
                    dp[m][d] = accumulate(all(dp[m-1]),0ll)%mod;
                else
                    dp[m][d] = (accumulate(all(dp[m-1]),0ll)-dp[m-rm[d]][d]+mod)%mod;
            }
        }
        debug(dp);
        return accumulate(all(dp.back()),0ll)%mod;
    }
};

class Solution {
public:
    int dieSimulator(int n, vector<int>& rm) {
        if (n == 1) return 6;
        vector<vector<ll>> dp(n+1,vector<ll>(6,0));
        for(int d = 0; d < 6; ++d)
            dp[0][d] = dp[1][d] = 1;
        for (ll m = 2; m <= n; ++m){
            for (ll d = 0; d < 6; ++d){
                if (m <= rm[d])
                    dp[m][d] = accumulate(all(dp[m-1]),0ll)%mod;
                else
                    // dp[m][d] = (accumulate(all(dp[m-1]),0ll) - dp[m-rm[d]][d] + mod)%mod;
                for (ll p = 1; p <= rm[d]; ++p)
                    dp[m][d] += (accumulate(all(dp[m-p]),0ll)-dp[m-p][d]+mod)%mod;
            }
        }
        debug(dp);
        return accumulate(all(dp.back()),0ll)%mod;
    }
};

void solve(){
    Solution sol;
    int n; cin >> n;
    vector<int> rm(6);
    rep(i,6) cin >> rm[i];
    cout << sol.dieSimulator(n,rm) << endl;
}

/*


4
1 1 1 1 1 2

1: {1,2,3,4,5,6}
2: {21,31,41,51,61,
    12,32,42,52,62,
    13,23,43,53,63,
    14,24,34,54,64,
    15,25,35,45,65,
    16,26,36,46,56,66}

3: {
    {12,32,42,52,62,
    13,23,43,53,63,
    14,24,34,54,64,
    15,25,35,45,65,
    16,26,36,46,56,66}.1
    
    {21,31,41,51,61,
    13,23,43,53,63,
    14,24,34,54,64,
    15,25,35,45,65,
    16,26,36,46,56,66}.2
    
    {21,31,41,51,61,
    12,32,42,52,62,
    14,24,34,54,64,
    15,25,35,45,65,
    16,26,36,46,56,66}.3

    {21,31,41,51,61,
    12,32,42,52,62,
    13,23,43,53,63,
    15,25,35,45,65,
    16,26,36,46,56,66}.4

    {21,31,41,51,61,
    12,32,42,52,62,
    13,23,43,53,63,
    14,24,34,54,64,
    16,26,36,46,56,66}.5

    {21,31,41,51,61,
    12,32,42,52,62,
    13,23,43,53,63,
    14,24,34,54,64,
    15,25,35,45,65,
    16,26,36,46,56}.6
}

4: {

    {   
        {21,31,41,51,61,
        13,23,43,53,63,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56,66}.2
        
        {21,31,41,51,61,
        12,32,42,52,62,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56,66}.3

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        15,25,35,45,65,
        16,26,36,46,56,66}.4

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        14,24,34,54,64,
        16,26,36,46,56,66}.5

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56}.6
    }.1

    ...
    ...
    ...

    {
        {12,32,42,52,62,
        13,23,43,53,63,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56,66}.1
        
        {21,31,41,51,61,
        13,23,43,53,63,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56,66}.2
        
        {21,31,41,51,61,
        12,32,42,52,62,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56,66}.3

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        15,25,35,45,65,
        16,26,36,46,56,66}.4

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        14,24,34,54,64,
        16,26,36,46,56,66}.5

        {21,31,41,51,61,
        12,32,42,52,62,
        13,23,43,53,63,
        14,24,34,54,64,
        15,25,35,45,65,
        16,26,36,46,56}.6
    }.6

}




*/