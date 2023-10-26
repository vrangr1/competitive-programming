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

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    unordered_set<int> cset;
    rep(i,m){
        cin >> c[i]; c[i]--;
        cset.insert(c[i]);
    }
    priority_queue<vector<int>> pq;
    rep(i,n){
        if(cset.find(i) != cset.end()) continue;
        // pq.push(make_pair(a[i],i));
        pq.push({a[i],-b[i],i});
    }
    int ind = 0;
    int souls = 0, l = 0;
    while(!pq.empty()){
        int s = pq.top().at(0);
        if (ind < m){
            if (a[c[ind]] >= pq.top().at(0)){
                if (l >= a[c[ind]]) souls += b[c[ind]];
                l = a[c[ind]];
                ind++;
                continue;
            }
            else{
                if (l >= s) souls += b[pq.top().at(2)];
                l = s;
                pq.pop();
            }
            continue;
        }
        else{
            if (l >= s) souls += b[pq.top().at(2)];
            l = s;
            pq.pop();
        }
    }
    while(ind < m){
        if (l >= a[c[ind]]) souls += b[c[ind]];
        l = a[c[ind]];
        ind++;
        // if (a[c[ind]] >= pq.top().first){
        //     if (l >= a[c[ind]]) souls += b[c[ind]];
        //     l = a[c[ind]];
        //     // continue;
        // }
        // ind++;
    }
    cout << souls << endl;
}