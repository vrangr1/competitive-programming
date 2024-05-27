/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri May 17 21:11:06 IST 2024
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
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n){
        cin >> p[i];
        --p[i];
    }
    if (is_sorted(all(p))) return void(cout << (((2ll*n)*(2ll*n + 1ll))/2ll) << endl);
    ll minr = 1, maxl = 2ll*n;
    rep(i,n-1ll,0ll,-1ll) {
        if (p[i] != i) {
            minr = i+2ll;
            break;
        }
    }
    {
        auto c = p;
        vector<ll> o(n,-1ll);
        rep(i,n) o[c[i]] = i;
        rep(i,n) {
            if (c[i] == i) continue;
            maxl = min(maxl,i+1ll+c[i]+1ll);
            swap(c[i],c[o[i]]);
        }
        debug(c);
        assert(is_sorted(all(c)));
    }
    assert(maxl <= minr);
    debug(maxl,minr);
    ll sol = 0ll, n2 = 2ll*n;
    rep(l,1,maxl,1) {
        sol += n2-minr+1ll;
    }
    cout << sol << endl;
}