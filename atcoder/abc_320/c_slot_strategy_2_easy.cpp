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

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST1;
	return 0;
}

inline int max(int a, int b, int c){
    return max(max(a,b),c);
}

void solve(){
    int m; cin >> m;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int iter1, iter2;
    int ans = INT_MAX;
    rep(i,m){
        iter1 = INT_MAX;
        iter2 = INT_MAX;
        rep(j,m){
            if (s2[j] != s1[i]) continue;
            iter1 = j;
            if (iter1 == i)
                iter1 += m;
            rep(k,m){
                if (s3[k] != s1[i]) continue;
                iter2 = k;
                while(iter2 == i || iter2 == iter1){
                    iter2 += m;
                }
                ans = min(ans,max(i, iter1, iter2));
            }
        }
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}