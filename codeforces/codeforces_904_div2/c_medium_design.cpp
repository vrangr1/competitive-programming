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
    vector<pair<int,int>> segments(n);
    rep(i,n){
        cin >> segments[i].first >> segments[i].second;
        segments[i].first--;
        segments[i].second--;
    }
    sort(all(segments),[](const pair<int,int> &a, const pair<int,int> &b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    // multiset<int> starts,ends;
    map<int,int> starts, ends;
    auto comp = [](const pair<int,int> &a, const pair<int,int> &b){
        return a.first > b.first;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
    int mx = 0;
    rep(i,n){
        while(!pq.empty() && pq.top().first < segments[i].first){
            starts[pq.top().second]--;
            ends[pq.top().first]--;
            if (starts[pq.top().second] == 0) starts.erase(pq.top().second);
            if (ends[pq.top().first] == 0) ends.erase(pq.top().first);
            // starts.erase(starts.find(pq.top().second));
            // ends.erase(ends.find(pq.top().first));
            pq.pop();
        }
        pq.push(make_pair(segments[i].second, segments[i].first));
        // starts.insert(segments[i].first);
        // ends.insert(segments[i].second);
        starts[segments[i].first]++;
        ends[segments[i].second]++;
        if (starts.empty() || starts.begin()->first > 0 || ends.rbegin()->first < m-1){
            mx = max((int)pq.size(),mx);
        }
        else{
            assert(!starts.empty());
            assert(!ends.empty());
            assert(starts.begin()->first == 0 && ends.rbegin()->first == m-1);
            mx = max((int)((int)pq.size() - min(starts.begin()->second, ends.rbegin()->second)), mx);
        }
    }
    cout << mx << endl;
}