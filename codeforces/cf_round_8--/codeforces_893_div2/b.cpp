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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m);
    rep(i,m) cin >> s[i];
    // ++m;
    // s.push_back(n);
    int total = 1, last = 1;
    rep(i,m){
        if (s[i] == last) continue;
        if (s[i] > last+d)
            total += (s[i]-1-last)/d;
        total++;
        last = s[i];
    }
    assert(last <= n);
    total += (n-last)/d;
    last = 1;
    debug(total);
    int mn = total;
    rep(i,m){
        if (s[i] == last) continue;
        if (s[i] > last+d){
            last = s[i]-((s[i]-1-last)%d)-1;
        }
        if (last+d == s[i]){
            last = s[i];
            continue;
        }
        if (i < m-1 && ((s[i+1]-1-last)/d) < (((s[i+1]-s[i]-1)/d)+1)){
            mn = min(mn, total+(((s[i+1]-1-last)/d) - (((s[i+1]-s[i]-1)/d)+1)));
        }
        else if (i == m-1 && (((n-last)/d) < (((n-s[i])/d) + 1))){
            mn = min(mn, total+((n-last)/d) - (((n-s[i])/d) + 1));
        }
        last = s[i];
    }
    debug(mn);
    int ct = 0;
    debug(n,d,s);
    if (mn < total){
        last = 1;
        rep(i,m){
            if (s[i] == last) continue;
            if (s[i] > last+d){
                last = s[i]-((s[i]-1-last)%d)-1;
            }
            if (last+d == s[i]){
                last = s[i];
                continue;
            }
            if (i < m-1 && ((s[i+1]-1-last)/d) < (((s[i+1]-s[i]-1)/d)+1)){
                if ((total+(((s[i+1]-1-last)/d) - (((s[i+1]-s[i]-1)/d)+1))) == mn)
                    ct++;
            }
            else if (i == m-1 && (((n-last)/d) < (((n-s[i])/d) + 1))){
                debug(s[i], last, ((n-last)/d), (((n-s[i])/d) + 1));
                if ((total+((n-last)/d) - (((n-s[i])/d) + 1)) == mn)
                    ct++;
            }
            last = s[i];
        }
    }
    else{
        ct = m;
    }
    // assert(ct > 0);
    cout << mn << " " << ct << endl;
}

/*
8

1
6 2 2
2 5

1
8 3 2
3 5 8

10 4 9
2 8 9 10

30 5 8
6 8 15 24 29

30 5 8
6 8 12 20 27

8 8 3
1 2 3 4 5 6 7 8

2 2 2
1 2

1000000000 3 20000000
57008429 66778899 837653445

1
7 2 2
4 6


*/