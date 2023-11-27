/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Nov 27 22:06:11 IST 2023
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

ll get_diff(ll a, ll b, ll x){
    a+=x;
    b+=x;
    a>>=1ll;
    b>>=1ll;
    return llabs(a-b);
}

void solve(){
    ll n; cin >> n;
    ll og = n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll ct = 0, cur = 0;
    vector<ll> ops;
    while(a.front() < a.back()){
        if (get_diff(a.front(),a.back(),0ll) <= get_diff(a.front(),a.back(),1ll)){
            cur++;
            a.front()>>=1ll;
            a.back()>>=1ll;
            if (ct+cur <= og)
                ops.push_back(0);
            continue;
        }
        else{
            a.front()++;
            a.back()++;
            a.front()>>=1ll;
            a.back()>>=1ll;
            ct+=cur;
            cur = 0ll;
            if (ct < og) ops.push_back(1);
            ct++;
        }
    }
    ct += cur;
    debug(a.front(),a.back());
    assert(a.front() == a.back());
    cout << ct << endl;
    if (ct <= n) print_vec(ops);
}