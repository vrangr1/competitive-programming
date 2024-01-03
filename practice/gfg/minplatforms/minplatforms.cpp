/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jan  1 10:26:20 IST 2024
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


// Shashwat's solution: debugging
void solve(){
    int n; cin >> n;
    vector<int> arr(n),dep(n);
    rep(i,n) cin >> arr[i];
    rep(i,n) cin >> dep[i];
    auto compute = [&](){
        vector<int> index(n);
    	iota(index.begin(),index.end(),0);
    	sort(index.begin(),index.end(),[&](const int i, const int j){return dep[i]<dep[j];});
    	priority_queue<int,vector<int>,greater<int>> pq;
    	for(auto i:index) {
    	    if (pq.size() and arr[i] > pq.top()) {
    	        pq.pop();
    	    }
    	    pq.push(dep[i]);
    	}
    	return pq.size();
    };
    cout << compute() << endl;
}

/*

6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000


5
8 0 2 4 11
17 7 8 12 14
0 1 2  3  4
0 2 4  11 8
7 8 12 14 17

 [ (0,0) (2,0) (4,0) (7,1) (8,0) (8,1) (11,0) (12,1) (14,1) (17,1) ]
 0 1 2 0 4 1 3 2 3 4
 ( ( ( ) ( ) ( ) ) )
*/