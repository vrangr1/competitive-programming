/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 22 20:05:28 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    auto get = [&n,&a](ll ind, ll val) -> ll {
        ll sol = 0ll;
        rep(i,ind,n-1ll,1){
            if (a[i] >= val) break;
            sol += val-a[i];
        }
        assert(sol != 0);
        return sol;
    };
    if (n%2){
        ll med = n/2, val = a[med];
        val++;
        ll sol = get(med,val);
        cout << sol << endl;
        return;
    }
    ll sol = LLONG_MAX, med = n/2ll - 1ll, val = a[med];
    sol = get(med, ++val);
    cout << sol << endl;
    // ll med = n/2ll-1ll, val = ((ll)a[med]+(ll)a[med+1])/2ll;
    // ll sol = LLONG_MAX;
    // if ((a[med]+a[med+1ll]+1ll)/2ll > val){
    //     if (a[med] < a[med+1ll]) return void(cout << "1\n");
    //     sol = min(sol,get(med+1ll,val+1ll));
    //     cout << sol << endl;
    //     return;
    // }
    // if (a[med]+1ll < a[med+1ll]) return void(cout << "2\n");
    // sol = min(sol,get(med,val+1ll));
    // sol = min(sol,get(med+1ll,val+2ll));
    // assert(sol != LLONG_MAX);
    // cout << sol << endl;
}