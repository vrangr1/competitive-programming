/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jan 15 21:29:30 IST 2024
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
#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif
// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class sum{
private:
    ll n, d;
    vector<ll> psum, a;
public:
    sum(){}

    sum(const vector<ll> &a){
        n = sz(a);
        this->a = a;
        psum.resize(n);
    }

    void assign(const vector<ll> &a){
        n = sz(a);
        this->a = a;
        psum.resize(n);
    }

    void build(const ll diff){
        this->d = diff;
        rep(i,n){
            if (i < d) psum[i] = a[i];
            else psum[i] = psum[i-d]+a[i];
        }
    }

    ll query(ll l, ll r){
        r = l + ((r-l)/d)*d;
        return psum[r]-psum[l]+a[l];
    }
};

class segtree{
private:
    ll n, d;
    vector<ll> tree, a;
    sum psum;

    ll get_ind(ll ind){
        return ind/d;
    }
public:
    segtree(const vector<ll> &a){
        this->a = a;
        ll gn = sz(a);
        n = gn;
        gn*=2ll;
        if (gn-(gn&(-gn)) != 0ll)
            gn = 1ll<<(bit_width((ull)gn));
        tree.resize(gn);
        psum.assign(a);
        d == LLONG_MAX;
    }

    void build(const ll diff){
        this->d = diff;
        n = sz(a)/d;
        psum.build(d);
        
    }

    ll query(ll l, ll k){
        ll res = 0ll;
        return res;
    }
};

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<vector<ll>>> queries(n+1ll);
    segtree st(a);
    rep(i,q){
        ll s, d, k; cin >> s >> d >> k;
        queries[d].push_back({s,k});
    }
    rep(d,1ll,n,1ll){

    }
}