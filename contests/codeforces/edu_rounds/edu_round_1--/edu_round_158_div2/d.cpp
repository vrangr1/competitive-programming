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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = max_element(all(a)) - a.begin(), r = l;
    ll x = a[l], steps = 0;
    while(l > 0 || r < n-1){
        if (l > 0 && r < n-1){
            if (a[l-1] < a[r+1]){
                x = max(x, a[l-1] + ++steps);
                --l;
                continue;
            }
            x = max(x, a[r+1] + ++steps);
            ++r;
            continue;
        }
        if (l > 0){
            x = max(x, a[l-1] + ++steps);
            --l;
            continue;
        }
        x = max(x, a[r+1] + ++steps);
        ++r;
        continue;
    }
    cout << x << endl;
}

void solve1(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> vis(n,false);
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j){
        return a[i] < a[j];
    });
    ll l = order.back(), r = l;
    ll x = a[l], ind, steps = 0;
    vis[l] = true;
    debug(l,r,x,endl);
    rep(i,n){
        ind = order[n-i-1];
        if (vis[ind]) continue;
        debug(a,ind,a[ind]);
        assert(ind < l || ind > r);
        if (ind < l){
            rep(j,l-1,ind,-1){
                x = max(x, a[j]+ ++steps);
                vis[j] = true;
            }
            l = ind;
        }
        else{
            rep(j,r+1,ind,1){
                x = max(x, a[j] + ++steps);
                vis[j] = true;
            }
            r = ind;
        }
        debug(l,r,x,endl);
    }
    cout << x << endl;
}

/*


4 3 2 10 1 5 6 9 8 7



*/