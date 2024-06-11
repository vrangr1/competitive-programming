/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun  9 21:50:05 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
#define yes "YES\n"
#define no "NO\n"
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

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

template <const ll p>
class stringhash{
private:
    ll inv(ll m) {
        if (m <= 1ll) return 1ll;
        return ((p-p/m)*inv(p%m))%p;
    }

    ll pwr(ll b, ll m) {
        if (m == 0ll) return 1ll;
        ll b2 = (b*b)%p;
        if (m%2ll) return (b*pwr(b2,m/2ll))%p;
        return pwr(b2,m/2ll);
    }

public:
    ll n, a;
    vector<ll> vals;
    stringhash(const string &s) {
        n = sz(s);
        a = grng(p-40ll)+26ll;
        vals.resize(n);
        rep(i,n) vals[i] = s[i]-'a';
        rep(i,1,n-1ll,1ll) {
            vals[i] = (vals[i-1]+(vals[i]*pwr(a,i))%p)%p;
        }
    }

    ll get(ll i, ll j) {
        if (i == 0ll) return vals[j];
        return (((vals[j]-vals[i-1]+p)%p)*inv(pwr(a,i)))%p;
    }

    bool same(ll i1, ll j1, ll i2, ll j2) {
        return get(i1,j1) == get(i2,j2);
    }
};

void solve() {
    string s; cin >> s;
    ll n = sz(s);
    stringhash<998244353ll> hash1(s);
    stringhash<1000000007ll> hash2(s);
    stringhash<1000000123ll> hash3(s);
    auto check = [&](ll i1, ll j1, ll i2, ll j2) -> bool {
        return hash1.same(i1,j1,i2,j2) && hash2.same(i1,j1,i2,j2) && hash3.same(i1,j1,i2,j2);
    };
    vector<ll> act(n,0ll);
    act[0] = (s[0]=='a');
    rep(i,1,n-1ll,1) 
        act[i] = act[i-1]+(ll)(s[i]=='a');
    auto all_as = [&](ll i, ll j) -> bool {
        assert(i<=j);
        ll m = j-i+1ll;
        ll ct = act[j];
        if (i) ct -= act[i-1];
        return ct == m;
    };
    auto isvalid = [&](ll ind, ll m) -> ll {
        
    };
    auto proc = [&](ll ind) -> ll {
        ll len = n-ind;
    };
    rep(i,n) {
        
    }
}