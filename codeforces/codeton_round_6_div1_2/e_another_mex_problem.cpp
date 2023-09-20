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
    #define cerr if(false)cerr
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
vector<vector<int>> segments(2e4, vector<int>(3));
vector<vector<int>> dp(5e3, vector<int>(5e3+1));
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}
bitset<(int)5e3 + 1> found;
bitset<8192> elements;

void carry_over(int i, vector<vector<int>> &dp, int n){
    if (i == 0) return;
    rep(j, n+1)
        dp[i][j] |= dp[i-1][j];
}

void propagate(const vector<int> &snapshot, vector<vector<int>> &dp, const vector<int> &segment, int n){
    for (int i = 1; i <= n; ++i){
        if (!snapshot[i]) continue;
        dp[segment[1]][segment[2]^i] = 1;
    }
    dp[segment[1]][segment[2]] = 1;
}

void find_ans(vector<vector<int>> &segments, const int segsize, int n, vector<vector<int>> &dp){
    sort(segments.begin(), segments.begin() + segsize, [](const vector<int> &a, const vector<int> &b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });
    int index = 0;
    for (int i = 0; i < n; ++i){
        carry_over(i,dp,n);
        while(index < segsize && segments[index][0] < i)
            index++;
        if (index == segsize) continue;
        if (i < segments[index][0]) continue;
        while(index < segsize && segments[index][0] == i)
            propagate(dp[max(i-1,0)], dp, segments[index++], n);
    }
    debug(dp[n-1]);
    rep(i,n,0,-1){
        if (!dp[n-1][i]) continue;
        cout << i << endl;
        break;
    }
}

void find_mex(int &index, int n){
    for (;index <= n; ++index)
        if (!elements[index]) return;
    assert(false);
    return;
}

void compute_segments(int n, const vector<int> &a, vector<vector<int>> &segments, int &segsize){
    int index = 0;
    segsize = 0;
    for (int i = 0; i < n; ++i){
        elements.reset();
        found.reset();
        index = 0;
        elements[a[i]] = true;
        for (int j = i+1; j < n; ++j){
            elements[a[j]] = true;
            find_mex(index, n);
            if (!found[index] && a[i] > a[j] && index > a[i] && index > a[j]){
                segments[segsize][0] = i;
                segments[segsize][1] = j;
                segments[segsize++][2] = index;
            }
            found[index] = true;
        }
        if (i == 0){
            if (a[i] == 0){
                segments[segsize][0] = i;
                segments[segsize][1] = i;
                segments[segsize++][2] = 1;
            }
            continue;
        }
        elements.reset();
        found.reset();
        index = 0;
        elements[a[i]] = true;
        for (int j = i-1; j >= 0; --j){
            elements[a[j]] = true;
            find_mex(index, n);
            if (!found[index] && a[i] > a[j] && index > a[i] && index > a[j]){
                segments[segsize][0] = j;
                segments[segsize][1] = i;
                segments[segsize++][2] = index;
            }
            found[index] = true;
        }
        if (a[i] == 0){
            segments[segsize][0] = i;
            segments[segsize][1] = i;
            segments[segsize++][2] = 1;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (count(a.begin(), a.end(), 0) == 0) return void(cout << 0 << endl);
    int segsize = 0;
    compute_segments(n, a, segments, segsize);
    rep(i,n) fill(dp[i].begin(), dp[i].begin() + n+1, 0);
    find_ans(segments, segsize, n, dp);
}