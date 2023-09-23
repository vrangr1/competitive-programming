#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
        # echo "\noutput begins now:"
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
    const bool DEBUG = true;
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
void solve(int T);

int main(){
	fastIO;
	int T;
    cin >> T;
    rep(t,T)
        solve(t+1);
	return 0;
}

bool check(vector<ll> a, ll ind){
    a.erase(a.begin() + ind);
    ll n = a.size();
    ll init = a[0] + a[n-1];
    rep(i,1,n/2,1){
        if (init != a[i] + a[n-i-1]) return false;
    }
    return true;
}

bool analyze_and_print(vector<ll> &a, ll init, int ind){
    if (check(a,ind)){
        if (init - a[ind] > 0) cout << init-a[ind] << endl;
        else cout << "-1\n";
        return true;
    }
    return false;
}

void solve(int T){
    cout << "Case #" << T << ": ";
    ll n; cin >> n;
    vector<ll> a(2*n-1);
    rep(i,2*n-1) cin >> a[i];
    if (n == 1ll) return void(cout << "1\n");
    sort(all(a));
    ll init = a[0] + a[2*n-2];
    ll i = 1;
    while(i<=n-2){
        if (a[i] + a[2*n-i-2] != init) break;
        i++;
    }
    if (i == n-1){
        if (init - a[n-1] > 0) cout << init-a[n-1] << endl;
        else cout << "-1\n";
        return;
    }
    if (i > 1){
        if (analyze_and_print(a, init, i)) return;
        else if(analyze_and_print(a, init, 2*n-i-2)) return;
        cout << "-1\n";
        return;
    }
    if (analyze_and_print(a, a[1]+a[2*n-2], 0)) return;
    else if(analyze_and_print(a, a[0] + a[2*n-3], 2*n-2)) return;
    else if(analyze_and_print(a, init, i)) return;
    else if (analyze_and_print(a, init, 2*n-i-2)) return;
    cout << "-1\n";
}