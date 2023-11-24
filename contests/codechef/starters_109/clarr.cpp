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
    ll n, d; cin >> n >> d;
    vector<ll> b(n), c(n);
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    if (b[0] != c[0]) return void(cout << no);
    if (!is_sorted(all(b)) || !is_sorted(rall(c))) return void(cout << no);
    vector<ll> a(n,LLONG_MIN), prev(n,LLONG_MIN);
    a[0] = b[0];
    ll mxi = 0, last = LLONG_MIN;
    rep(i,1,n-1ll,1){
        if (b[i] < c[i]) return void(cout << no);
        if (b[i] != b[i-1]){
            if (c[i] != c[i-1]) return void(cout << no);
            prev[i] = last;
            a[i] = b[i];
            last = a[i];
            mxi = i;
            continue;
        }
        if (c[i] != c[i-1]){
            prev[i] = last;
            a[i] = c[i];
            last = a[i];
            mxi = i;
        }
        prev[i] = last;
    }
    fill(a.begin() + mxi + 1, a.end(), a[mxi]);
    last = a[mxi];
    rep(i,mxi-1,0ll,-1){
        if (a[i] != LLONG_MIN){
            last = a[i];
            continue;
        }
        if (llabs(prev[i]-last) <= d){
            if (last >= c[i] && last <= b[i])
                a[i] = last;
            else if (last >= c[i])
                a[i] = min(last,b[i]);
            else
                a[i] = max(last,c[i]);
            last = a[i];
            continue;
        }
        if (prev[i] > last){
            a[i] = last+d;
            last = a[i];
            if (last >= c[i] && last <= b[i])
                a[i] = last;
            else if (last >= c[i])
                a[i] = min(last,b[i]);
            else
                a[i] = max(last,c[i]);
            last = a[i];
            continue;
        }
        a[i] = last-d;
        last = a[i];
        if (last >= c[i] && last <= b[i])
            a[i] = last;
        else if (last >= c[i])
            a[i] = min(last,b[i]);
        else
            a[i] = max(last,c[i]);
        last = a[i];
    }
    rep(i,1,n-1ll,1){
        if (llabs(a[i]-a[i-1]) > d) return void(cout << no);
    }
    cout << yes;
    print_vec(a);
}