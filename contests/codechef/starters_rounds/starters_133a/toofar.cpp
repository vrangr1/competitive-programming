/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  8 21:29:21 IST 2024
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

const ll mod = 998244353ll;

vector<ll> fac((int)5e5+1), invfac((int)5e5+1);

ll inv(ll n) {
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fac[0] = fac[1] = 1ll;
    invfac[0] = invfac[1] = 1ll;
    rep(f,2,sz(fac)-1ll,1){
        fac[f] = (fac[f-1]*f)%mod;
        invfac[f] = (invfac[f-1]*inv(f))%mod;
    }
}

ll ncr(ll n, ll r) {
    assert(n>=0 && r >= 0 && n >= r);
    if (n == 0ll) return 1ll;
    ll sol = (fac[n]*invfac[r])%mod;
    return (sol*invfac[n-r])%mod;
}

ll npr(ll n, ll r) {
    assert(n>=0 && r >= 0 && n >= r);
    if (n == 0ll) return 1ll;
    return (fac[n]*invfac[n-r])%mod;
}

void solve(){
    init();
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll k;
    {
        set<ll> st(all(a));
        if (st.find(0) != st.end()) st.erase(0);
        k = sz(st);
    }
    auto get = [&](ll c) -> ll {
        debug(endl,c);
        if (c < k) return 0ll;
        set<ll> st, vals;
        ll z = 0;
        ll sol = 1ll;
        bool first = true;
        rep(i,n) {
            assert(sz(st) + z < c);
            if (a[i]) {
                if (st.find(a[i]) != st.end()) 
                    return 0ll;
                if (first) {
                    vals.insert(a[i]);
                }
                else {
                    if (vals.find(a[i]) == vals.end()) return 0ll;
                }
                st.insert(a[i]);
            }
            else z++;
            if (sz(st) + z == c) {
                debug(sz(st),z);
                sol *= fac[z];
                sol%=mod;
                st.clear();
                z = 0ll;
                if (first) first = false;
            }
        }
        sol *= (npr(c-sz(st),z));
        sol%=mod;
        if (!first) {
            sol*=ncr(m-k,c-k);
            sol%=mod;
        }
        else {
            sol *= ncr(m,z);
            sol%=mod;
        }
        debug(sol);
        return sol;
    };
    ll sol = 0ll;
    rep(c,1,m,1) {
        sol += get(c);
        sol%=mod;
    }
    cout << sol << endl;
}

/*

3

1
4 4
3 0 4 0


4 10
1 1 0 0
6 7
0 1 0 2 3 0

*/