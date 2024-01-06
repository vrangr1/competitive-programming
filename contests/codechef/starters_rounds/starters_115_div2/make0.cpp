/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan  3 20:23:10 IST 2024
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (*min_element(all(a)) >= n) return void(cout << n << endl);
    map<int,int> mp;
    vector<int> mns(n);
    mns[0] = a[0];
    mp[a[0]]++;
    rep(i,1,n-1,1){
        mns[i] = min(mns[i-1],a[i]);
        mp[a[i]]++;
    }
    int del = 0, sol = n, rem = 0, last = 0;
    rep(i,n-1,0,-1){
        if (i != n-1 && mns[i] == mns[i+1]){
            mp[a[i]]--;
            continue;
        }
        debug(a,i,mns[i],last,sol,mns[i],mp[mns[i]],rem,del);
        int cur = mns[i]-last;
        del += mp[mns[i]];
        rem += cur;
        debug(cur,rem+n-del,endl);
        if (rem >= n) return void(cout << sol << endl);
        sol = min(sol, rem+n-del);
        last = mns[i];
        mp[a[i]]--;
    }
    cout << sol << endl;
}

/*
5
3
1 1 1
3
1 2 1
4
1 2 2 2
5
1 1 2 2 2

1
9
5 3 3 5 2 4 5 2 1


*/