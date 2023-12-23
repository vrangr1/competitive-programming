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
	TEST;
	return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> b(n*(n-1)/2);
    rep(i,n*(n-1)/2) cin >> b[i];
    sort(b.begin(), b.end());
    vector<int> a(n);
    int ind = 1;
    a[0] = b[0];
    int lt = 0;
    debug(b);
    rep(i,n*(n-1)/2){
        if (i==0) continue;
        if(b[i] == b[i-1]){
            if (i-lt > n-ind-1){
                debug(i,lt,ind,a,n-ind-1,n);
                lt = i;
                assert(ind<n);
                a[ind++] = b[i];
            }
            continue;
        }
        assert(ind<n);
        a[ind++] = b[i];
        lt = i;
    }
    while(ind < n){
        a[ind] = a[ind - 1];
        ind++;
    }
    rep(i,n) cout << a[i] << " \n"[i==n-1];
}