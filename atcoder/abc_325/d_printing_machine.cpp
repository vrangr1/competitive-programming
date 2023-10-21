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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> t(n), d(n);
    repll(i,n) cin >> t[i] >> d[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    stable_sort(all(order),[&t](const ll &i, const ll &j){
        return t[i] < t[j];
    });
    ll mx = n;
    auto comp = [](const ll &a, const ll &b){
        return a > b;
    };
    priority_queue<ll, vector<ll>, decltype(comp)> pq(comp);
    ll last_start = INT_MIN;
    repll(i,n){
        ll ind = order[i];
        ull ct = 0ll, diff = t[ind] - last_start;
        debug(i,mx,last_start,t[ind],t[ind]+d[ind],diff,pq);
        // debug(i, mx, last_start, t[ind], t[ind]+d[ind], diff);
        while(!pq.empty() && pq.top() <= t[ind]){
            ct++;
            pq.pop();
        }
        debug(ct,pq);
        // debug(ct);
        if (ct > diff){
            mx -= (ct-diff);
        }
        else{
            while(ct < diff && !pq.empty()){
                ct++;
                pq.pop();
            }
        }
        pq.push(t[ind]+d[ind]);
        debug(pq,mx,endl);
        last_start = t[ind];
    }
    // if (!pq.empty()) mx++;
    while (!pq.empty()){
        ll st = pq.top();
        ull ct = 0ll, diff = st - last_start+1ll;
        while(!pq.empty() && pq.top() <= st){
            ct++;
            pq.pop();
        }
        // debug(ct,pq);
        // debug(ct);
        if (ct > diff){
            mx -= (ct-diff);
        }
        else{
            while(ct < diff && !pq.empty()){
                ct++;
                pq.pop();
            }
        }
        // pq.push(t[ind]+d[ind]);
        // debug(pq,mx,endl);
        last_start = st+1;
    }
    cout << mx << endl;
}


/*

10
4 1
1 2
1 4
3 2
5 1
5 1
4 1
2 1
4 1
2 4


1 1 2 2 3 4 4 4 5 5
3 5 3 6 5 5 5 5 6 6

pq: {6,6}
last_start = 5
diff = 0
ct = 2
mx = 7
2 4 1 4 2 1 1 1 1 1


*/