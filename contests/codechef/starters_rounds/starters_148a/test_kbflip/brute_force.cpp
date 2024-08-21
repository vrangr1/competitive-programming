/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 21 20:44:38 IST 2024
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

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    auto get = [&]() -> ll {
        ll z = 0, o = 0;
        for (char &ch : s) z += ch=='0';
        o = n-z;
        return min(z,o);
    };
    auto flip = [&](ll l, ll r) -> void {
        assert(r >= l);
        assert(l >= 0ll && r < n);
        rep(i,l,r,1) s[i] = (s[i]=='1'?'0':'1');
    };
    ll sol = get();
    [[maybe_unused]] ll sl = -1, sr = -1;
    rep(i,n) {
        rep(j,i,n-1ll,1) {
            if (j-i+1ll > k) break;
            flip(i,j);
            ll cur = get();
            if (cur > sol) {
                sol = cur;
                sl = i;
                sr = j;
            }
            flip(i,j);
        }
    }
    cout << sol << endl;
    debug(sl,sr);
}