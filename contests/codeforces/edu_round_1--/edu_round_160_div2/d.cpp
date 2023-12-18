/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec 18 20:55:30 IST 2023
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

const ll mod = 998244353ll;

void solve2(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    if (n == 1ll) return void(cout << "1\n");
    vector<ll> last(2,0ll),cur(2,0ll), save;
    last[1] = 1ll;
    ll mxval = p[0];
    save = last;
    rep(i,1ll,n-1ll,1ll){
        cur[1] = (last[1] + last[0])%mod;

    }
}

void solve(){
    ll n; cin >> n;
    vector<ll> p(n);
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const int &i, const int &j){
        return p[i] < p[j];
    });
    vector<ll> dp(n);
    dp[0] = 1ll;
    rep(i,1ll,n-1ll,1ll){
        if (p[i] > p[i-1ll]){
            dp[i] = dp[i-1]*2ll;
            dp[i]%=mod;
            continue;
        }
        if (p[i-2] > p[i-1]){
            // dp[i] = dp[i-1]
        }
    }
}

void solve1(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const int &i, const int &j){
        return p[i] < p[j];
    });
    ll sum = 0ll;
    auto nc2 = [](const ll n){
        if (n == 0ll) return 0ll;
        return ((n*(n-1ll))/2ll + n)%mod;
    };
    auto process = [&](const ll l, const ll r){
        // ll cur = (l+1ll)*(n-r);
        // cur %= mod;
        ll cur = 0ll;
        cur += nc2(l);
        cur %= mod;
        cur += nc2(n-r-1ll);
        cur %= mod;
        debug(l,r,cur);
        return cur;
    };
    ll l = order.back(), r = l;
    sum += process(l,r);
    sum %= mod;
    
    rep(i,n-2ll,1ll,-1ll){
        l = min(l,order[i]);
        r = max(r,order[i]);
        sum += process(l,r);
        sum %= mod;
    }
    sum++;
    sum%=mod;
    cout << sum << endl;
}

/*

3

1
2
2 1

4
2 4 1 3

1
5
10 2 6 3 4


*/