/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 20:45:57 IST 2023
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
    ll t2, temp; cin >> t2 >> temp;
    i128 n = t2;
    i128 k = temp;
    vector<ll> a(n);
    i128 s = 0;
    rep(i,n){
        cin >> a[i];
        s += (i128)a[i];
    }
    map<i128,ll> mp;
    rep(i,n) mp[a[i]]++;
    // sort(all(a));
    // auto maxfreq = [&](){
    //     ll mxct = 1ll, val = a[0], curct = 0ll;
    //     rep(i,n){
    //         if (val == a[i]){
    //             curct++;
    //             mxct = max(curct,mxct);
    //         }
    //         else{
    //             curct = 1ll;
    //             val = a[i];
    //         }
    //     }
    // };
    // maxfreq();
    auto process = [&](i128 op) -> ll {
        i128 target = s+op*k;
        assert(target%n == 0);
        target/=n;
        if (mp.find(target) == mp.end()) return op+n;
        
    };
    vector<ll> ops;
    ll rem = (n-s%n)%n;
    rep(op,n){
        ll cur = ((op%n)*(k%n))%n;
        if (cur != rem) continue;
        
        // process
    }


}