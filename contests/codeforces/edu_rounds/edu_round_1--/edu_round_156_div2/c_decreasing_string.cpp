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

inline ll compute_len(ll ct, ll n){
    return (((n*(n+1ll))/2ll) - (((n-ct)*(n-ct+1ll))/2ll));
}

ll b_sch(ll low, ll high, ll pos, ll n){
    if (low > high) return -1;
    if (low == high) return low;
    ll mid = (low+high)/2ll;
    if (mid == low) mid++;
    if (compute_len(mid, n) < pos){
        low = mid;
        return b_sch(low, high, pos, n);
    }
    return b_sch(low,mid-1ll,pos,n);
}

void solve(){
    string s; cin >> s;
    ll pos; cin >> pos;
    ll n = s.size();
    ll ct = 0, og;
    // if (pos > n)
    ct = b_sch(0ll,n-1ll, pos, n);
    og = ct;
    pos -= compute_len(ct,n);
    pos--;
    debug(ct,pos);
    assert(pos >= 0ll && pos < n-ct);
    string after = "";
    for (int i = 0; i < n; ++i){
        while(ct > 0 && !after.empty() && after.back() > s[i]){
            ct--;
            after.pop_back();
        }
        after.push_back(s[i]);
        // if (s[i] <= s[i+1]){
        //     after.push_back(s[i]);
        //     continue;
        // }
        // if (ct == 0) after.push_back(s[i]);
        // else ct--;
    }
    // after.push_back(s[n-1]);
    after = after.substr(0, after.size()-ct);
    debug(after,after.size(),n,n-og);
    assert((ll)after.size() == n-og);
    cout << after[pos];
}

/*

3

1
cab
6

abcd
9

x
1

*/