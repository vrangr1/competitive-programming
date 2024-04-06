/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Apr  6 20:09:25 IST 2024
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
#include <array>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef unsigned int uint;
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
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

void solve(){
    int n, k; cin >> n >> k; --k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int val = a[k];
    // a.erase(a.begin()+k);
    // n--;
    vector<int> mxs(n);
    rep(i,n){
        if (!i) mxs[i] = a[i];
        else mxs[i] = max(mxs[i-1],a[i]);
    }
    vector<int> nxt(n,n);
    rep(i,n-2,0,-1){
        nxt[i] = i+1;
        while(nxt[i] < n && a[nxt[i]] < a[i]){
            nxt[i] = nxt[nxt[i]];
        }
    }
    int sol = 0;
    debug(a,val,mxs,nxt);
    rep(i,n){
        if (i == k) continue;
        int mx = INT_MIN;
        if (i) mx = mxs[i-1];
        debug(i,mx);
        if (mx > val) continue;
        int ind = i+1;
        while(ind < n && a[ind] <= val){
            ind = nxt[ind];
        }
        if (a[i] > val) ind = min(k,ind);
        if (!i) ind--;
        debug(ind);
        sol = max(sol,ind-i);
    }
    cout << sol << endl;
}

/*

3

1
6 1
12 10 14 11 8 3

1
6 5
7 2 727 10 12 13

1
2 2
1000000000 1


*/