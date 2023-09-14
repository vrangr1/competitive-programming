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

bool dfs(int start, const vector<int> &b, vector<int> &counts, vector<bool> &visited, vector<bool> &cur, int count, const int k, bool loop = false){
    if (loop) assert(cur[b[start]] || !visited[b[start]]);
    visited[start] = true;
    cur[start] = true;
    counts[start] = ++count;
    if (cur[b[start]]){
        if (counts[start] - counts[b[start]] + 1 != k) return false;
        counts[start] = b.size() + 1;
        cur[start] = false;
        return true;
    }
    if (visited[b[start]] && counts[b[start]] >= k-count){
        counts[start] = counts[b[start]]+1;
        cur[start] = false;
        return true;
    }
    if (visited[b[start]]){
        return false;
    }
    bool ans = dfs(b[start], b, counts, visited, cur, count, k, loop);
    if (!ans) return false;
    cur[start] = false;
    counts[start] = counts[b[start]] + 1;
    return true;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> b(n);
    bool all_ones = true;
    vector<int> parent(n,-1);
    rep(i,n){
        cin >> b[i];
        // if (b[i] != 1) all_ones = false;
        b[i]--;
        parent[b[i]] = i;
    }
    rep(i,n){
        if (k == 1 && b[i] != i) return void(cout << no);
    }
    // if (all_ones) return void(cout << yes);
    vector<bool> visited(n, false), cur(n,false);
    vector<int> counts(n,-1);
    debug(parent);
    rep(i, n){
        if (parent[i] != -1) continue;
        if (!dfs(i, b, counts, visited, cur, 0, k))
            return void(cout << no);
    }
    rep(i,n){
        if (visited[i]) continue;
        if (!dfs(i, b, counts, visited, cur, 0, k, true))
            return void(cout << no);
    }
    cout << yes;
}
// 1
// 2 2
// 1 1