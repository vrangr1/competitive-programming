/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 31 20:10:45 IST 2024
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

const ll mod = ll(1e9)+7ll;

void solve() {
    ll n; cin >> n;
    vector<ll> tpr(n+1ll), tprsum(n+1ll), i2tprsum(n+1ll), itprsum(n+1ll);
    tpr[0] = 1ll;
    tpr[1] = 2ll;
    tprsum[0] = i2tprsum[0] = itprsum[0] = 0ll;
    tprsum[1] = i2tprsum[1] = itprsum[1] = 2ll;
    rep(i,2,n,1ll) {
        tpr[i] = (tpr[i-1]*2ll)%mod;
        tprsum[i] = (tprsum[i-1]+tpr[i])%mod;
        i2tprsum[i] = (i2tprsum[i-1] + (((i*i)%mod)*tpr[i])%mod)%mod;
        itprsum[i] = (itprsum[i-1] + (i*tpr[i])%mod)%mod;
    }
    ll sol = 0ll;
    rep(i,2,n,1) {
        ll cur = (tpr[n-i]*((i*i)%mod))%mod;
        cur*=tprsum[i-1ll];
        cur%=mod;
        cur += (tpr[n-i]*i2tprsum[i-1])%mod;
        cur%=mod;
        cur = (cur - (((tpr[n-i+1]*i)%mod)*itprsum[i-1])%mod +mod)%mod;
        cur%=mod;
        sol += cur;
        sol%=mod;
    }
    cout << sol << endl;
}