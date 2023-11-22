/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#include <random>
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

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const char red = 'R', blue = 'B';

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int l = n+m-2;
    if (l > k) return void(cout << no);
    int diff = k-l;
    if ((diff%4)%2) return void(cout << no);
    vector<string> rows(n,string(m-1,red)), cols(m, string(n-1,red));
    int cur = 0;
    if ((diff%4) == 0){
        rep(i,n-1)
            cols[0][i] = (cur++%2 ? red : blue);
        rep(j,m-1)
            rows[n-1][j] = (cur++%2 ? red : blue);
        cols[m-1][n-2] = (cur++%2 ? red : blue);
        rows[n-2][m-2] = (cur++%2 ? red : blue);
        cols[m-2][n-2] = (cur++%2 ? red : blue);
    }
    else{
        rep(i,n-1)
            cols[0][i] = (cur++%2 ? red : blue);
        rep(j,m-2)
            rows[n-1][j] = (cur++%2 ? red : blue);
        cols[m-2][n-2] = (cur++%2 ? red : blue);
        rows[n-2][m-2] = (cur++%2 ? red : blue);
        cols[m-1][n-2] = (cur++%2 ? red : blue);
        rows[n-1][m-2] = (cur++%2 ? red : blue);
    }
    cout << yes;
    rep(i,n){
        rep(j,m-1)
            cout << rows[i][j] << " \n"[j==m-2];
    }
    rep(i,n-1){
        rep(j,m)
            cout << cols[j][i] << " \n"[j==m-1];
    }
}