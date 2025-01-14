/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug 25 09:16:41 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) void(42)
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
#define TEST cout << "1\n"
#define TEST1
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

// IMPORT SNIPPETS HERE
#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif


// END OF SNIPPETS

void generate_test();

int main() {
	fastIO;
    TEST1;
    generate_test();
    #ifdef LOCAL
        cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const ll maxn = 5ll, maxk = 5, maxm = 5ll, maxa = 5ll;

// Generate just a singular test. The multitudinous nature of tests are implemented through a bash script
void generate_test() {
    ll n = grng(maxn)+1ll, k = grng(maxk)+1ll, m = grng(maxm)+1ll;
    cout << n << " " << k << " " << m << endl;
    rep(i,n) cout << grng(maxa)+1ll << " \n"[i==n-1];
}