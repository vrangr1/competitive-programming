/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 15 20:00:49 IST 2024
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

void solve1(){
    ll n; cin >> n;
    vector<ll> tpwr(19);
    tpwr[0] = 1ll;
    rep(i,1,sz(tpwr)-1ll,1) tpwr[i] = tpwr[i-1]*10ll;
    auto get = [&tpwr](auto &&self, i128 n) -> i128 {
        if (n < 10ll) return (n*(n+1ll))/2ll;
        string s = to_string((ll)n);
        i128 v = s.front()-'0', m = tpwr[sz(s)-1]-1ll;
        reverse(all(s));
        s.pop_back();
        reverse(all(s));
        i128 rem = stoll(s);
        i128 o = self(self,m);
        return (((v-(i128)1)*v)/(i128)2)*(m+(i128)1) + v*o + (rem+(i128)1)*v + self(self,rem);
    };
    i128 sol = get(get,n);
    string s;
    while(sol > 0){
        s.push_back('0'+sol%((i128)10));
        sol/=(i128)10;
    }
    reverse(all(s));
    cout << s << endl;
}

void solve() {
    ll n; cin >> n;
    ll v = (n%9ll);
    cout << (n/9ll)*45ll + (v*(v+1ll))/2ll << endl;
}