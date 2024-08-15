/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Aug 15 05:27:00 IST 2024
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
#ifndef NCR_SETUP_HPP
#define NCR_SETUP_HPP
#include <vector>
#include <assert.h>
#include <climits>
const long long maxn = (long long)1e6 + 10ll;
const bool MOD_ENABLE = true;
// ALL FACTORIALS, INVERSE_FACTORIALS AND NCRS MUST BE < LLONG_MAX WHEN MOD_ENABLE == false
const long long mod = (MOD_ENABLE?(long long)1e9 + 7ll:LLONG_MAX);
std::vector<long long> factorial(maxn), inverse_factorial(maxn);

long long inv(long long n) {
    if (n <= 1) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    factorial[0] = factorial[1] = 1;
    inverse_factorial[0] = inverse_factorial[1] = 1;
    for (long long f = 2; f < maxn; f++) {
        factorial[f] = (factorial[f-1]*f)%mod;
        inverse_factorial[f] = (inverse_factorial[f-1]*inv(f))%mod;
    }
}

long long ncr(long long n, long long r) {
    assert(maxn > n && n >= r && r >= 0ll);
    return (((factorial[n]*factorial[r])%mod)*inverse_factorial[n-r])%mod;
}
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


void solve() {
    init();
    ll n, m; cin >> n >> m;
    ll sol = 0ll;
    rep(v,n-1ll,m-2ll,1ll) {
        ll stt = v+1ll, edd = m-1ll;
        debug(endl,v,v-1ll,n-2ll,ncr(v-1ll,n-2ll),edd,stt);
        if (v+edd <= m+1ll) {
            sol += (ncr(v-1ll,n-2ll)*(edd-stt+1ll))%mod;
            sol %= mod;
        }
        else {
            ll mx = m+1ll-v;
            if (mx >= stt)
                sol = (sol + (ncr(v-1ll,n-2ll)*(mx-stt+1ll))%mod)%mod;
            
        }
    }
    cout << sol << endl;
}