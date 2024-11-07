/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Nov  6 20:19:09 IST 2024
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
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    ll ca = 0, cb = 0, ta = 0, tb = 0;
    // rep(ind,1ll,(ll)min({n,m}),1ll) {
    rep(ind,(ll)min(n,m)) {
        ll i = (ind%k);
        // --i;
        debug(endl,i,s[i],ta,tb,ca,cb);
        if (s[i] == 'A') {
            ca++;
            ta += (m-i) + (n-i)-1ll;
            ta += 2ll*cb;
            tb -= 2ll*cb;
        } else {
            cb++;
            tb += (m-i) + (n-i)-1ll;
            tb += 2ll*ca;
            ta -= 2ll*ca;
        }
    }
    debug(endl,ta,tb,ca,cb);
    if (ta > tb) cout << "Alice\n";
    else if (ta == tb) cout << "Draw\n";
    else cout << "Bob\n";
}