#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
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
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

vector<int> dp(2e5);

int get_coins(int start, const vector<int> &arr, vector<int> &dp, const int n){
    if (start == n) return 0;
    if (dp[start] != -1) return dp[start];
    if (start == n-1)
        return dp[start] = 0;
    if (arr[start] == -1){
        if (arr[start+1] == -1) return dp[start] = get_coins(start+1,arr,dp,n);
        dp[start] = max(get_coins(start+1,arr,dp,n), arr[start+1] + get_coins(start+2,arr,dp,n));
        return dp[start];
    }
    dp[start] = max(get_coins(start+1,arr,dp,n), arr[start]+get_coins(start+2,arr,dp,n));
    return dp[start];
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    int coins = 0;
    vector<int> arr;
    rep(i,n){
        if (arr.size() == 0){
            if (s[i] == 'B') arr.push_back(-1);
            else arr.push_back(1);
            continue;
        }
        if (s[i] == 'A' && arr.back() > 0)
            arr[arr.size()-1]++;
        else if (s[i] == 'A') arr.push_back(1);
        else arr.push_back(-1);
    }
    int k = arr.size();
    fill(dp.begin(), dp.begin() + k, -1);
    coins = get_coins(0, arr, dp, k);
    cout << coins << endl;
}