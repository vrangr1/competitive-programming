/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep  1 20:36:17 IST 2024
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
    ll n, k; cin >> n >> k;
    ll g = 0;
    rep(i,n) {
        ll v; cin >> v;
        g = gcd(g,v);
    }
    if (n == 1ll) {
        if (g > k-1ll) cout << k-1ll << endl;
        else cout << k << endl;
        return;
    }
    if (g == 1) return void(cout << n+k-1 << endl);
    ll mex = 1;
    --k;
    rep(i,1,n-1ll,1) {
        assert(g*i > mex);
        ll v = g*i;
        debug(endl,v,mex,k);
        if (k >= v-mex) {
            k-=v-mex;
            mex = v+1ll;
            continue;
        }
        mex += k;
        k = 0ll;
        break;
    }
    cout << mex+k << endl;
}