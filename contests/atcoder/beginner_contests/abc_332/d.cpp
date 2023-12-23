/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec 10 17:42:38 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

int get_fac(int n){
    switch(n){
        case 1: return 1;
        case 2: return 2;
        case 3: return 6;
        case 4: return 24;
        case 5: return 120;
    }
    return 0;
}

void solve(){
    int h,w; cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w)), b(h,vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    // int th = get_fac(h), tw = get_fac(w);
    vector<int> rows(h), cols(w);
    iota(all(rows),0);
    iota(all(cols),0);
    auto match = [&]() -> bool {
        rep(i,h)
            rep(j,w)
                if (a[rows[i]][cols[j]] != b[i][j]) return false;
        return true;
    };
    auto inv = [] (const vector<int> &v) -> int {
        int n = sz(v), ct = 0;
        rep(i,n){
            rep(j,i+1,n-1,1)
                if (v[i] > v[j]) ct++;
        }
        return ct;
    };
    int mn = INT_MAX;
    do{
        sort(all(cols));
        do{
            if (!match()) continue;
            mn = min(mn,inv(rows)+inv(cols));
        }while(next_permutation(all(cols)));
    }while(next_permutation(all(rows)));
    if (mn != INT_MAX) cout << mn << endl;
    else cout << "-1\n";
}

/*
h! * w! * hw
120 * 120 * 25
360000

1 2 3

*/