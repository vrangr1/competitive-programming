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
	TEST;
	return 0;
}

void stack_push(ll val, stack<ll> &stk, bool &odd){
    if (stk.empty()){
        stk.push(val);
        return;
    }
    ll temp = val;
    while(!stk.empty() && stk.top() + temp > 0){

    }
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<bool> pos(n,false);
    rep(i,n){
        cin >> a[i];
        pos[i] = pos[i-1]||(a[i]>=0ll);
    }
    ll sum = 0ll, rem = 0ll, ind = n;
    bool odd = (n%2);
    rep(i,n-1,0,-1){
        if (odd && a[i] >= 0){
            sum += a[i] + rem;
            rem = 0ll;
            ind = i;
            odd = !odd;
            continue;
        }
        else if (odd){
            odd = !odd;
            continue;
        }
        if (a[i] > 0ll){
            // if (rem > 0ll){
            //     sum += a[i]+rem;
            //     rem = 0ll;
            //     ind = i;
            // }
            // else
                rem += a[i];
        }
        else{
            sum += rem;
            ind = i;
            rem = 0ll;
        }
        odd = !odd;
    }
    ll mx_add = 0ll;
    debug(rem,ind,sum);
    if (rem > 0ll){
        assert(ind > 0);
        ll mn = LLONG_MIN;
        rep(i,ind){
            assert((i+1)%2 == 0 || a[i] < 0ll);
            assert(i%2 == 0 || a[i] > 0ll);
            if (a[i] < 0){
                mn = max(mn, a[i]);
                continue;
            }
            if (a[i] >= 0){
                mx_add = max(rem+mn,mx_add);
                rem -= a[i];
                mx_add = max(mx_add, rem);
            }
        }
    }
    sum += mx_add;
    cout << sum << endl;
}


// 1
// 4
// -4 1 -3 5
// 4
// 1 -2 3 -4
// 3
// -1 3 -5
// 1
// -1