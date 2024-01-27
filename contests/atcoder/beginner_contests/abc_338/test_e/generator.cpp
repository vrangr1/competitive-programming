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
#include <random>
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
#define TEST cout << "1\n"
#define TEST1
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
mt19937 rng((uint)chrono::steady_clock::now().time_since_epoch().count());
ull grng(const ull maxval){return rng()%maxval;}
void generate_test();

int main(){
	fastIO;
    TEST1;
    generate_test();
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll maxn = 2;

// Generate just a singular test. The multitudinous nature of tests are implemented through a bash script
void generate_test(){
    ll n = grng(maxn)+2ll;
    cout << n << endl;
    set<ll> st;
    rep(i,1ll,2ll*n,1ll) st.insert(i);
    vector<ll> ed(2ll*n + 2ll);
    auto get_rand = [&]() -> ll {
        ll c = grng(sz(st));
        auto it = st.begin();
        while(c--){
            it++;
        }
        ll val = *it;
        st.erase(it);
        return val;
    };
    rep(i,n){
        ll a = get_rand(), b = get_rand();
        ed[a] = b;
        ed[b] = a;
    }
    assert(st.empty());
    vector<bool> vis(2ll*n + 2ll,false);
    rep(i,1ll,2ll*n,1ll){
        if (vis[i] || vis[ed[i]]) continue;
        cout << ed[i] << " " << i << endl;
        vis[i] = true;
        vis[ed[i]] = true;
    }
}