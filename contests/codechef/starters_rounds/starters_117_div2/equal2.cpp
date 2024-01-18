/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan 17 20:08:32 IST 2024
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
    ll a, b; cin >> a >> b;
    ll d = llabs(a-b);
    if (d <= 1ll) return void(cout << d << endl);
    auto comp = [](ll n){
        if (n%2ll) return ((n+1ll)/2ll)*n;
        else return (n/2ll)*(n+1ll);
    };
    auto bsch = [&comp](auto &&self, ll l, ll h, const ll d){
        assert(l <= h);
        if (l == h){
            assert(comp(l) <= d);
            return l;
        }
        ll mid = (l+h+1ll)/2ll, c = comp(mid);
        if (c == d) return mid;
        if (c < d) return self(self,mid,h,d);
        return self(self,l,mid-1ll,d);
    };
    ll n = bsch(bsch,1ll,INT_MAX,d), s = comp(n);
    if (s == d) return void(cout << n << endl);
    assert(s < d);
    d-=s;
    d = ++n-d;
    if (d%2ll == 0ll) return void(cout << n << endl);
    d = ++n-d;
    if (d%2ll == 0ll) return void(cout << n << endl);
    d = ++n-d;
    assert(d%2ll == 0ll);
    return void(cout << n << endl);
}