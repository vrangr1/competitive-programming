/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 22 20:28:11 IST 2024
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
    ll a, b, k; cin >> a >> b >> k;
    auto pwr = [](auto &&self, i128 a, i128 n) -> i128 {
        if (n == 0ll) return 1;
        if (n%2ll) return a*self(self,a*a,n/2ll);
        return self(self,a*a,n/2ll);
    };
    auto bsch = [&pwr](auto &&self, i128 low, i128 high, i128 a, i128 b, i128 k) -> i128 {
        if (low == high) {
            assert((pwr(pwr,k,low))*a <= b);
            return low;
        }
        i128 mid = (low+high+1ll)/2ll, val = a*(pwr(pwr,k,mid));
        if (val == b) return mid;
        if (val < b) return self(self,mid,high,a,b,k);
        return self(self,low,mid-1ll,a,b,k);
    };
    auto find_p = [&bsch](i128 a, i128 b, i128 k) -> i128 {
        i128 high = (i128)(logl(b/a)/logl(k)) + (i128)2;
        return bsch(bsch,0,high,a,b,k);
    };
    auto get = [&find_p,&pwr](i128 a, i128 b, i128 k) -> ll {
        i128 p = 0ll, t = b;
        while (t > a) {
            t/=k;
            if (t < a) break;
            p++;
        }
        i128 v = a*pwr(pwr,k,p);
        assert(v <= b);
        return (ll)(p + b-v);
    };
    ll sol = get(a,b,k);
    // debug(sol);
    ll ct = 0;
    ll opt = a;
    while(a < b) {
        ct++;
        a++;
        if (sol > (ct+get(a,b,k))) {
            opt = a;
            // if (opt == 21)
            // debug(ct);
        }
        sol = min(sol,(ct+get(a,b,k)));
        // debug(a,ct,sol);
    }
    debug(opt,get(opt,b,k));
    cout << sol << endl;
}