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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int t;
    rep(i,k) cin >> t;
    vector<int> r(k+1);
    r[0] = 0;
    rep(i,k)
        cin >> r[i+1];
    int q; cin >> q;
    int x, ind;
    vector<int>::iterator iter;
    vector<pair<int,int>> ops(n, make_pair(-1,-1));
    debug(r);
    rep(_,q){
        cin >> x;
        iter = lower_bound(all(r), x);
        ind = iter-r.begin();
        ind--;
        assert(ind >= 0 && ind < k);
        int a = min(x,r[ind+1]+r[ind]+1-x), b = max(x,r[ind+1]+r[ind]+1-x);

        a--;b--;
        debug(a,b,endl);
        assert(a>=0 && a <= b && b < n);
        if (ops[a].first == -1){
            ops[a] = make_pair(a, b);
            continue;
        }
        assert(ops[a].first == a && ops[a].second == b);
        ops[a] = make_pair(-1,-1);
    }
    debug(ops);
    pair<int,int> end = make_pair(-1,-1);
    rep(i,n){
        if (end.first == -1) end = ops[i];
        else if (ops[i].first != -1) end = make_pair(-1,-1);
        
        if (end.first == -1) continue;
        int mid = (end.first+end.second)/2;
        if (i >= mid){
            end = make_pair(-1,-1);
            continue;
        }
        swap(s[i],s[end.second-(i-end.first)]);
    }
    cout << s << endl;
}
// 1
// 8 4
// hifnuapw
// 1 3 6 7
// 2 5 6 8
// 9
// 6 3 7 2 4 8 4 8 4



// 1
// 4 2
// abcd
// 1 3
// 2 4
// 2
// 1 3

// 5 3
// abcde
// 1 2 3
// 1 2 5
// 3
// 1 2 3

// 3 1
// gaf
// 1
// 3
// 2
// 2 2

// 10 1
// aghcdegdij
// 1
// 10
// 5
// 1 2 3 4 2

// 1 1
// a
// 1
// 1
// 1
// 1
