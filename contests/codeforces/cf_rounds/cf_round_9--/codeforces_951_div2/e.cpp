/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jun  6 21:38:15 IST 2024
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
    ll n, d; cin >> n >> d;
    vector<pair<ll,ll>> pts(n);
    rep(i,n) cin >> pts[i].first >> pts[i].second;
    map<ll,set<vector<ll>>> plus,minus;
    rep(i,n) {
        plus[pts[i].first+pts[i].second].insert({pts[i].first,pts[i].second,i+1});
        minus[pts[i].first-pts[i].second].insert({pts[i].first,pts[i].second,i+1});
    }
    auto get = [](ll val, ll x1, ll x2, map<ll,set<vector<ll>>> &mp) -> vector<ll> {
        if (mp.find(val) == mp.end() || mp[val].empty()) return {};
        auto &cur = mp[val];
        auto it = cur.lower_bound({x1,LLONG_MIN,LLONG_MIN});
        if (it == cur.end() || it == prev(cur.end())) return {};
        auto nxt = next(it);
        assert(nxt != cur.end());
        assert(it->at(0) >= x1 && nxt->at(0) >= x1);
        if (it->at(0) > x2 || nxt->at(0) > x2) return {};
        return {it->at(2),nxt->at(2)};
    };
    rep(i,n) {
        auto [x, y] = pts[i];
        plus[x+y].erase({x,y,i+1});
        minus[x-y].erase({x,y,i+1});
        vector<ll> pos = get(x+y+d,x,x+d,plus);
        if (sz(pos) == 2) {
            cout << i+1 << " ";
            print_vec(pos);
            return;
        }
        pos = get(x+y-d,x-d,x,plus);
        if (sz(pos) == 2) {
            cout << i+1 << " ";
            print_vec(pos);
            return;
        }
        pos = get(x-y+d,x,x+d,minus);
        if (sz(pos) == 2) {
            cout << i+1 << " ";
            print_vec(pos);
            return;
        }
        pos = get(x-y-d,x-d,x,minus);
        if (sz(pos) == 2) {
            cout << i+1 << " ";
            print_vec(pos);
            return;
        }
        plus[x+y].insert({x,y,i+1});
        minus[x-y].insert({x,y,i+1});
    }
    cout << "0 0 0\n";
}