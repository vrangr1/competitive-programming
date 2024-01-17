/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jan 15 20:21:29 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<ll> c(n), order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j){
        return a[i] < a[j];
    });
    sort(all(b));
    ll l = 0, r = m-1ll;
    rep(i,(n+1ll)/2ll){
        assert(l<=r);
        ll ind = order[i];
        ll o = order[n-i-1ll];
        if (ind == o){
            if (llabs(a[ind]-b[l]) >= llabs(a[ind]-b[r])){
                c[ind] = b[l++];
            }
            else c[ind] = b[r--];
            continue;
        }
        assert(l<r);
        c[ind] = b[r--];
        c[o] = b[l++];
    }
    ll sol = 0ll;
    rep(i,n)
        sol += llabs(a[i]-c[i]);
    debug(a,b,c);
    cout << sol << endl;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<ll> c(n), order(n);
    // iota(all(order),0ll);
    // sort(all(order),[&](const ll &i, const ll &j){
    //     return a[i] < a[j];
    // });
    sort(all(a));
    sort(all(b));
    deque<ll> dq(all(b));
    auto dbg = [](vector<ll> a)->void{
        sort(all(a));
        debug(a);
    };
    dbg(a);
    debug(dq);
    ll l = 0, r = n-1ll;
    ll diff = 0ll;
    while(l <= r){
        if (l == r){
            diff += max(llabs(a[l]-dq.front()),llabs(a[l]-dq.back()));
            break;
        }
        assert(sz(dq)>1);
        ll left = llabs(a[r]-dq.front()), right = llabs(a[l]-dq.back());
        if (left >= right){
            diff += left;
            r--;
            dq.pop_front();
        }
        else{
            diff += right;
            l++;
            dq.pop_back();
        }
    }
    cout << diff << endl;
}

/*

1
4 6
6 1 2 4
3 5 1 7 2 3

*/