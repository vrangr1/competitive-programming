/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec 10 16:25:22 IST 2023
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

void inds(int ind, int &x, int &y){
    x = ind/3;
    y = ind%3;
}

inline bool is_adj(int i, int j){
    int x1, y1, x2, y2;
    inds(i,x1,y1);
    inds(j,x2,y2);
    return (abs(x1-x2) <= 1 && abs(y1-y2) <= 1);
}

void solve(){
    string s, temp;
    cin >> s >> temp;
    s += temp;
    cin >> temp;
    s += temp;
    string mn = s.substr(0,3);
    rep(i,9){
        rep(j,9){
            if (i == j) continue;
            rep(k,9){
                if (i == k || k == j) continue;
                if (!is_adj(i,j) || !is_adj(j,k)) continue;
                temp = string(1,s[i])+string(1,s[j])+string(1,s[k]);
                mn = min(mn,temp);
            }
        }
    }
    cout << mn << endl;
}