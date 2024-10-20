/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 27 20:47:18 IST 2024
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

const ll mod = (ll)1e9+7ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> fs;
    ll sum = 0ll;
    rep(i,m){
        ll a, b, f; cin >> a >> b >> f;
        fs.push_back(f);
        sum += f;
        sum %= mod;
    }
    if (m == 0ll){
        assert(sum == 0ll);
        return void(cout << "0\n");
    }
    auto inv = [](auto &&self, ll n) -> ll {
        if (n <= 1ll) return 1ll;
        return ((mod-mod/n)*self(self,mod%n))%mod;
    };
    ll t = ((n*(n-1ll))/2ll)%mod, q = inv(inv,t), q2 = inv(inv,(t*t)%mod), k2 = ((k*(k-1ll))/2ll)%mod;
    ll sol = ((((sum*k)%mod)*q)%mod + (((k2*q2)%mod)*m)%mod)%mod;
    cout << sol << endl;
}