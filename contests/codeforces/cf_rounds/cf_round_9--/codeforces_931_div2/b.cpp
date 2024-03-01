/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar  1 20:10:50 IST 2024
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

map<ll,ll> mp;
const ll limit = 200;
void solve(){
    ll n; cin >> n;
    auto get = [](auto &&self, ll n) -> ll {
        assert(n>=0);
        if (mp.find(n) != mp.end()) return mp[n];
        if (n == 0) return mp[0] = 0;
        if (n <= limit){
            mp[n] = 1+self(self,n-1);
            if (n>=15)
            mp[n] = min(mp[n],1+self(self,n-15));
            if (n>=10)
            mp[n] = min(mp[n],1+self(self,n-10));
            if (n>=6)
            mp[n] = min(mp[n],1+self(self,n-6));
            if (n>=3)
            mp[n] = min(mp[n],1+self(self,n-3));
            return mp[n];
        }
        if ((n-limit)%15 == 0) return mp[n] = (n-limit)/15ll + self(self,limit);
        return mp[n] = (n-limit+14ll)/15ll + self(self,limit-(15ll-((n-limit)%15ll)));
    };
    cout << get(get,n) << endl;
}