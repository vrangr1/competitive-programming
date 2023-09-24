#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
        #echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
/***************************************************
* AUTHOR : Shashwat Agrawal
* Nick : shashuiitk
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
#include <bitset>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debu
    // #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

using namespace std;

#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
// #define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
// #define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
// #define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; ((st<=end or d>0)?i<=end:i>=end); i+=d)
#define pass (void)0
#define space " "
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    int t;
    cin>>t;
    forn(i,t) {
        ll a,b,c;
        cin>>a>>b>>c;
        if (c < min(a,b)) {
             cout<<"Case #"<<i+1<<": "<<0ll<<endl;
             continue;
        }
        ll ans = max(2*(c/b)-1,max(1+2*((c-a)/b),c/a));
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
}

int main(){
	fastIO;
	TEST1;
	return 0;
}