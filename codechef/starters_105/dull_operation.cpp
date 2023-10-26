#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
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
#include <random>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
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
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const int limit = (1<<30);

bool possible(int xyor, int xyxor, int &x, int &y){
    int temp = xyxor, bit;
    while(temp > 0){
        bit = (temp&(-temp));
        if ((xyor&bit) == 0) return false;
        temp -= bit;
    }
    x = xyor;
    y = x^xyxor;
    // debug(xyxor, xyor, x, y, (x|y), (x^y));
    return (x < limit && y < limit);
}

void solve(){
    int n; cin >> n;
    int rt = sqrt(n);
    if (rt < limit && rt*rt == n) return void(cout << "0 " << rt << endl);
    debug(rt);
    rep(i,1,rt,1){
        if (n%i) continue;
        debug(i);
        int x, y;
        if (possible(n/i,i,x,y)){
            assert((x|y)*(x^y) == n);
            cout << x << " " << y << endl;
            return;
        }
        if (possible(i,n/i,x,y)){
            assert((x|y)*(x^y) == n);
            cout << x << " " << y << endl;
            return;
        }
        // if ((x|y)*(x^y) == n) return void(cout << x << " " << y << endl);
    }
    assert(false);
}

/*
21 -> 7 4
35 -> 7 2
x|y = a
x^y = b



*/