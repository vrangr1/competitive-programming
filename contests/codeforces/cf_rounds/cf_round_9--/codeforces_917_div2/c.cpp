/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec 24 20:27:43 IST 2023
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

void solve1(){
    ll n, k, d; cin >> n >> k >> d;
    vector<ll> a(n), v(k);
    rep(i,n) cin >> a[i];
    rep(i,k){
        cin >> v[i];
        --v[i];
    }
    vector<ll> vs = v;
    sort(all(vs));
    vector<ll> low(n, LLONG_MAX), high(n,LLONG_MAX);
    auto get_ct = [&] (ll days, ll ind){
        vector<ll>::iterator iter = lower_bound(all(vs),ind);
        ll x = (days/k)*((ll)(vs.end()-iter));
        if (days%k == 0ll) return x;
        days%=k;
        iter = lower_bound(vs.begin(),vs.begin()+days, ind);
        x += ((ll)((vs.begin()+days) - iter));
        return x;
    };
    auto lbsch = [&] (auto &&self, ll l, ll h, const ll req, const ll ind) -> ll {
        if (ind == 2) debug(l,h);
        if (l > h) return LLONG_MAX;
        if (l == h){
            ll x = get_ct(l,ind);
            if (x != req) return LLONG_MAX;
            return l;
        }
        ll mid = (l+h+1ll)/2ll;
        ll x = get_ct(mid,ind);
        if (ind == 2) debug(mid,x);
        if (x > req) return self(self, l, mid-1ll, req, ind);
        if (x == req){
            if (mid == l+1ll){
                x = get_ct(l,ind);
                if (x == req) return l;
                else return mid;
            }
            return self(self,l,mid,req,ind);
        }
        return self(self,mid+1ll,h,req,ind);
    };
    auto hbsch = [&] (auto &&self, ll l, ll h, const ll req, const ll ind) -> ll {
        if (l > h) return LLONG_MAX;
        if (l == h){
            ll x = get_ct(l,ind);
            if (x != req) return LLONG_MAX;
            return l;
        }
        ll mid = (l+h)/2ll;
        ll x = get_ct(mid,ind);
        if (x > req) return self(self, l, mid-1ll, req, ind);
        if (x == req){
            if (mid == h-1ll){
                x = get_ct(h,ind);
                if (x == req) return h;
                else return mid;
            }
            return self(self,mid,h,req,ind);
        }
        return self(self,mid+1ll,h,req,ind);
    };
    auto process = [&] (const ll ind) -> void {
        if (a[ind] > ind+1){
            return;
        }
        ll req = ind+1-a[ind];
        debug(ind,req);
        low[ind] = lbsch(lbsch,0,d,req,ind);
        if (low[ind] == LLONG_MAX) return;
        high[ind] = hbsch(hbsch,low[ind],low[ind]+k,req,ind);
        assert(high[ind] != LLONG_MAX);
    };
    rep(i,n) process(i);
    debug(k,d,a,v,low,high);
    ll mxct = 0;
    rep(i,n){
        if (low[i] == LLONG_MAX) continue;
        ll ct = 0;
        rep(j,n){
            if (low[j] == LLONG_MAX) continue;
            if (high[j] < low[i] || low[j] > high[i]) continue;
            ct++;
        }
        mxct = max(ct,mxct);
    }
    cout << mxct << endl;
}

/*

5

1
3 4 4
1 2 3
1 3 2 3

1
6 2 3
6 1 2 4 1 5
6 6

1
5 1 1
0 5 0 5 0
5

1
1 1 1
1
1

1
3 4 6
1 2 3
1 3 2 3




*/