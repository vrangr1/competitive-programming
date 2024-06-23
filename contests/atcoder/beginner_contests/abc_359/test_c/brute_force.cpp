/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun 22 17:59:15 IST 2024
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

void solve() {
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    debug(sx,sy,tx,ty);
    if (sx == tx || sy == ty) {
        if (sx == tx) return void(cout << llabs(sy-ty) << endl);
        ll d = llabs(sx-tx);
        if (((sx+sy)%2ll && sx < tx) || ((sx+sy)%2ll == 0ll && sx > tx)) cout << (d+1ll)/2ll << endl;
        else cout << d/2ll << endl;
        return;
    }
    ll d1 = llabs(sx-tx), d2 = llabs(sy-ty);
    if (d1 > d2) swap(d1,d2);
    debug(d1,d2);
    ll sol = d1;
    if (sx <= tx) sx += d1;
    else sx -= d1;
    if (sy <= ty) sy += d1;
    else sy -= d1;
    debug(sx,sy);
    assert(sx == tx || sy == ty);
    d2 = max(llabs(sx-tx),llabs(sy-ty));
    if (sx == tx) sol += d2;
    else if (((sx+sy)%2ll && sx < tx) || ((sx+sy)%2ll == 0ll && sx > tx)) sol += (d2+1ll)/2ll;
    else sol += d2/2ll;
    cout << sol << endl;
}