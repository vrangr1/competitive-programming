#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -Wall -DLOCAL $me.cpp -o $me
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

void process(ll num, unordered_map<int, pair<int,ll>> &umap, bool skip, ll bit){
    if (umap.find(num) == umap.end()){
        if (skip) return;
        umap[num] = make_pair(0,0);
    }
    umap[num].first++;
    umap[num].second += bit;
}

void loop(int index, const vector<ll> &a, unordered_map<int, pair<int,ll>> &umap, bool skip = true){
    ll num;
    for(ll i = 0ll; i < 32ll; ++i){
        num = a[index]+(1ll<<i);
        process(num, umap, skip, (1ll<<i));
        num = a[index]-(1ll<<i);
        if (num < 0) continue;
        process(num, umap, skip, ((ll)(-1))*(1ll<<i));
    }
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    unordered_map<int, pair<int,ll>> umap;
    int num, coeff;
    loop(0, a, umap, false);
    if (n > 2){
        rep(i,1,n-2,1){
            loop(i, a, umap);
        }
    }
    rep(j,32){
        num = a[n-1]+(1ll<<j);
        process(num, umap, true, (1ll<<j));
        if (umap[num].first == n && umap[num].second == 0ll)
            return void(cout << yes);
        num = a[n-1]-(1ll<<j);
        if (num < 0) continue;
        process(num, umap, true, ((ll)(-1))*(1ll<<j));
        if (umap[num].first == n && umap[num].second == 0ll)
            return void(cout << yes);
    }
    cout << no;
}