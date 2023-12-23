/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec 19 20:16:18 IST 2023
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
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    vector<int> oa(n), ob(n), oc(n);
    iota(all(oa),0);
    iota(all(ob),0);
    iota(all(oc),0);
    sort(all(oa), [&](const int &i, const int &j){
        return a[i] < a[j];
    });
    sort(all(ob), [&](const int &i, const int &j){
        return b[i] < b[j];
    });
    sort(all(oc), [&](const int &i, const int &j){
        return c[i] < c[j];
    });
    int mx = 0;
    rep(i,n-5,n-1,1){
        if (i < 0) continue;
        rep(j,n-5,n-1,1){
            if (j < 0) continue;
            if (oa[i] == ob[j]) continue;
            rep(k,n-5,n-1,1){
                if (k < 0) continue;
                if (oa[i] == oc[k] || ob[j] == oc[k]) continue;
                mx = max(a[oa[i]] + b[ob[j]] + c[oc[k]], mx);
            }
        }
    }
    cout << mx << endl;
}

/*

1
3
1 10 1
10 1 1
1 1 10


*/