/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan 17 20:12:46 IST 2024
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

void solve(){
    ll n, m; cin >> n >> m;
    if (n == 1ll && m == 1ll) return void(cout << "1\n");
    if (n < m) swap(n,m);
    ll k = (n)/2ll;
    // debug(n,m,k);
    if (n == m){
        if (n%2ll) return void(cout << ((k+1ll)*(k+1ll))%mod << endl);
        ll sol = (k*k)%mod;
        sol += ((k)*(k+1ll))%mod;
        sol%=mod;
        sol += ((k)*(k+1ll))%mod;
        sol%=mod;
        sol += ((k+1ll)*(k+1ll))%mod;
        sol%=mod;
        cout << sol << endl;
        return;
    }
    auto inv = [](auto &&self, ll n) -> ll {
        if (n <= 1ll) return 1ll;
        return ((mod-mod/n)*self(self,mod%n))%mod;
    };
    ll sol = 0ll, two = inv(inv,2ll);
    auto comp = [two](ll n){
        assert(n>=1ll);
        ll sol = (n*(n+1ll))%mod;
        sol *= two;
        sol %= mod;
        return sol;
    };
    if (n%2ll){
        if (m <= k+1ll){
            return void(cout << (comp(m)*(k+1ll))%mod << endl);
        }
        assert((m-k) <= k+1ll);
        sol = comp(k+1ll) - comp(m-k-1ll) + mod;
        sol %= mod;
        sol *= (k+1ll);
        sol %= mod;
        return void(cout << sol << endl);
    }
    if (m <= k+1ll){
        sol = comp(m);
        sol *= (2ll*k+1ll);
        sol %= mod;
        return void(cout << sol << endl);
    }
    assert((m-k) <= k+1ll);
    sol = comp(k+1ll) - comp(m-k-1ll) + mod;
    sol *= (2ll*k+1ll);
    sol %= mod;
    return void(cout << sol << endl);
}