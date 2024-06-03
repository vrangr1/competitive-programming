/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun  1 17:49:13 IST 2024
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

// END OF SNIPPETS

int main() {
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = 998244353ll;

void solve() {
    ll n, m; cin >> n >> m;
    // auto get = [n,m](ll bit) mutable -> ll {
    //     ll v = (1ll<<bit);
    //     if (n < v) return 0ll;
    //     ll left = v%mod, sol = (((n&v) > 0ll) && (n > v));
    //     if ((63ll-__builtin_clzll(v)) == (63ll-__builtin_clzll(n))) {
    //         assert((v&n));
    //         sol = 1ll + (v<n);
    //         rep(cur,bit-1ll,0ll,-1ll) {
    //             ll cv = (1ll<<cur);
    //             if ((n&cv) == 0ll) continue;
    //             sol += (1ll<<(cur))-1ll;
    //         }
    //         debug(bit,sol);
    //         return sol;
    //     }
    //     debug(bit,left);
    //     rep(cur,59ll,bit+1ll,-1ll) {
    //         ll cv = (1ll<<cur);
    //         if ((n&cv) == 0ll) continue;
    //         ll diff = cur-bit-1ll;
    //         debug(cur,bit);
    //         if (diff > 0)
    //         sol += ((1ll<<diff));
    //         sol%=mod;
    //     }
    //     debug(sol);
    //     return ((sol+1ll)*left)%mod;
    // };
    auto get = [n,m](ll bit) mutable -> ll {
        ll v = (1ll<<bit), sol = ((n&v)>0ll);
        rep(cur,59ll,0ll,-1ll) {
            ll cv = (1ll<<cur);
            if (cur == bit || ((n&cv) == 0ll)) continue;
            if (cur > bit) {
                sol += (1ll<<(cur-1ll));
                sol%=mod;
            }
            else if (v&n) {
                sol += (1ll<<(cur));
                sol%=mod;
            }
        }
        return sol;
    };
    ll sol = 0ll;
    rep(bit,60ll) {
        ll v = (1ll<<bit);
        if (v > n) break;
        if ((v&m) == 0ll) continue;
        debug(endl,get(bit));
        sol += get(bit);
        debug(endl);
        sol%=mod;
    }
    cout << sol << endl;
}