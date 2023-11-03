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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
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

bool evaluate(int ind, const vector<int> &a, const vector<int> &axors, vector<int> &vals, unordered_set<int> p, const int n){
    // zero case:
    if (ind == 0){
        if (a[0] >= n) return false;
        vals[0]++;
        vals[a[0]]++;
        if (vals[0] == 1 && vals[a[0]] == 1){
            assert(p.find(0) != p.end());
            assert(p.find(a[0]) != p.end());
            p.erase(0);
            p.erase(a[0]);
            if (p.empty()) return true;
            p.insert(0);
            p.insert(a[0]);
        }
        vals[0]--;
        vals[a[0]]--;
        return false;
    }
    if (a[ind-1] >= n || a[ind] >= n) return false;
    vals[0]++;
    vals[a[ind-1]]++;
    vals[a[ind]]++;
    vals[a[ind-1]^a[ind]]--;
    
}

void solve(){
    int n; cin >> n;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    vector<int> axors(n-2);
    vector<int> vals(n);
    rep(i,n-2){
        axors[i] = a[i]^a[i+1];
        if (axors[i] >= n){
            if (i != 0 && i != n-2){
                rep(j,n){
                    if (j < i){
                        cout << (a[j]^a[j+1]) << space;
                        continue;
                    }
                    if (j == i){
                        assert(a[i] < n);
                        cout << a[i] << space;
                        continue;
                    }
                    if (j == i+1){
                        
                    }
                }
                return;
            }

            return;
        }
        vals[axors[i]]++;
    }
    unordered_set<int> p;
    rep(i,n){
        if (vals[i] == 0 || vals[i] > 1) p.insert(i);
    }
    assert(p.size() <= 3);
}