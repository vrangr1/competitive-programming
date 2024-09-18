/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep 17 20:38:32 IST 2024
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
    ll n; cin >> n;
    vector<pair<ll,ll>> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    auto comp = [](const pair<ll,ll> &p, const pair<ll,ll> &q) {
        auto [x1,y1] = p;
        auto [x2,y2] = q;
        if (x1+y1 != x2+y2)
            return x1+y1 < x2+y2;
        if (x1 != x2) return x1 < x2;
        return y1 < y2;
    };
    set<pair<ll,ll>, decltype(comp)> st(comp);
    for (auto &p : a) st.insert(p);
    debug(st);
    ll sol = 0ll;
    while(sz(st) > 1) {
        auto [sx, sy] = *st.begin();
        st.erase(st.begin());
        auto [lx,ly] = *st.begin();
        st.erase(st.begin());
        // auto [lx,ly] = *st.rbegin();
        // st.erase(prev(st.end()));
        assert(sx + sy <= lx+ly);
        if (llabs(sx+lx-ly) > llabs(sy+ly-lx)) {
            sol += sx*sx;
            ly+=sy;
        }
        else {
            sol += sy*sy;
            lx += sx;
        }
        // if (sx > sy) swap(sx,sy);
        // if (lx > ly) swap(lx,ly);
        // ly+=sy;
        // sol += sx*sx;
        st.emplace(lx,ly);
        debug(st);
    }
    assert(sz(st) == 1);
    auto [x,y] = *st.begin();
    sol += (x+y)*(x+y);
    cout << sol << endl;
}