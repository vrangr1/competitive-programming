/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 17:38:47 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> lr(n);
    for (auto &[l,r] : lr)
        cin >> l >> r;
    sort(all(lr));
    // lr.emplace_back(lr.back().first,m+1ll);
    multiset<ll> st;
    for (auto [l,r] : lr)
        st.insert(r);
    ll sol = 0ll;
    ll last = 1ll;
    auto get = [](ll k) -> ll {
        if (k < 0ll) return 0ll;
        return (k*(k+1ll))/2ll;
    };
    debug(lr,st);
    rep(i,n) {
        auto [l,r] = lr[i];
        debug(endl,l,r,st);
        assert(!st.empty());
        ll lmn = last, lmx = l;
        if (lmx < lmn) {
            last = l+1ll;
            st.erase(st.find(r));
            continue;
        }
        ll rmx = *st.begin()-1ll;
        lmx = min(rmx,lmx);
        if (lmx < lmn) {
            last = l+1ll;
            st.erase(st.find(r));
            continue;
        }
        debug(lmn,lmx,rmx,(get(rmx-lmn+1ll) - get(rmx-lmx)));
        sol += get(rmx-lmn+1ll) - get(rmx-lmx);
        last = l+1ll;
        st.erase(st.find(r));
    }
    if (last <= m) sol += get(m-last+1ll);
    cout << sol << endl;
}