/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec 21 02:57:13 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = accumulate(all(a),0ll), mx = *max_element(all(a));
    cout << min(sum-mx, sum/3ll) << endl;
}

void solve1(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ct = 0ll;
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    ll total = psum.back(), target = ((total+1ll)/2ll);
    auto bsch = [&](auto &&self, ll low, ll high, const ll i) -> ll {
        assert(low <= high);
        if (low == high) return high%n;
        ll mid = (low+high)/2ll;
        ll val;
        if (psum[mid%n] >= psum[i]) val = psum[mid%n]-psum[i]+a[i];
        else val = total - (psum[i] - a[i] - psum[mid%n]);
        if (val >= target) return self(self, low, mid, i);
        return self(self, mid+1ll, high, i);
    };
    
    debug(n,a,psum,total,target,endl);
    rep(i,n){
        ll ind = bsch(bsch, i, i+n-1ll, i);
        ll left, right;
        if (ind >= i) left = psum[ind] - psum[i] + a[i] - a[ind];
        else left = total - (psum[i] - psum[ind] - a[i]) - a[ind];
        right = total - left - a[ind];
        ll cur = min((left/3ll)*2ll, (right/3ll)*2ll);
        if (left < right) swap(left,right);
        right%=3ll;
        left -= (cur/2ll)*3ll;
        assert(left >= 0ll);
        if (right > 0ll && left+right >= 3ll){
            cur++;
            left -= 3ll-right;
            right = 0ll;
        }
        ll temp = a[ind]+right;
        ll nval = min((left/3ll)*2ll,(temp/3ll)*2ll);
        cur += nval;
        if (left < temp) swap(left,temp);
        temp%=3ll;
        left -= (nval/2ll)*3ll;
        assert(left>=0ll);
        if (temp > 0ll && temp+left >= 3ll){
            cur++;
        }
        ct = max(ct, cur);
    }
    target = ((total+2ll)/3ll)*2ll;
    auto bsch2 = [&](auto &&self, ll low, ll high, const ll i) -> ll {
        assert(low <= high);
        if (low == high) return high%n;
        ll mid = (low+high)/2ll;
        ll val;
        if (psum[mid%n] >= psum[i]) val = psum[mid%n]-psum[i]+a[i];
        else val = total - (psum[i] - a[i] - psum[mid%n]);
        if (val >= target) return self(self, low, mid, i);
        return self(self, mid+1ll, high, i);
    };
    rep(i,n){
        ll ind = bsch2(bsch2, i, i+n-1ll, i);
        // ll prev = (ind-1ll<0ll?n-1ll:ind-1ll), nxt = (ind+1ll<n?ind+1ll:0ll);
        ll left, right;
        if (ind >= i) left = psum[ind] - psum[i] + a[i] - a[ind];
        else left = total - (psum[i] - psum[ind] - a[i]) - a[ind];
        right = total - left - a[ind];
        // ct = max(ct, (total-a[ind])/3ll);
        ct = max(ct, max(left/2ll,right));
    }
    cout << ct << endl;
}