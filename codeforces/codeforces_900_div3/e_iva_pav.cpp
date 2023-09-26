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
// vector<vector<int>> bitcounts((int)2e5,vector<int>(31));

void preprocess(const vector<int> &a, vector<vector<int>> &bitcounts){
    int n = a.size(), num;
    rep(bit,31){
        num = (1<<bit);
        if (a[0]&num)
            bitcounts[0][bit] = 1;
        else bitcounts[0][bit] = 0;
        // bitcounts[0][bit] = ((a[0]&num) > 0);
        rep(i,1,n-1,1){
            // bitcounts[i][bit] = ((a[0]&num) > 0) + bitcounts[i-1][bit];
            if (a[i]&num)
                bitcounts[i][bit] = 1+bitcounts[i-1][bit];
            else bitcounts[i][bit] = bitcounts[i-1][bit];
        }
            
    }
}

int get_and(const int start, const int end, const vector<vector<int>> &bitcounts){
    int ans = 0, diff;
    rep(bit,31){
        diff = bitcounts[end][bit];
        if (start > 0) diff -= bitcounts[start-1][bit];
        if (diff == end-start+1) ans = (ans | (1<<bit));
    }
    return ans;
}

bool check(int andnum, int k){
    return andnum >= k;
}

int bsch(int low, int high, const int k, const vector<vector<int>> &bitcounts, const int start){
    if (low == high) return low;
    debug(low,high);
    assert(low<high);
    int mid = (low+high)/2;
    if (mid == low) mid++;
    // int andnum = get_and(low,mid, bitcounts);
    // debug(mid, andnum,k);
    if (check(get_and(start,mid, bitcounts), k)) return bsch(mid,high,k, bitcounts, start);
    return bsch(low,mid-1,k, bitcounts, start);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        debug(bitset<32>(a[i]).to_string());
        // fill(all(bitcounts[i]),0);
    }
    vector<vector<int>> bitcounts(n,vector<int>(31));
    preprocess(a,bitcounts);
    debug(bitcounts);
    int q; cin >> q;
    debug(q);
    while(q--){
        int l,k; cin >> l >> k; l--;
        debug(l);
        assert(l >= 0 && l < n);
        if (!check(a[l],k)){
            cout << "-1" << " \n"[q==0];
            continue;
        }
        cout << bsch(l, n-1, k,bitcounts, l)+1 << " \n"[q==0];
    }
}
// 1
// 5
// 15 14 17 42 34
// 3
// 1 7
// 2 15
// 4 5