/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 23 18:06:12 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    auto get = [&](ll i, char t) -> ll {
        assert(i < n-1);
        return (s[i] == t?0ll:c[i]) + (s[i+1]==t?0ll:c[i+1]);
    };
    if (n == 2) return void(cout << min(get(0,'1'),get(0,'0')) << endl);
    vector<vector<ll>> left(n,vector<ll>(2,LLONG_MAX)), right(n,vector<ll>(2,LLONG_MAX));
    rep(i,n-1ll,0ll,-1ll){
        right[i][0] = (s[i]=='0'?0ll:c[i]);
        right[i][1] = (s[i]=='1'?0ll:c[i]);
        if (i == n-1ll)
            continue;
        right[i][0] += right[i+1][1];
        right[i][1] += right[i+1][0];
    }
    rep(i,n){
        left[i][0] = (s[i]=='0'?0ll:c[i]);
        left[i][1] = (s[i]=='1'?0ll:c[i]);
        if (!i) continue;
        left[i][0] += left[i-1][1];
        left[i][1] += left[i-1][0];
    }
    ll mn = LLONG_MAX;
    rep(i,n-1){
        ll cost = LLONG_MAX;
        if (!i){
            cost = min(cost, get(i,'0') + right[i+2][1]);
            cost = min(cost, get(i,'1') + right[i+2][0]);
        }
        else if (i == n-2){
            cost = min(cost, get(i,'0') + left[i-1][1]);
            cost = min(cost, get(i,'1') + left[i-1][0]);
        }
        else{
            cost = min(cost, get(i,'0') + right[i+2][1] + left[i-1][1]);
            cost = min(cost, get(i,'1') + right[i+2][0] + left[i-1][0]);
        }
        mn = min(mn,cost);
    }
    cout << mn << endl;
}