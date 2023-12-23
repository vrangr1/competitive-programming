/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
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
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST cout << "1\n"
#define TEST1
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define qwe(r,t,y)
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

const ll maxp = 50, maxr = 500;
vector<bool> prime(maxp+1ll,true);
vector<ll> primes;

void init(){
    static bool init = false;
    if(init) return;
    init = true;
    ll f = 2ll;
    rep(i,f*f,maxp,f)
        prime[i] = false;
    primes.push_back(2ll);
    rep(i,3ll,maxp,2ll){
        if (!prime[i]) continue;
        primes.push_back(i);
        rep(j,i*i,maxp,i)
            prime[j] = false;
    }
}

// Generate just a singular test. The multitudinous nature of tests are implemented through a bash script
void generate_test(){
    init();
    ll r = grng(maxr)+1ll, l = grng(r)+1ll;
    ll p = primes[grng(sz(primes))];
    cout << l << space << r << " " << p;
}