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
* Nick : vrangr
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
#define forsn(i, st, end, d) for(int i = st; (st<=end?i<=end:i>=end); i+=d)
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

vector<int> s(2e5), b(2e5);
const ll MOD = 998244353;

int get_inverse(ll n, ll mod){
    if (n <= 1) return n;
    return (get_inverse(mod%n, mod)*(mod - mod/n))%mod;
}

void solve(){
    ll n; cin >> n;
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.begin() + n);
    ll zstart, zend, oend, start, ans=0ll;
    rep(bit, 30){
        forn(i,n)
            b[i] = s[i]>>bit;
        if (b[n-1] == 0)
            break;
        zstart = 0;
        zend = 0;
        oend = 0;
        while(zstart < n){
            start = b[zstart]>>1;
            zend = zstart;
            while(zend < n && b[zend]>>1 == start && (b[zend]&1) == 0)
                zend++;
            oend = zend;
            while(oend < n && b[oend]>>1 == start && (b[zend]&1) == 1)
                oend++;
            ans += (zend-zstart)*(oend - zend)*(2ll*__builtin_popcountll(start) + 3ll);
            ans %= MOD;
            zstart = oend;
        }
    }
    start=0;
    rep(i,n){
        if (s[i] == s[start]) continue;
        ans += (i-start)*(i-start)*(__builtin_popcountll(s[start]) + 1ll);
        ans %= MOD;
        start = i;
    }
    ans += (n-start)*(n-start)*(__builtin_popcountll(s[start])+1ll);
    ans %= MOD;
    ll inv = get_inverse((n*n)%MOD, MOD) % MOD;
    inv += MOD;
    inv %= MOD;
    ans = (ans * inv)%MOD;
    cout << ans << endl;
}