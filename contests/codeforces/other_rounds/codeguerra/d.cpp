/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 20:16:41 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string pat; cin >> pat;
    int q; cin >> q;
    vector<int> ft(m),lt(m);
    int ind = 0;
    bool pos = true;
    rep(i,n){
        if (ind < m && s[i] == pat[ind]){
            ft[ind] = i;
            ind++;
        }
    }
    if (ind != m){
        pos = false;
    }
    ind = m-1;
    if (pos)
    rep(i,n-1,0,-1){
        if (ind >= 0 && s[i] == pat[ind]){
            lt[ind] = i;
            ind--;
        }
    }
    auto possible = [&] (const int l, const int r) -> bool {
        if (!pos) return false;
        int indlt = (int)(upper_bound(all(lt),r) - lt.begin());
        if (indlt == 0) return true;
        return (ft[indlt-1] < l);
    };
    while(q--){
        int l,r; cin >> l >> r;--l;--r;
        if (possible(l,r)) cout << yes;
        else cout << no;
    }
}