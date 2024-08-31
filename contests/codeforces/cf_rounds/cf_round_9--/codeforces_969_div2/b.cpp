/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Aug 30 20:47:12 IST 2024
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
    ll n, m; cin >> n >> m;
    set<ll> st;
    rep(i,n) {
        ll v; cin >> v;
        st.insert(v);
    }
    auto upd = [&]() -> void {
        while(*st.rbegin() - *st.begin() > m) {
            st.erase(st.begin());
        }
    };
    upd();
    while(m--) {
        char op; cin >> op;
        ll d = (op == '+'?1ll:-1ll);
        ll l, r; cin >> l >> r;
        l = max(*st.rbegin()-m,l);
        if (l > r) {
            cout << *st.rbegin() << " \n"[m==0ll];
            continue;
        }
        auto it = st.lower_bound(r);
        if (it == st.end() || *it > r){
            if (it == st.begin()) {
                cout << *st.rbegin() << " \n"[m==0ll];
                upd();
                continue;
            }
            it = prev(it);
        }
        bool dont = false;
        while(true) {
            if (*it < l) break;
            ll v = *it;
            if (!dont)
                st.erase(it);
            auto [it2, ins] = st.insert(v+d);
            it = it2;
            assert(*it == v+d);
            if (!ins && d == -1ll) {
                dont = true;
                continue;
            }
            dont = false;
            if (it == st.begin()) break;
            it = prev(it);
            if (it == st.begin() && *it == v+d) break;
            if (*it == v+1ll) it = prev(it);
        }
        upd();
        cout << *st.rbegin() << " \n"[m==0ll];
    }
}