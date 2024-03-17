/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 23:11:34 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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

const ll mod = (ll)1e9+7ll;
const ll maxn = (ll)1e6+3ll;
vector<ll> fac(maxn), invf(maxn,-1ll);

ll inv (ll n){
    if (n <= 1ll) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

ll invfac(ll n){
    if (invf[n] != -1ll) return invf[n];
    if (n <= 1ll) return invf[n] = 1ll;
    invf[n] = inv(fac[n]);
    return invf[n];
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    rep(f,2ll,maxn-1ll,1ll)
        fac[f] = (fac[f-1ll]*f)%mod;
}

ll ncr(ll n, ll r){
    if (n<r) return 1ll;
    ll sol = fac[n];
    sol *= invfac(r);
    sol%=mod;
    sol *= invfac(n-r);
    sol%=mod;
    return sol;
}

void solve(){
    init();
    ll s, p, k; cin >> s >> p >> k;
    if (k > s) return void(cout << "0\n");
    if (k == s) return void(cout << "1\n");
    if (p == 1ll) return void(cout << "0\n");
    if (s <= p){
        cout << ncr(s-1ll,k-1ll) << endl;
        return;
    }
    s-=k;
    p--;
    ll t = min((s/(p+1ll)),k);
    ll sol = 0ll;
    rep(i,t+1ll){
        ll cur = 1ll;
        cur = ncr(k,i);
        cur *= ncr(s-(i*(p+1ll))+k-1ll,k-1ll);
        cur%=mod;
        if (i%2ll) sol = (sol+mod-cur)%mod;
        else sol = (sol+cur)%mod;
    }
    cout << sol << endl;
}