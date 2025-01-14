/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Apr  6 21:33:52 IST 2024
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
    ll n, k; cin >> n >> k;
    if (n < k) return void(cout << no);
    if ((n%k) < (n/k)) return void(cout << yes << "1\n" << n/k << endl);
    auto rec = [](auto &&self, ll n, ll k) -> vector<ll> {
        if (n < k) return {};
        if ((n%k) < (n/k)) return {n/k};
        ll low = n/k, high = (n+k-1ll)/k + 1ll;
        rep(r,high,low,-1ll){
            if (n/r == k) return {r};
            if (n/r > k) break;
            assert(n/r < k);
            auto csol = self(self,n%r,k-(n/r));
            if (csol.empty()) continue;
            csol.push_back(r);
            return csol;
        }
        return {};
    };
    auto sol = rec(rec,n,k);
    if (sol.empty() || sz(sol) > 60) return void(cout << no);
    cout << yes;
    cout << sz(sol) << endl;
    reverse(all(sol));
    print_vec(sol);
}