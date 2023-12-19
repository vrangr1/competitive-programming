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
    TEST;
    generate_test();
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

ll maxn = 12;

// Generate just a singular test. The multitudinous nature of tests are implemented through a bash script
void generate_test(){
    ll n = grng(maxn)+2ll;
    cout << n << endl;
    vector<ll> parent(n+1ll,-1);
    vector<ll> rem(n-1ll);
    iota(all(rem),2ll);
    shuffle(all(rem),rng);
    // debug(rem);
    auto gen = [&] (auto &&self, ll node) -> void {
        if (rem.empty()) return;
        ll nc = grng(sz(rem))+1ll;
        vector<ll> children(nc);
        rep(i,nc){
            assert(!rem.empty());
            children[i] = rem.back();
            parent[rem.back()] = node;
            rem.pop_back();
        }
        if (rem.empty()) return;
        rep(i,nc){
            self(self,children[i]);
        }
    };
    gen(gen,1ll);
    rep(i,2ll,n,1ll) assert(parent[i] != -1ll);
    rep(i,2ll,n,1ll)
        cout << parent[i] << " \n"[i==n];
}