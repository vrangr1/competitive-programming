/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 27 18:37:55 IST 2024
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
    ll n, q; cin >> n >> q;
    vector<tuple<ll,ll,ll>> ops;
    rep(i,q) {
        ll l, r, c; cin >> l >> r >> c; --l;--r;
        ops.emplace_back(l,r,c);
    }
    sort(all(ops),[&](const tuple<ll,ll,ll> &a, const tuple<ll,ll,ll> &b) {
        auto [la,ra,ca] = a;
        auto [lb,rb,cb] = b;
        if (la != lb) return la < lb;
        return ra > rb;
    });
    ll mxr = -1ll;
    for (auto [l, r, c] : ops) {
        if (mxr == -1) {
            if (l != 0) return void(cout << "-1\n");
            mxr = r;
            continue;
        }
        if (mxr < l) return void(cout << "-1\n");
        mxr = max(mxr,r);
    }
    if (mxr != n-1) return void(cout << "-1\n");
    ll sol = 0ll;
    sort(all(ops),[&](const tuple<ll,ll,ll> &a, const tuple<ll,ll,ll> &b) {
        auto [la,ra,ca] = a;
        auto [lb,rb,cb] = b;
        return ca < cb;
    });
    set<pair<ll,ll>> ints;
    debug(ops);
    for (auto [l, r, c] : ops) {
        debug(endl,ints,l,r,c);
        if (ints.empty()) {
            ints.emplace(l,r);
            sol += (r-l+1ll)*(c);
            continue;
        }
        auto it = ints.lower_bound({l,r});
        ll il = l, ir = r;
        if (it == ints.end()) {
            it = prev(it);
            auto [cl, cr] = *it;
            if (cr >= l) {
                sol += c;
                sol += max(0ll,r-(cr+1ll)+1ll)*c;
                ints.erase(it);
                ir = max(ir,cr);
                il = cl;
            }
            ints.emplace(il,ir);
            continue;
        }
        ll low = l, high = r;
        if (it->first > il && it != ints.begin()) {
            auto p = prev(it);
            auto [pl, pr] = *p;
            if (pr >= l) {
                sol += c;
                low = pr+1ll;
                il = pl;
                ir = max(ir,pr);
                ints.erase(p);
                it = ints.lower_bound({l,r});
            }
        }
        while(low <= high && it != ints.end() && it->first <= high) {
            auto [cl, cr] = *it;
            sol += c;
            high = cl-1ll;
            ints.erase(it);
            il = min(il,cl);
            ir = max(ir,cr);
            it = ints.lower_bound({l,r});
        }
        if (low <= high) sol += (high-low+1ll)*c;
        ints.emplace(il,ir);
    }
    cout << sol << endl;
}