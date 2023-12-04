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
    int n,k; cin >> n >> k;
    vector<int> a(n), left_limits(k), right_limits(k);
    vector<bool> vals(k,false);
    left_limits[0] = 0;
    right_limits[0] = n-1;
    int mx = 0;
    rep(i,n){
        cin >> a[i];
        --a[i];
        vals[a[i]] = true;
        if (a[i] > mx){
            rep(j, mx+1, a[i], 1)
                left_limits[j] = i;
            mx = a[i];
        }
    }
    mx = 0;
    rep(i,n-1,0,-1){
        if (a[i] > mx){
            rep(j, mx+1, a[i], 1)
                right_limits[j] = i;
            mx = a[i];
        }
    }
    vector<ll> ans(k);
    ll side;
    debug(vals);
    rep(i,k){
        if (!vals[i]){
            ans[i] = 0;
            continue;
        }
        side = right_limits[i] - left_limits[i] + 1ll;
        ans[i] = side+side;
    }
    rep(i,k)
        cout << ans[i] << " \n"[i==k-1];
}