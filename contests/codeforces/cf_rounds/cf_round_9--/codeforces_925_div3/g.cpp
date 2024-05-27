/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb 13 21:51:07 IST 2024
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

const ll mod = 998244353ll, mx = (ll)(2e6)+5ll;
vector<ll> fac(mx),invs(mx,-1ll);

ll inv(ll n){
    if (n <= 1ll) return 1ll;
    return (((mod-mod/n)*inv(mod%n))%mod);
}

ll invfac(ll n){
    assert(n < mx);
    if (invs[n] != -1) return invs[n];
    return invs[n] = inv(fac[n]);
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    rep(f,2ll,mx-1ll,1ll)
        fac[f] = (fac[f-1ll]*f)%mod;
}

void solve(){
    init();
    vector<ll> c(4);
    rep(i,4) cin >> c[i];
    auto ncr = [](ll n, ll r) -> ll {
        assert(r <= n);
        ll sol = (fac[n]*invfac(r))%mod;
        sol *= invfac(n-r);
        return sol%mod;
    };
    if (llabs(c[0]-c[1]) > 1ll) return void(cout << "0\n");
    if (c[0] == c[1] && c[0] == 0){
        if (c[2] && c[3]) return void(cout << "0\n");
        cout << "1\n";
        return;
    }
    if (c[2] == 0 && c[3] == 0){
        if (c[0] == c[1]) return void(cout << "2\n");
        cout << "1\n";
        return;
    }
    if (c[2] == 0){
        ll sol;
        if (c[0] == c[1]){
            sol = ncr(c[3]+c[0]+1-1,c[0]) + ncr(c[3]+c[0]-1,c[0]-1);
            sol%=mod;
        }
        else if (c[0] > c[1]){
            sol = ncr(c[3]+c[0]-1,c[0]-1);
        }
        else{
            sol = ncr(c[3]+c[1]-1,c[1]-1);
        }
        cout << sol << endl;
        return;
    }
    else if (c[3] == 0){
        ll sol;
        if (c[0] == c[1]){
            sol = ncr(c[2]+c[0]-1,c[0]-1) + ncr(c[2]+c[0],c[0]);
            sol %= mod;
        }
        else if (c[0] > c[1])
            sol = ncr(c[2]+c[0]-1,c[0]-1);
        else sol = ncr(c[2]+c[1]-1,c[1]-1);
        cout << sol << endl;
        return;
    }
    else{
        ll sol;
        if (c[0] == c[1]){
            sol = (ncr(c[3]+c[0]-1,c[0]-1)*ncr(c[2]+c[0],c[0]))%mod;
            sol += (ncr(c[3]+c[0]+1-1,c[0])*ncr(c[2]+c[0]-1,c[0]-1))%mod;
            sol%=mod;
        }
        else if (c[0] > c[1]){
            sol = ncr(c[3]+c[0]-1,c[0]-1);
            sol *= ncr(c[2]+c[0]-1,c[0]-1);
            sol%=mod;
        }
        else{
            sol = ncr(c[3]+c[1]-1,c[1]-1);
            sol *= ncr(c[2]+c[1]-1,c[1]-1);
            sol%=mod;
        }
        cout << sol << endl;
    }
}