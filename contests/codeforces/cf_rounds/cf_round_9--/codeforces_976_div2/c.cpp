/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep 29 21:13:12 IST 2024
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
    auto chk = [&](ll a, ll b, ll c, ll d) -> bool {
        return (a|b) - (a&c) == d;
    };
    ll b, c, d; cin >> b >> c >> d;
    ll a = 0;
    rep(bit,64ll) {
        ll val = (1ll<<bit);
        if (chk(1,((b&val) > 0ll),((c&val) > 0ll),((d&val) > 0ll))) 
            a += val;
        else if (!chk(0,((b&val) > 0ll),((c&val) > 0ll),((d&val) > 0ll)))
            return void(cout << "-1\n");
    }
    cout << a << endl;
}