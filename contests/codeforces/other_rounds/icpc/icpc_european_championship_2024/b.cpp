/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Mar 24 16:24:43 IST 2024
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
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(all(a));
    multiset<ll> bms, other;
    debug(a);
    auto pos = [&](ll k) -> bool {
        debug(endl,k);
        bms.clear();
        other.clear();
        bms = multiset<ll>(all(b));
        rep(i,n) other.insert(-b[i]);
        for (ll v : a){
            auto it = bms.lower_bound(v+k);
            if (it == bms.end()){
                it = other.lower_bound(k-v);
                if (it == other.end()) return false;
                ll val = *it;
                other.erase(it);
                val = -val;
                assert(bms.find(val) != bms.end());
                bms.erase(bms.find(val));
                continue;
            }
            ll val = -*it;
            bms.erase(it);
            assert(other.find(val) != other.end());
            other.erase(other.find(val));
        }
        return true;
    };
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        assert(low <= high);
        if (low == high) return low;
        ll mid = (low+high+1ll)/2ll;
        assert(mid > low);
        if (pos(mid)) return self(self,mid,high);
        else return self(self,low,mid-1ll);
    };
    bms.clear();
    bms = multiset<ll>(all(b));
    debug(bms);
    ll mx = max(llabs(*bms.rbegin()-a.front()), llabs(a.back()-*bms.begin()));
    debug(mx);
    cout << bsch(bsch,0,mx) << endl;
}

/*

a: [ 12 14 25 62 74 86 95 ]
bms: { 20 51 62 71 72 84 92 }

a: [ 12 14 25 62 74   ]
bms: { 20 51  71  84 92 }

*/