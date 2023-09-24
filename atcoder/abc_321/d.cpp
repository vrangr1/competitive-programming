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

void solve(){
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    if (n > m){
        swap(n,m);
        swap(a,b);
    }
    sort(all(b));
    vector<ll> psum(m);
    partial_sum(b.begin(), b.end(), psum.begin());
    debug(n,m,a,b,psum);
    vector<ll>::iterator iter;
    ll sum = 0ll, ind;
    for(ll i = 0ll; i < n; ++i){
        if (a[i] >= p){
            sum += p*m;
            continue;
        }
        iter = upper_bound(all(b), (ll)p-a[i]);
        if (iter == b.begin()){
            sum += p*m;
            continue;
        }
        if (iter == b.end()){
            sum += m*a[i] + psum[m-1];
            continue;
        }
        ind = (ll)(iter-b.begin());
        // debug(a[i]);
        // debug(ind);
        // debug(sum);
        sum = sum + (ll)psum[ind-1] + (ll)a[i]*ind;
        // debug(sum);
        sum = sum + (ll)p*(m-ind);
        // debug(sum,endl);
    }
    cout << sum << endl;
}