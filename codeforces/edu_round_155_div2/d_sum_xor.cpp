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
const ll mod = 998244353;
vector<int> a(3e5);
void solve(){
    int mx=INT_MIN, num, n;
    cin >> n;
    ll ans = 0ll, one_pathsum, one_pathcount, zero_pathsum, zero_pathcount, tps, tpc;
    rep(i,n){
        cin >> a[i];
        mx = max(a[i],mx);
    }
    rep(bit, 32){
        num = 1ll<<(ll)bit;
        if (num > mx) break;
        one_pathsum = one_pathcount = (ll)((a[0]&num) > 0);
        zero_pathsum = zero_pathcount = 1ll-one_pathsum;
        ans += (num*(one_pathsum%mod))%mod;
        ans %= mod;
        rep(i,1,n-1,1){
            if (a[i]&num){
                tps = zero_pathsum;
                tpc = zero_pathcount;
                zero_pathsum = one_pathsum+one_pathcount;
                zero_pathcount = one_pathcount;
                one_pathsum = tps+tpc+1ll;
                one_pathcount = tpc+1ll;
            }
            else{
                zero_pathsum = zero_pathsum+zero_pathcount+1ll;
                zero_pathcount = zero_pathcount+1ll;
                one_pathsum = one_pathsum+one_pathcount;
                one_pathcount = one_pathcount;
            }
            ans += (num*(one_pathsum%mod))%mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}