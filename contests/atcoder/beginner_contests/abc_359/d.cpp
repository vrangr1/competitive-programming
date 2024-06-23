/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun 22 17:45:27 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = 998244353ll;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> ct(n,2);
    rep(i,n) if (s[i] != '?') ct[i] = 1;
    vector<vector<ll>> g(n);
    rep(i,n-k+1ll) {
        bool palin = true;
        rep(j,k/2) {
            ll l = i+j, r = i+k-j-1ll;
            if (s[l] != '?' && s[r] != '?') {
                if (s[l] == s[r]) continue;
                palin = false;
                break;
            }
        }
        if (!palin) continue;
        rep(j,k/2) {
            ll l = i+j, r = i+k-j-1ll;
            if (s[l] != '?' && s[r] != '?') {
                assert(s[l] == s[r]);
                continue;
            }
            if (s[l] != '?' || s[r] != '?') {
                if (s[l] != '?') {
                    ct[r] = 1;
                    s[r] = (s[l] == 'A'?'B':'A');
                }
                else {
                    ct[l] = 1;
                    s[l] = (s[r] == 'A'?'B':'A');
                }
                palin = false;
                continue;
            }
        }
    }
}