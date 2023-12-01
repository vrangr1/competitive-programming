/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Nov 30 22:21:09 IST 2023
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

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    // set<ll> st;
    // ll mxsum, start = 0ll;
    // ll end, cursum = 0ll;
    vector<ll> splits;
    // while(start < n){
    //     cursum = 0ll;
    //     // ++ind;
    //     end = start;
    //     assert(st.empty());
    //     while(end < n){
    //         cursum += a[end];
    //         st.insert(a[end]);
    //         mp[a[end]]--;
    //         if (mp[a[end]] == 0) st.erase(a[end]);
    //         if (st.empty()) break;
    //         end++;
    //     }
    //     splits.push_back(cursum);
    //     start = end+1ll;
    // }
    ll mxsum;
    // debug(splits);
    splits = a;
    n = sz(splits);
    vector<ll> suffix(n);
    suffix[n-1ll] = splits.back();
    rep(i,n-2ll,0ll,-1ll){
        // suffix[i] = suffix[i+1ll]+splits[i+1ll];
        suffix[i] = suffix[i+1ll] + splits[i];
    }
    // vector<bool> keep(n,true);
    // rep(i,1ll,n-1ll,1ll){
    //     if (splits[i] >= 0ll) continue;
    //     if (suffix[i] + splits[i] < 0ll) keep[i] = false;
    // }
    // ll ind = 1ll;
    mxsum = suffix.front();
    debug(suffix);
    rep(i,1,n-1ll,1ll){
        if (suffix[i] >= 0ll) mxsum += suffix[i];
        // if (!keep[i]){
        //     mxsum += (ind-1ll)*splits[i];
        //     continue;
        // }
        // mxsum += ind*splits[i];
        // ind++;
    }
    cout << mxsum << endl;
}

/*

6
1 -3 7 -6 2 5

4
2 9 -5 -3

8
-3 -4 2 -5 1 10 17 23

1
830

1
10
2 -1 4 2 -30 5 1 5 6 6

*/