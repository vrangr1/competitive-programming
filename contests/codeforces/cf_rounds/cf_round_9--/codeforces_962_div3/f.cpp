/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jul 26 20:48:44 IST 2024
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

void solve1() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    // if (n == 1ll) {
    //     ll p = a[0]/b[0];
    //     if (p+1ll < k) {
    //         ll sol = ((p+1ll)*(a[0]) - (((p+1ll)*p)/2ll)*b[0]);
    //         a[0]-= (p+1ll)*b[0];
    //         assert(a[0] >= 0ll);
    //         cout << sol+a[0] << endl;
    //         return;
    //     }
    //     ll sol = (k*(a[0]) - (((k-1ll)*k)/2ll)*b[0]);
    //     cout << sol << endl;
    //     return;
    // }
    multiset<pair<ll,ll>> mp;
    rep(i,n)
        mp.insert({a[i],b[i]});
    ll sol = 0ll;
    mp.insert({0,0});
    while(k) {
        auto [ca,cb] = *mp.rbegin();
        if (ca == 0ll) break;
        mp.erase(prev(mp.end()));
        assert(!mp.empty());
        auto [pa,pb] = *mp.rbegin();
        ll low = pa;
        ll p = (ca-low)/cb;
        debug(endl,sol,k,ca,cb,pa,pb,p);
        if (p+1ll < k) {
            sol += ((p+1ll)*ca - (((p+1ll)*p)/2ll)*cb);
            ca -= (p+1ll)*cb;
            k -= p+1ll;
            assert(ca < low);
            ca = max(ca,0ll);
            mp.emplace(ca,cb);
            continue;
        }
        sol += (k*ca - (((k-1ll)*k)/2ll)*cb);
        break;
    }
    cout << sol << endl;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll mx = *max_element(all(a));
    if (k == 1ll) {
        cout << mx << endl;
        return;
    }
    auto comp = [&](ll lbd) -> bool {
        ll ops = 0ll;
        rep(i,n) {
            if (a[i] < lbd) continue;
            ll p = (a[i]-lbd)/b[i];
            ops += p+1ll;
            if (ops > k) return false;
        }
        return true;
    };
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        // debug(endl,low,high);
        if (low == high) {
            assert(low == mx || comp(low));
            return low;
        }
        ll mid = (low+high)/2ll;
        // debug(mid);
        if (comp(mid)) return self(self,low,mid);
        return self(self, mid+1ll, high);
    };
    ll lbd = bsch(bsch, 0, mx);
    ll sol = 0ll, ops = 0ll;
    debug(lbd);
    multiset<pair<ll,ll>> mp;
    bool proc = comp(lbd);
    rep(i,n) {
        if (!proc || a[i] < lbd) {
            mp.emplace(a[i],b[i]);
            continue;
        }
        ll p = (a[i]-lbd)/b[i];
        sol += (a[i]*(p+1ll) - (((p+1ll)*p)/2ll)*b[i]);
        a[i] -= ((p+1ll)*b[i]);
        assert(a[i] < lbd);
        a[i] = max(a[i],0ll);
        ops += (p+1ll);
        mp.emplace(a[i],b[i]);
    }
    k -= ops;
    assert(k>=0ll);
    debug(mp);
    while(k) {
        auto [ca,cb] = *mp.rbegin();
        if (ca <= 0ll) break;
        mp.erase(prev(mp.end()));
        sol += ca;
        ca = max(ca-cb,0ll);
        mp.emplace(ca,cb);
        k--;
    }
    cout << sol << endl;
}