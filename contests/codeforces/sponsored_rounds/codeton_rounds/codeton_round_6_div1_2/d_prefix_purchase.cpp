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
    int n; cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    int k; cin >> k;
    vector<int> a(n,0);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](const int &i, const int &j){
        return c[i] < c[j];
    });
    int ind, maxind = -1;
    int mx = 0, cost = -1;
    rep(i,n){
        ind = order[i];
        if (k < c[order[i]]) break;
        if (ind < maxind) continue;
        maxind = max(maxind, ind);
        a[ind] = k/c[ind];
        if (a[ind] >= mx){
            mx = a[ind];
            cost = c[ind]*a[ind];
            continue;
        }
        int p = 1, prev_cost = cost/mx, rem = k - cost;
        a[ind] = rem/c[ind];
        rem = rem%c[ind];
        int count = 0;
        while(rem + prev_cost >= c[ind]){
            count += (rem+prev_cost)/c[ind];
            a[ind] += (rem+prev_cost)/c[ind];
            rem = (rem+prev_cost)%c[ind];
        }
        k -= prev_cost*(mx-count);
        mx = a[ind];
        cost = c[ind]*a[ind];
        assert(cost <= k);
    }
    mx = a[n-1];
    rep(i,n-2,0,-1){
        if (a[i] < mx)
            a[i] = mx;
        else mx = a[i];
    }
    rep(i,n)
        cout << a[i] << " \n"[i==n-1];
}

void solve1(){
    int n; cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    int k; cin >> k;
    vector<int> a(n,0);
    int mx = 0, cost = -1;
    rep(i,n){
        if (k < c[i]) continue;
        a[i] = k/c[i];
        if (a[i] >= mx){
            mx = a[i];
            cost = c[i]*a[i];
            continue;
        }
        int p = 1, prev_cost = cost/mx, rem = k - cost;
        a[i] = rem/c[i];
        rem = rem%c[i];
        int count = 0;
        while(rem + prev_cost >= c[i]){
            count += (rem+prev_cost)/c[i];
            a[i] += (rem+prev_cost)/c[i];
            rem = (rem+prev_cost)%c[i];
        }
        k -= prev_cost*(mx-count);
        mx = a[i];
        cost = c[i]*a[i];
        assert(cost <= k);
    }
    mx = a[n-1];
    rep(i,n-2,0,-1){
        if (a[i] < mx)
            a[i] = mx;
        else mx = a[i];
    }
    rep(i,n)
        cout << a[i] << " \n"[i==n-1];
}