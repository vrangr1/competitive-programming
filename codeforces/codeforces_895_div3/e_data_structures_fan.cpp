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
#define debug
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
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
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
    int n; cin >> n;
    vector<int> a(n);
    forn(i,n) cin >> a[i];
    string s;
    cin >> s;
    int xor1 = 0, xor0 = 0;
    vector<int> prefix_xor0(n,0), prefix_xor1(n,0);
    prefix_xor1[0] = (s[0] == '1'? a[0] : 0);
    prefix_xor0[0] = (s[0] == '1'? 0 : a[0]);
    forsn(i, 1, n-1){
        prefix_xor0[i] = prefix_xor0[i-1];
        prefix_xor1[i] = prefix_xor1[i-1];
        if (s[i] == '1')
            prefix_xor1[i] ^= a[i];
        else prefix_xor0[i] ^= a[i];
    }
    xor0 = prefix_xor0[n-1];
    xor1 = prefix_xor1[n-1];
    int q;
    cin >> q;
    forn(i,q){
        int tp; cin >> tp;
        int l,r,g;
        switch(tp){
            case 1:
                cin >> l >> r;
                
                break;
            case 2:
                cin >> g;

                break;
        }
    }
}