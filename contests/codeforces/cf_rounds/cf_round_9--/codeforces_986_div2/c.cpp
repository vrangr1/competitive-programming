/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 10 21:35:16 IST 2024
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
    ll n, m, v; cin >> n >> m >> v;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (m == n) {
        if (*min_element(all(a)) >= v) cout << "0\n";
        else cout << "-1\n";
        return;
    }
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto get = [&](ll l, ll r) -> ll {
        if (l > r) return 0;
        if (l == 0ll) return psum[r];
        return psum[r] - psum[l-1ll];
    };
    vector<pair<ll,ll>> dpl(n), dpr(n);
    ll cur, sol = -1;
    if (a[0] >= v) {
        dpl[0] = {1ll,0ll};
        cur = 0ll;
        if (m == 1ll) sol = get(1,n-1ll);
    } else {
        cur = a[0];
        dpl[0] = {0ll,-1ll};
    }
    rep(i,1,n-1ll,1) {
        cur += a[i];
        dpl[i] = dpl[i-1];
        if (cur >= v && dpl[i].first < m) {
            dpl[i].first++;
            if (dpl[i].first == m) {
                sol = max(sol,get(i+1,n-1ll));
            }
            dpl[i].second = i;
            cur = 0ll;
        }
    }
    assert(dpl.back().first <= m);
    if (dpl.back().first == m) {
        sol = max(sol,get(dpl.back().second+1,n-1ll));
    }
    if (a.back() >= v) {
        dpr[n-1] = {1ll,n-1ll};
        cur = 0ll;
        if (m == 1) sol = max(sol,get(0,n-2ll));
    } else {
        cur = a.back();
        dpr[n-1] = {0ll,n};
    }
    rep(i,n-2ll,0ll,-1) {
        cur += a[i];
        dpr[i] = dpr[i+1];
        if (cur >= v && dpr[i].first < m) {
            dpr[i].first++;
            if (dpr[i].first == m) sol = max(sol,get(0,i-1ll));
            dpr[i].second = i;
            cur = 0ll;
        }
    }
    assert(dpr[0].first <= m);
    if (dpr[0].first == m) {
        sol = max(sol,get(0,dpr[0].second-1));
    }
    debug(dpl,dpr,sol);
    dpr.emplace_back(0,n);
    rep(i,1,n-2ll,1) {
        auto [lct, li] = dpl[i-1];
        auto [rct, ri] = dpr[i+1];
        if (lct + rct < m) continue;
        ll low = ri, high = n;
        while(low < high) {
            ll mid = (low+high+1ll)/2ll;
            auto [mct, mi] = dpr[mid];
            assert(mi >= mid);
            if (lct+mct >= m) low = mi;
            else high = mid-1ll;
        }
        auto [fct, fi] = dpr[low];
        if (lct + fct != m) {
            debug(i,lct,li,rct,ri,fct,fi,endl);
            exit(0);
        }
        assert(lct + fct == m);
        sol = max(sol,get(li+1,fi-1));
    }
    cout << sol << endl;
}