/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jun  3 21:09:44 IST 2024
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
    vector<pair<ll,ll>> fs(k+1);
    rep(i,k) cin >> fs[i].first >> fs[i].second;
    vector<ll> order(k);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        auto &a = fs[i], &b = fs[j];
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    });
    ll cx = 0, cy = 0;
    vector<ll> a(k,0ll);
    debug(fs,order);
    auto get = [&](ll x, ll y) -> ll {
        assert(cy < y);
        assert(cx <= x);
        ll sol = (min(x+1ll,n)-max(1ll,cx)+1ll)*(y-1ll);
        assert(sol >= 0ll);
        if (cx && cy) sol--;
        return sol;
    };
    ll sol = 0ll;
    for (ll ind : order) {
        auto [x,y] = fs[ind];
        assert(cy < y);
        if (x < cx) continue;
        a[ind] = true;
        debug(endl,sol);
        sol += get(x,y);
        cx = x+1;
        cy = y-1;
        debug(sol,cx,cy);
    }
    // assert(sol > 0ll);
    if (cx <= n) {
        sol += (n-max(1ll,cx)+1ll)*(m);
        if (cx && cy) sol--;
    }
    assert(sol > 0ll);
    cout << sol << endl;
    print_vec(a);
}

/*
5

1
2 2 3
1 1
1 2
2 2


5 5 4
1 2
2 2
3 4
4 3
2 5 9
1 2
1 5
1 1
2 2
2 4
2 5
1 4
2 3
1 3
6 4 4
6 2
1 3
1 4
1 2
3 4 5
2 1
3 2
1 4
1 3
2 4



*/