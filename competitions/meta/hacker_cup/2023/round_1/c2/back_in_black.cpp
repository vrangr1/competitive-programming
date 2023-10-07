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
void solve(int T);

int main(){
	fastIO;
	int T;cin>>T;for(int t = 1; t <= T; ++t)solve(t);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

// vector<int> seen(4e6+1);

int get_count(int ind, vector<int> &seen){
    int ct = 0;
    rep(i,1,sqrt(ind),1){
        if (ind%i == 0) ct += seen[i];
    }
    if (ind > sqrt(ind))
    ct += seen[ind];
    return ct%2;
}

int compute_count(const string &state, vector<int> &seen){
    int ct, n = state.size();
    int sol = 0;
    rep(i,1,n,1){
        ct = get_count(i,seen)%2 + (state[i-1] == '1');
        ct %= 2;
        if (ct == 1){
            seen[i]++;
            sol++;
        }
    }
    return sol;
}

void solve(int T){
    cout << "Case #" << T << ": ";
    ll n; cin >> n;
    string state; cin >> state;
    ll q; cin >> q;

    ll temp = q;
    ll b;
    vector<int> seen(n+1,0);
    // fill(seen.begin(), seen.begin() + n + 1, 0);
    while(q--){
        cin >> b;
        seen[b]++;
        seen[b] %= 2;
    }
    int ct = 0;
    // debug(seen,state);
    rep(i, 1, n, 1){
        // debug(i,get_count(i,seen));
        ct = get_count(i,seen)%2 + (state[i-1] == '1');
        ct %= 2;
        state[i-1] = '0' + ct;
    }
    // debug(state);
    fill(seen.begin(), seen.begin() + n + 1, 0);
    ll sol = compute_count(state, seen);
    sol = (sol+1)*(temp);
    cout << sol << endl;
}

/*
5

4
1010
1
1   0101

4
0001
4
2   0100
3   0110  0011
2   0011
4   0010  0010

7
0101101
8
1
3
2
6
7
4
2
5

7
0101100
1
7

7
1111111
1
1






5

1
4
1010
1
1

1
4
0001
4
2
3
2
4

7
0101101
8
1
3
2
6
7
4
2
5

7
0101100
1
7

7
1111111
1
1

*/