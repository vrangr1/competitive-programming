/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec  4 19:28:09 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll m; cin >> m;
    ll len = sqrt(n) + 1ll;
    vector<ll> s(len, 0ll), c(len,0ll);
    ll ind = -1;
    rep(i,n){
        if (i%len == 0)
            ++ind;
        assert(ind < sz(s));
        s[ind] += v[i];
    }
    vector<ll> vs(all(v));
    sort(all(vs));
    ind = -1;
    rep(i,n){
        if (i%len == 0)
            ++ind;
        assert(ind < sz(c));
        c[ind] += vs[i];
    }
    auto get_sum = [len](ll l, ll r, const vector<ll> &a, const vector<ll> &v){
        ll sum = 0ll;
        if (l/len == r/len){
            rep(i,l,r,1ll)
                sum += v[i];
            return sum;
        }
        ll k = ((l/len)+1ll)*len;
        rep(i,l,k-1ll,1ll)
            sum += v[i];
        ll p = (r/len);
        rep(i,(l/len)+1ll,p-1ll,1ll)
            sum += a[i];
        rep(i,p*len,r,1ll)
            sum += v[i];
        return sum;
    };
    while(m--){
        ll l, r, t; cin >> t >> l >> r; --l; --r;
        if (t == 1) cout << get_sum(l, r, s, v) << endl;
        else cout << get_sum(l, r, c, vs) << endl;
    }
}