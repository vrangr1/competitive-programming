/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec  5 20:41:08 IST 2023
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
    vector<ll> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];
    auto intersect = [](ll gl, ll gr, ll cl, ll cr) -> bool {
        return (cl >= gl && cl <= gr) || (cr >= gl && cr <= gr) || (cl <= gl && cr >= gr);
    };
    auto pos = [&](ll k) -> bool {
        ll cl = 0, cr = 0;
        rep(i,n){
            cl -= k;
            cr += k;
            if (!intersect(l[i],r[i],cl,cr)) return false;
            cl = max(cl,l[i]);
            cr = min(cr,r[i]);
        }
        return true;
    };
    auto search = [&](auto self, ll low, ll high) -> ll {
        assert(low <= high);
        if (low == high) return high;
        ll mid = (low+high)/2ll;
        if (pos(mid)) return self(self,low,mid);
        return self(self,mid+1ll,high);
    };
    cout << search(search,0ll,(ll)(INT_MAX)+100ll) << endl;
}