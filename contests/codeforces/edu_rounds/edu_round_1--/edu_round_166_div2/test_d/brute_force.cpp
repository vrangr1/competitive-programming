/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 21:33:07 IST 2024
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

#define open '('
#define close ')'

void solve() {
    string s; cin >> s;
    ll sol = 0ll, n = sz(s);
    auto test = [&]() -> bool {
        ll f = 0ll;
        rep(i,n) {
            f += (s[i]==open?1ll:-1ll);
            if (f < 0ll) return false;
        }
        return f==0ll;
    };
    auto flip = [&](ll i, ll j) -> void {
        assert(i<=j);
        rep(k,i,j,1ll)
            s[k] = (s[k]==open?close:open);
    };
    rep(i,n) {
        rep(j,i,n-1ll,1ll) {
            flip(i,j);
            if (test()) {
                debug(i,j,s);
                sol++;
            }
            flip(i,j);
        }
    }
    cout << sol << endl;
}