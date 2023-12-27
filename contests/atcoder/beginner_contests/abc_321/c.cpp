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
	TEST1;
	return 0;
}

void increment(vector<ll> &num, ll &sz){
    for (ll ind = 0; ind < num.size(); ++ind){
        // if (ind == 9){
        //     assert(num[ind] < 9);
        //     num[ind]++;
        //     return;
        // }
        if (num[ind] == 9){
            num[ind] = 0;
            continue;
        }
        if (num[ind] < num[ind+1]-1 || ind == sz || ind == sz-1){
            num[ind]++;
            if (ind==sz) sz++;
            return;
        }
        assert(ind < 9);
        num[ind] = 0;
    }
}

void solve(){
    ll k; cin >> k;
    if (k == 1) return void(cout << "1\n");
    vector<ll> num(20,0);
    ll sz = 0;
    for (ll i = 1; i <= k; ++i){
        increment(num,sz);
        while(count(num.begin(),num.begin() + sz, 0) > 1)
            increment(num,sz);
        debug(i,num,sz);
    }
    ll ans = 0;
    debug(num);
    rep(i,9,0,-1){
        ans = (10ll)*ans + num[i];
    }
    cout << ans << endl;
}