/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Apr 30 20:21:53 IST 2024
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto cost = [&](ll mn) -> ll {
        auto it = upper_bound(all(a),mn);
        if (it == a.begin()) return 0ll;
        if (it == a.end()) return (mn*n)-psum.back();
        ll ind = (ll)(it-a.begin());
        assert(a[ind] > mn);
        return (mn*ind) - psum[ind-1ll];
    };
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        assert(low <= high);
        if (low == high) return low;
        ll mid = (low+high+1ll)/2ll;
        ll mcost = cost(mid);
        if (mcost <= k) return self(self,mid,high);
        return self(self,low,mid-1ll);
    };
    ll mn = bsch(bsch,a.front(),a.back()+k);
    ll mcost = cost(mn);
    assert(mcost <= k);
    k-=mcost;
    ll sol = (mn-1ll)*n + 1ll;
    ll ind = (ll)(upper_bound(all(a),mn) - a.begin());
    sol += k + (n-ind);
    cout << sol << endl;
}