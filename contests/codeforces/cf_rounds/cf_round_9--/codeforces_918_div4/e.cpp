/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec 28 20:24:05 IST 2023
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1ll) return void(cout << no);
    ll k = n/2ll;
    debug(k);
    vector<ll> d(k);
    debug(a);
    rep(i,1,n-1ll,2){
        if ((i>>1ll) >= sz(d)) break;
        assert((i>>1ll)<sz(d));
        d[i>>1ll] = a[i]-a[i-1];
    }
    debug(d);
    vector<ll> psum(k);
    assert(sz(psum)==sz(d));
    partial_sum(all(d),psum.begin());
    debug(psum);
    set<ll> st;
    multiset<ll> rem(all(psum));
    rep(i,k){
        assert(i<sz(psum));
        if (psum[i] == 0ll) return void(cout << yes);
        ll ind = (i<<1ll)+2ll, ind2 = (i<<1ll)+1ll;
        // debug(i,ind);
        if (ind < n && psum[i] == a[ind]) return void(cout << yes);
        // auto iter = lower_bound(psum.begin(),psum.begin()+i,psum[i]);
        if (st.find(psum[i]) != st.end()) return void(cout << yes);
        // if (iter != psum.begin()+i && *iter == psum[i]) return void(cout << yes);
        if (ind < n){
            if (st.find(psum[i]-a[ind]) != st.end()) return void(cout << yes);
            // iter = lower_bound(psum.begin(),psum.begin()+i,psum[i]-a[ind]);
            // if (iter != psum.begin()+i && *iter == psum[i]-a[ind]) return void(cout << yes);
        }
        assert(ind2 < n);
        // iter = lower_bound(psum.begin()+i+1,psum.end(),psum[i]-a[ind2]);
        // if (iter != psum.end() && *iter == psum[i] - a[ind2]) return void(cout << yes);
        assert(rem.find(psum[i]) != rem.end());
        rem.erase(rem.find(psum[i]));
        if (rem.find(psum[i]-a[ind2]) != rem.end()) return void(cout << yes);
        st.insert(psum[i]);
    }
    rep(i,2,n-1ll,2){
        assert(((i-1ll)>>1ll) < sz(d));
        d[(i-1ll)>>1ll] = a[i-1]-a[i];
    }
    assert(sz(psum) <= sz(d));
    partial_sum(all(d),psum.begin());
    if (n%2ll == 0ll) k--;
    st.clear();
    rep(i,k){
        assert(i<sz(psum));
        if (psum[i] == 0) return void(cout << yes);
        // auto iter = lower_bound(psum.begin(),psum.begin()+i,psum[i]);
        // if (iter != psum.begin()+i && *iter == psum[i]) return void(cout << yes);
        if (st.find(psum[i]) != st.end()) return void(cout << yes);
        st.insert(psum[i]);
    }
    cout << no;
}


/*

1
8
1 2 11 4 1 5 1 2


*/