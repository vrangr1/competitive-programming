/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 21:37:49 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> vals;
    rep(i,n) {
        ll l; cin >> l;
        set<ll> st;
        ll mex = 0ll;
        rep(j,l) {
            ll v; cin >> v;
            st.insert(v);
            while(st.find(mex) != st.end())
                mex++;
        }
        ll v1 = mex;
        st.insert(v1);
        while(st.find(mex) != st.end())
            mex++;
        vals.emplace_back(v1,mex);
    }
    ll sol = 0ll;
    map<ll,ll> mp;
    map<pair<ll,ll>,ll> vct;
    ll mxval = -1ll;
    rep(i,n-1,0ll,-1ll) {
        auto [m1,m2] = vals[i];
        vct[vals[i]]++;
        if (vct[vals[i]] > 1) mxval = max(mxval,m2);
        if (mp.find(m2) != mp.end()) mp[m1] = max(mp[m2],mp[m1]);
        else mp[m1] = m2;
    }
    rep(i,n-1,0ll,-1ll) {
        auto [m1,m2] = vals[i];
        mp[m1] = max({mp[m1],mxval,mp[mxval]});
    }
    rep(c,m+1ll) {
        vector<bool> vis(n,false);
        // ll x = c;
        // if (x <= mxval) {
        //     sol += max({c,mxval,mp[mxval]});
        //     continue;
        // }
        sol += max({c,mxval,mp[mxval]});
    }
    cout << sol << endl;
}