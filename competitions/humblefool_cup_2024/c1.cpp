/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Apr 16 20:54:28 IST 2024
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
    ll n; cin >> n;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    ll sum = 0ll, mxsum = LLONG_MIN, dsum = accumulate(all(d),0ll);
    rep(i,n-1ll)
        sum += (i+1ll)*d[i];
    mxsum = sum;
    rep(i,1ll,n-1ll,1ll){
        if (i == 1ll){
            sum -= (dsum-d[n-1ll]);
            sum += (n-1ll)*d[n-1ll];
        }
        else{
            sum -= (dsum-d[i-2ll]);
            sum += (n-1ll)*d[i-2ll];
        }
        mxsum = max(mxsum,sum);
    }
    sum = 0ll;
    rep(i,n-1ll)
        sum += (i+1ll)*d[n-i-1ll];
    mxsum = max(sum,mxsum);
    rep(i,n-2ll,0ll,-1ll){
        if (i == n-2ll){
            sum -= (dsum-d[0]);
            sum += (n-1ll)*d[0];
        }
        else{
            sum -= (dsum-d[i+2ll]);
            sum += (n-1ll)*d[i+2ll];
        }
        mxsum = max(mxsum,sum);
    }
    cout << mxsum << endl;
    
}