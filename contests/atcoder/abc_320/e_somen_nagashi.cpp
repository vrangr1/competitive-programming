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
	TEST1;
	return 0;
}

void solve(){
    ll n, m; cin >> n >> m;
    set<ll> people;
    vector<vector<ll>> events(m, vector<ll>(3));
    vector<ll> ans(n,0ll);
    auto comp = [](const pair<int,int> &a, const pair<int,int> &b){
        return a.first > b.first;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
    
    rep(i,n) people.insert(i);
    for(ll i = 0; i < m; ++i)
        cin >> events[i][0] >> events[i][1] >> events[i][2];
    sort(events.begin(), events.end());
    rep(i,m){
        while(!pq.empty() && pq.top().first <= events[i][0]){
            people.insert(pq.top().second);
            pq.pop();
        }
        if (people.size() == 0) continue;
        assert(*people.begin() >= 0 && *people.begin() < n);
        ans[*people.begin()] += events[i][1];
        pq.push(make_pair(events[i][0] + events[i][2], *people.begin()));
        people.erase(people.begin());
    }
    rep(i,n) cout << ans[i] << endl;
}