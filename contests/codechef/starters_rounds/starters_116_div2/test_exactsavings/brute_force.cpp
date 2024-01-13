/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
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

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, x, z; cin >> n >> x >> z;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (z%x == 0ll) return void(cout << z/x << endl);
    vector<ll> sums(x,LLONG_MAX);
    auto precomp = [&](){
        vector<ll> sel(n);
        auto getsum = [&]() -> ll {
            ll s = 0ll;
            rep(i,n) if (sel[i]) s += a[i];
            return s;
        };
        rep(ct,n+1ll){
            fill(sel.begin(),sel.begin()+ct,0);
            fill(sel.begin()+ct,sel.end(),1);
            do{
                ll s = getsum();
                sums[s%x] = min(sums[s%x],s);
            }while(next_permutation(all(sel)));
        };
    };
    precomp();
    ll r = x-(z%x);
    assert(sums[r] == LLONG_MAX || (sums[r]+z)%x == 0ll);
    cout << (sums[r] == LLONG_MAX?-1:((sums[r]+z)/x)) << endl;
}