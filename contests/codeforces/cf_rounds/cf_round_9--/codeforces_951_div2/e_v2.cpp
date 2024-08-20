/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 20 17:37:45 IST 2024
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
    vector<pair<ll,ll>> pts;
    map<ll,vector<pair<ll,ll>>> xmy, xpy;
    rep(i,n) {
        ll x, y; cin >> x >> y;
        pts.emplace_back(x,y);
        xmy[x-y].emplace_back(x+y,i);
        xpy[x+y].emplace_back(x-y,i);
    }
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return pts[i] < pts[j];
    });
    for (auto &[k,v] : xmy) sort(all(v));
    for (auto &[k,v] : xpy) sort(all(v));
    auto ans = [](ll i, ll j, ll k) -> void {
        cout << i+1 << " " << j+1 << " " << k+1 << endl;
    };
    auto find = [&](ll k, ll low, ll high, bool plus = true) -> ll {
        auto &vec = (plus?xpy[k]:xmy[k]);
        auto it = lower_bound(all(vec),make_pair(low,-1ll));
        if (it == vec.end() || it->first > high) return -1;
        return it->second;
    };
    auto valid = [&](ll i1, ll i2) -> bool {
        auto [x1, y1] = pts[i1];
        auto [x2, y2] = pts[i2];
        if (x1 - y1 == x2 - y2) {
            ll low = min(x1+y1,x2+y2), high = max(x1+y1,x2+y2);
            ll i3 = find(x1-y1-d,low,high,false);
            if (i3 != -1) {
                ans(i1,i2,i3);
                return true;
            }
            i3 = find(x1-y1+d,low,high,false);
            if (i3 != -1) {
                ans(i1,i2,i3);
                return true;
            }
            return false;
        }
        ll low = min(x1-y1,x2-y2), high = max(x1-y1,x2-y2);
        ll i3 = find(x1+y1+d,low,high);
        if (i3 != -1) {
            ans(i1,i2,i3);
            return true;
        }
        i3 = find(x1+y1-d,low,high);
        if (i3 != -1) {
            ans(i1,i2,i3);
            return true;
        }
        return false;
    };
    auto index = [&](pair<ll,ll> pt) -> ll {
        ll low = 0, high = n-1ll;
        while (low < high) {
            ll mid = (low+high+1ll)/2ll;
            if (pts[order[mid]] == pt) return order[mid];
            if (pt > pts[order[mid]]) low = mid;
            else high = mid-1;
        }
        if (pts[order[low]] == pt) return order[low];
        return -1;
    };
    rep(i,n) {
        auto [x,y] = pts[i];
        ll j = index({x+d/2,y+d/2});
        if (j != -1 && valid(i,j)) return;
        j = index({x-d/2,y-d/2});
        if (j != -1 && valid(i,j)) return;
        j = index({x+d/2,y-d/2});
        if (j != -1 && valid(i,j)) return;
        j = index({x-d/2,y+d/2});
        if (j != -1 && valid(i,j)) return;
    }
    cout << "0 0 0\n";
}