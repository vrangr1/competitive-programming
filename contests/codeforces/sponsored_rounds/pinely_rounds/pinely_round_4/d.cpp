/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 28 20:29:35 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
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

// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

ll maxn = (ll)1e5 + 3ll;
vector<bool> isprime(maxn,false);
vector<ll> primes;
void sieve() {
    static bool init = false;
    if (init) return;
    init = true;
    isprime[2] = isprime[3] = true;
    rep(f,4,maxn-1ll,2ll) isprime[f] = false;
    rep(f,3,maxn-1ll,2ll) {
        if (!isprime[f]) continue;
        rep(n,2ll*f,maxn-1ll,f)
            isprime[n] = false;
    }
    primes.push_back(2);
    rep(f,3,maxn-1ll,1ll) if (isprime[f]) primes.push_back(f);
}

void solve() {
    sieve();
    ll n; cin >> n;
    vector<ll> colors(n+1,-1);
    vector<ll> g(n+1);
    colors[1] = 1;
    colors[2] = 2;
    colors[3] = 2;
    rep(i,4,n,1) {
        if (isprime[i]) {
            colors[i] = 1;
            continue;
        }
        unordered_set<ll> st;
        for (auto &p : primes) {
            ll v = (p^i);
            if (v > i) continue;
            st.insert(colors[v]);
        }
        ll mex = 1ll;
        while(st.find(mex) != st.end()) mex++;
        colors[i] = mex;
    }
    cout << *max_element(all(colors));
    rep(i,1,n,1) cout << colors[i] << " \n"[i==n];
}