/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Nov 27 23:37:26 IST 2023
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
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
#include <bit>
#include <bitset>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

ll binary_search(int low, int high, const int val, const int limit){
    if (low == high) return high;
    int mid = (low+high)/2;
    int nval = val/mid + (val%mid > 0);
    if (nval <= limit) return binary_search(low, mid, val, limit);
    return binary_search(mid+1, high, val, limit);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ct = 0, p;
    while((int)a.size() > 1){
        n = a.size();
        if (a[n-2] <= a[n-1]){
            a.pop_back();
            continue;
        }
        if (a[n-2]-a[n-1] <= a[n-1]){
            a.pop_back();
            a.back()/=2;
            ct++;
            continue;
        }
        p = binary_search(1,a[n-2],a[n-2],a[n-1]);
        ct += p-1ll;
        a.pop_back();
        a.back()/=p;
    }
    cout << ct << endl;
}