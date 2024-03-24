/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 23 17:32:23 IST 2024
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
#define yes "Yes\n"
#define no "No\n"
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

const string pat = "wbwbwwbwbwbw";
const string pat2 = pat+pat;
const int n = sz(pat);
const int mw = (int)count(all(pat),'w'), mb = (int)count(all(pat),'b');

void solve1(){
    int w, b; cin >> w >> b;
    int c = min(w/mw,b/mb);
    w -= (mw*c);
    b -= (mb*c);
    w = w%mw;
    b = b%mb;
    if (w < 0 || b < 0) return void(cout << no);
    if (w == 0 && b == 0) return void(cout << yes);
    int cw = 0, cb = 0;
    rep(i,(int)n){
        cw = 0;
        cb = 0;
        rep(j,i,i+n-2,1){
            cw += (pat2[j]=='w');
            cb += (pat2[j]=='b');
            if (cw == w && cb == b) return void(cout << yes);
        }
    }
    cout << no;
}

// const string pat = "wbwbwwbwbwbw";
string rep;
int n2;

void init(){
    int r = 30;
    rep = pat;
    while(r--){
        rep+=pat;
    }
    n2 = sz(rep);
}

void solve(){
    init();
    int w, b; cin >> w >> b;
    int cw = 0, cb = 0;
    rep(i,n2){
        cw = cb = 0;
        rep(j,i,n2-1,1){
            cw += (rep[j] == 'w');
            cb += (rep[j] == 'b');
            if (cw == w && cb == b) return void(cout << yes);
        }
    }
    cout << no;
}