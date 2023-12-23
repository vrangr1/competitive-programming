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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mx = INT_MIN, mn = INT_MAX;
    rep(i,n){
        cin >> a[i];
        mx = max(a[i],mx);
        mn = min(a[i],mn);
    }
    if (mx == mn) return void(cout << "0\n");
    int moves = (32 - __builtin_clz(mx-mn));
    rep(i,n){
        a[i] /= (1<<(moves-1));
    }
    mx = *max_element(all(a)), mn = *min_element(all(a));
    bool zero = true, one = true;
    int zval = -1, oval = -1;
    while(mx != mn){
        zero = true; one = true;
        zval = -1; oval = -1;
        zval = a[0]/2;
        oval = (a[0]+1)/2;
        rep(i,1,n-1,1){
            if (a[i]/2 != zval){
                zero = false;
            }
            if ((a[i]+1)/2 != oval)
                one = false;
            if (!one && !zero) break;
        }
        if (zero){
            cout << moves << endl;
            if (moves <= n)
            rep(i,moves)
                cout << "0" << " \n"[i==moves-1];
            return;
        }
        if (one){
            cout << moves << endl;
            if (moves <= n)
            rep(i,moves-1)
                cout << "0 ";
            if (moves <= n)
            cout << "1\n";
            return;
        }
        moves++;
        rep(i,n) a[i]>>=1;
        mx>>=1;
        mn>>=1;
    }
    assert(false);
}

void solve1(){
    int n; cin >> n;
    vector<int> a(n);
    int mx = INT_MIN, mn = INT_MAX;
    rep(i,n){
        cin >> a[i];
        mx = max(a[i],mx);
        mn = min(a[i],mn);
    }
    int diff = mx-mn;
    int moves = (32 - __builtin_clz(diff));
    if (moves > n) return void(cout << moves << endl);
    rep(i,n){
        a[i] /= (1<<(moves-1));
    }
    sort(rall(a));
    bool zero = true, one = true;
    int zval = -1, oval = -1;
    zval = a[0]/2;
    oval = (a[0]+1)/2;
    rep(i,1,n-1,1){
        if (a[i]/2 != zval){
            zero = false;
        }
        if ((a[i]+1)/2 != oval)
            one = false;
        if (!one && !zero) break;
    }
    if (zero){
        cout << moves << endl;
        rep(i,moves)
            cout << "0" << " \n"[i==moves-1];
        return;
    }
    if (one){
        cout << moves << endl;
        rep(i,moves-1)
            cout << "0 ";
        cout << "1\n";
        return;
    }
    zval = a[0]/4;
    rep(i,1,n-1,1){
        assert((a[i])/4 == zval);
    }
    moves++;
    // cout << moves << end;

}