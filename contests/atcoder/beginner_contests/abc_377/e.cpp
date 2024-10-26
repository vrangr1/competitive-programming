/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 17:55:19 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n, k; cin >> n >> k;
    // ++k;
    vector<ll> p(n+1ll);
    rep(i,1,n,1) cin >> p[i];
    vector<vector<ll>> jump(n+1,vector<ll>(66));
    rep(i,1,n,1) {
        // jump[i][0] = p[p[i]];
        jump[i][0] = p[i];
    }
    rep(pr,1,sz(jump[0])-1ll,1) {
        rep(i,1,n,1) {
            // jump[i][pr] = jump[jump[jump[jump[i][pr-1]][pr-1]][pr-1]][pr-1];
            jump[i][pr] = jump[jump[i][pr-1]][pr-1];
        }
    }
    // jump[i][pr] -> apply p 2^pr times == apply pr ops
    vector<vector<ll>> dp(n+1,vector<ll>(66));
    rep(i,1,n,1) dp[i][0] = jump[i][1];
    rep(pr,1,sz(dp[0])-1ll,1) {
        rep(i,1,n,1)
            dp[i][pr] = dp[dp[i][pr-1]][pr-1];
    }
    debug(jump,dp);
    auto getpr = [](ll v) -> ll {
        assert(v>=1ll);
        assert(__builtin_popcountll(v) == 1ll);
        return 63ll-__builtin_clzll(v);
    };
    rep(i,1,n,1) {
        ll cur = k;
        ll sol = i;
        while(cur) {
            ll bit = (cur&(-cur));
            sol = dp[sol][getpr(bit)];
            cur -= bit;
        }
        cout << sol << " \n"[i==n];
    }
}