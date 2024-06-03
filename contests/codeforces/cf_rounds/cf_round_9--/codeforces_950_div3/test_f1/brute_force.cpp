/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jun  3 22:10:00 IST 2024
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
    ll n, m, k; cin >> n >> m >> k;
    vector<pair<ll,ll>> fs(k);
    rep(i,k) cin >> fs[i].first >> fs[i].second;
    ll sol = 0ll;
    auto check = [&](ll x, ll y) -> bool {
        for (auto [fx, fy] : fs) {
            if (fx >= x && fy <= y) {
                // if (x == 3 && y == 3)
                return false;
            }
        }
        return true;
    };
    rep(i,1,n,1) {
        rep(j,1,m,1) {
            sol += check(i,j);
        }
    }
    cout << sol << endl;

    vector<ll> order(k);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        auto &a = fs[i], &b = fs[j];
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    });
    vector<ll> a(k,0ll);
    ll cx = 0, cy = 0;
    for (ll ind : order) {
        auto [x,y] = fs[ind];
        assert(cy < y);
        if (x < cx) continue;
        a[ind] = true;
        // debug(endl,sol);
        cx = x+1;
        cy = y-1;
        // debug(sol,cx,cy);
    }
    print_vec(a);
}