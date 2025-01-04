/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Jan  4 20:36:41 IST 2025
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
    ll l, r; cin >> l >> r;
    ll sol = LLONG_MIN, sa = 0, sb = 0, sc = 0;
    auto comp = [](ll a, ll b, ll c) -> ll {
        return (a^b) + (b^c) + (c^a);
    };
    rep(a,l,r-2ll,1ll) {
        rep(b,a+1ll,r-1ll,1ll) {
            rep(c,b+1ll,r,1ll) {
                if (comp(a,b,c) > sol) {
                    sol = comp(a,b,c);
                    sa=a;
                    sb=b;
                    sc=c;
                }
            }
        }
    }
    cout << sa << " " << sb << " " << sc << endl;
}