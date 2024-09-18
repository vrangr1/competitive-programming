/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 18 20:02:51 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> ct(n,vector<ll>(3,0));
    rep(i,m) {
        string s; cin >> s;
        rep(j,n)
            if (s[j] == '1') ct[j][1]++;
            else if (s[j] == '0') ct[j][0]++;
            else ct[j][2]++;
    }
    ll sol = 0ll;
    rep(i,n) {
        ll o = ct[i][1], z = ct[i][0], q = ct[i][2];
        if (o > z) swap(o,z);
        if (q <= z-o) {
            o+=q;
        }
        else {
            ll t = z-o;
            o+=t;
            q-=t;
            z+=q/2ll;
            o+=(q+1ll)/2ll;
        }
        sol += o*z;
    }
    cout << sol << endl;
}