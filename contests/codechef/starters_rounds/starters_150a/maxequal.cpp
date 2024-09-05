/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep  4 20:00:44 IST 2024
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
    map<ll,ll> mp;
    set<pair<ll,ll>> st;
    vector<ll> a(n,0);
    ll z = n, sol = 0ll;
    auto get = [&](ll m) -> ll {
        return ((m-1ll)*m)/2ll;
    };
    rep(i,n) {
        ll x, y; cin >> x >> y;
        --x;
        if (a[x]) {
            st.erase({mp[a[x]],a[x]});
            sol -= get(mp[a[x]]);
            mp[a[x]]--;
            if (mp[a[x]] == 0) mp.erase(a[x]);
            else {
                sol += get(mp[a[x]]);
                st.emplace(mp[a[x]],a[x]);
            }
        }
        else z--;
        a[x] = y;
        if (y){
            if (mp.find(y) != mp.end())
                st.erase({mp[y],y});
            sol -= get(mp[y]);
            mp[y]++;
            sol += get(mp[y]);
            st.emplace(mp[y],y);
        }
        else z++;
        ll mx = 0;
        if (!st.empty()) mx = st.rbegin()->first;
        debug(endl,x,y,z,sol,mp,st,mx);
        cout << sol-get(mx) + get(mx+z) << " \n"[i==n-1];
    }
}