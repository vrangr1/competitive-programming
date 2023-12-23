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
    const bool DEBUG = true;
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
typedef long double ld;
int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll mod = 1e9+7;

inline ll logab(ld a, ld b){
    ll ans = (log2l(a)/log2l(b)+1e-6);
    if ((ll)powl(b,ans+1ll) <= (ll)a) return ans+1ll;
    if ((ll)powl(b,ans) > (ll)a) return ans-1ll;
    return ans;
}

ll get_next(ll cur, ll base){
    ll anx = logab(cur,base)+1ll;
    return ((ll)powl(base,anx))-1ll;
}


ll get_sum(ll l, ll r, ll base){
    ll cur = l, sum = 0ll;
    while(cur <= r){
        ll nx = get_next(cur,base);
        if (logab(nx+1ll,base) == logab(cur,base)){
            debug(cur, nx+1ll, base, logab(nx+1ll,base), logab(cur,base), endl);
        }
        assert(logab(nx+1ll,base) != logab(cur,base));
        nx = min(nx, r);
        if (logab(nx,base) != logab(cur,base)){
            debug(cur, nx, base, logab(nx,base), logab(cur,base), endl);
        }
        assert(logab(cur,base) == logab(nx,base));
        sum += ((nx-cur+1ll)*logab(cur,base))%mod;
        sum %= mod;
        cur = nx+1;
    }
    return sum;
}

void solve(){
    ll l, r; cin >> l >> r;
    ll cur = l;
    ll sum = 0;
    while(cur <= r){
        ll nx = get_next(cur,2);
        if (logab(nx+1ll,2) == logab(cur,2)){
            debug(cur, nx+1ll, 2, logab(nx+1ll,2), logab(cur,2), endl);
        }
        assert(((ll)logab(nx+1,2)) != ((ll)logab(cur,2)));
        nx = min(nx, r);
        if (logab(nx,2) != logab(cur,2)){
            debug(cur, nx, 2, logab(nx,2), logab(cur,2), endl);
        }
        assert(((ll)logab(cur,2)) == ((ll)logab(nx,2)));
        ll base = logab(cur,2);
        sum += get_sum(cur,nx,base);
        sum %= mod;
        cur = nx+1;

    }
    cout << sum << endl;
}