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
    const bool DEBUG = false;
#else
    const bool DEBUG = false;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST ll T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

ll get_mex(const vector<ll> &counts){
    for (ll i = 0; i < counts.size(); ++i)
        if (counts[i] == 0) return i;
    assert(false);
    return -1;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n), counts(n+1,0);
    rep(i,n){
        cin >> a[i];
        if (a[i] <= n) counts[a[i]]++;
    }
    ll mex = get_mex(counts), m;
    ll minm = mex*(counts[0]-1ll);
    if (minm == 0) return void(cout << "0\n");
    vector<ll> dp(mex,0);
    dp[0] = 0;
    dp[1] = counts[0]-1ll;
    for (ll i = 2; i < mex; ++i){
        dp[i] = i*(counts[0]-1ll);
        for (ll j = 1; j < i; ++j)
            dp[i] = min(dp[i], i*(counts[j]-1ll) + j + dp[j]);
    }
    debug(counts, mex, dp, minm);
    for (ll i = 1; i < mex; ++i){
        minm = min(mex*(counts[i]-1ll) + i + dp[i], minm);
    }
    cout << minm << endl;
}



/*

 0000000 1111 22 333 444 ... .. .. ... mex
  0 -> mex * (ct0-1)
  1 -> mex * (ct1-1) + 1 + ct0-1
  2 -> mex * (ct2-1) + 2 + min(2*(ct0-1) + 0, 2*(ct1-1) + 1 + ct0)
  3 -> mex * ct3 + min(3*ct2 + min(2*ct0, 2*ct1 + ct0), 3*ct1 + ct0, 3*ct0)
  4 -> mex * ct4 + min(4*ct3 + min(3*ct2 + min(2*ct0, 2*ct1 + ct0), 3*ct1 + ct0, 3*ct0), 4*ct2 +...)

  mex*cti + 
  0 -> 0
  1 -> ct0-1
  2 -> min(2*(ct0-1) + 0, 2*(ct1-1) + 1 + ct0-1) = min(2*(ct0-1) + 0, 2*(ct1-1) + 1 + v1)
  3 -> min(3*(ct2-1) + 2 + v2, 3*ct1 + v1, 3*ct0)
  4 -> min(4*ct3 + v3, 4*ct2 + v2, 4*ct1 + v1, 4*ct0)
  
*/

// 1
// 8
// 5 2 1 0 3 0 4 0