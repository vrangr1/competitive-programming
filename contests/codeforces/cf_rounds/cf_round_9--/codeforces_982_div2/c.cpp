/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 20:38:09 IST 2024
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
    vector<ll> a(n);
    map<ll,vector<ll>> mp;
    rep(i,n) {
        cin >> a[i];
        if (i == 0) continue;
        mp[a[i]+i].push_back(i);
    }
    if (mp.find(n) == mp.end()) return void(cout << n << endl);
    ll sol = n;
    set<ll> st;
    for (ll v : mp[n]) {
        st.insert(n+v);
        sol = max(sol,n+v);
    }
    set<ll> vis;
    vis.insert(n);
    while(!st.empty()) {
        if (vis.find(*st.begin()) != vis.end()) {
            st.erase(st.begin());
            continue;
        }
        ll m = *st.begin();
        vis.insert(m);
        for (ll v : mp[m]) {
            if (vis.find(m+v) != vis.end()) continue;
            st.insert(v+m);
            sol = max(v+m,sol);
        }
    }
    cout << sol << endl;
}