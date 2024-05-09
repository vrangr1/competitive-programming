/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  8 20:00:34 IST 2024
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
    i128 n; 
    {
        ll temp;
        cin >> temp;
        n = temp;
    }
    vector<i128> a(n);
    rep(i,n){
        ll t;
        cin >> t;
        a[i] = t;
    }
    auto pwr = [](auto &&self, i128 a, i128 n) -> i128 {
        if (n == 0ll) return 1ll;
        if (n%2ll) return a*self(self,a*a,n/2ll);
        return self(self,a*a,n/2ll);
    };
    auto get_val = [&pwr](ld a, i128 j) -> i128 {
        ld pr = ((ld)1)/((ld)j);
        i128 c = (ll)pow(a,pr);
        assert(pwr(pwr,c,j) <= a);
        // ll ct = 0ll;
        // while(pwr(pwr,c+1ll,j) <= a){
        //     c++;
        //     // ct++;
        //     // assert(ct < 10);
        // }
        return c;
    };
    vector<i128> c = a;
    sort(all(c));
    auto get_ct = [&](i128 v) -> ll {
        auto it = upper_bound(all(c),v);
        if (it == c.begin()) return 0ll;
        return it-c.begin();
    };
    ll sol = 0ll;
    rep(i,n){
        sol += get_ct(get_val(a[i],i+1ll));
    }
    cout << sol << endl;
}