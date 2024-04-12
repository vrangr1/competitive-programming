/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Apr 11 21:15:17 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = (ll)1e9+7ll;

void solve(){
    ll x, y, n; cin >> x >> y >> n;
    if (x > y) swap(x,y);
    vector<ll> f(y);
    rep(i,y) cin >> f[i];
    if (n < y) return void(cout << f[n] << endl);
    auto mult = [](vector<vector<ll>> &a, vector<vector<ll>> &b) -> vector<vector<ll>> {
        ll m = sz(a);
        vector<vector<ll>> sol(m,vector<ll>(m,0ll));
        rep(i,m){
            rep(j,m){
                rep(k,m){
                    sol[i][k] += (a[i][j]*b[j][k])%mod;
                    sol[i][k]%=mod;
                }
            }
        }
        return sol;
    };
    auto pr = [&mult](vector<vector<ll>> &a, ll n) -> vector<vector<ll>> {
        assert(n>=1ll);
        if (n == 1ll) return a;
        ll m = sz(a);
        vector<vector<ll>> sol(m,vector<ll>(m,0ll));
        rep(i,m) sol[i][i] = 1ll;
        while(n>1){
            auto a2 = mult(a,a);
            if (n%2ll){
                sol = mult(sol,a);
            }
            swap(a,a2);
            n>>=1ll;
        }
        return mult(sol,a);
    };
    vector<vector<ll>> mat(y,vector<ll>(y,0ll));
    mat[0][x-1ll] = 1ll;
    mat[0][y-1ll] = 1ll;
    rep(i,1,y-1ll,1)
        mat[i][i-1ll] = 1ll;
    debug(mat);
    debug(f);
    mat = pr(mat,n-y+1ll);
    ll sol = 0ll;
    reverse(all(f));
    rep(i,y){
        sol += (mat[0][i]*f[i])%mod;
        sol%=mod;
    }
    cout << sol << endl;
}