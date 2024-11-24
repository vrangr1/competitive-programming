/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov 23 21:04:09 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll x, m; cin >> x >> m;
    if (x == 1) return void(cout << m << endl);
    // ll sol = 0;
    set<ll> st;
    rep(y,1,(ll)min(x,m),1) {
        ll v = (x^y);
        if ((v%x) == 0 || (v%y) == 0){
            st.insert(y);
        }
        if (v >= 1 && v <= m && ((y%x) == 0 || (y%v) == 0)) {
            st.insert(v);
        }
    }
    if (m > x && __builtin_clzll(m) != __builtin_clzll(x)) {
        ll mx = m;
        ll bit = (1ll<<(63ll-__builtin_clzll(m)));
        bool done = false;
        while(bit > 0) {
            if (done) {
                mx |= bit;
                bit>>=1ll;
                continue;
            }
            if ((bit&m) && (bit&x)) {
                done = true;
                bit>>=1ll;
                continue;
            }
            if (!(bit&m)) {
                if (bit&x) mx |= bit;
                bit>>=1ll;
                continue;
            }
            bit>>=1ll;
        }
        rep(f,1,mx/x,1) {
            ll xy = f*x, y = xy^x;
            assert(y>=1 && y <= m);
            if (y >= 1 && y <= m) st.insert(y);
            // else {
            //     if ((y/2ll) > m) break;
            // }
        }
    }
    cout << sz(st) << endl;
}