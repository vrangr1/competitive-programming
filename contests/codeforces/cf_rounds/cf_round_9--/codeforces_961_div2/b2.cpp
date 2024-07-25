/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jul 23 20:16:35 IST 2024
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
    ll n, m; cin >> n >> m;
    vector<ll> b(n), c(n);
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    debug(b,c);
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return b[i] < b[j];
    });
    ll sol = 0ll;
    rep(ind,n-1ll) {
        ll i = order[ind], nxt = order[ind+1];
        if (b[nxt] > b[i]+1ll) {
            sol = max(sol,min((m/b[i]),c[i])*b[i]);
            continue;
        }
        if (b[i]*c[i] + b[nxt]*c[nxt] <= m) {
            sol = max(sol,b[i]*c[i] + b[nxt]*c[nxt]);
            continue;
        }
        ll mx = (m)/b[i], rem = m%b[i];
        if (c[i] >= mx) {
            sol = max(sol,m - (rem - min({rem,c[nxt],mx})));
            // if (mx < rem) {
            //     continue;
            // }
            // sol = max(sol, m - b[i]*(rem - min({rem,c[nxt]})));
            continue;
        }
        ll unc = mx-c[i];
        if (unc > rem) {
            [[maybe_unused]] ll t = unc/b[i];
            if (c[nxt] >= unc) {
                
            }

            continue;
        }
        sol = max(sol,m - (b[i]*(c[i]+min({rem,c[nxt],unc})) - min({rem,c[nxt],unc})));

        // rep(ct,c[i]+1ll) {
        //     if (b[i]*ct > m) break;
        //     ll cur = (m-(b[i]*ct))/b[nxt];
        //     cur = min(cur,c[nxt]);
        //     sol = max(b[i]*ct+cur*b[nxt],sol);
        // }
    }
    sol = max(sol,min((m/b[order.back()]),c[order.back()])*b[order.back()]);
    cout << sol << endl;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> c[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    ll sol = 0ll;
    rep(ind,n) {
        ll i = order[ind];
        sol = max(sol, min(m/a[i],c[i])*a[i]);
        if (ind == n-1) break;
        ll nxt = order[ind+1ll];
        if (a[nxt] != a[i]+1ll) continue;
        ll b = a[i], m1 = m - (min(m/b,c[i])*b);
        ll m2 = m1 - ((b+1ll)*min(m1/(b+1ll),c[nxt]));
        ll cur = m - m2, mn = min({c[nxt] - (m1-m2)/(b+1ll), (m-m1)/b, m2});
        sol = max(sol,cur+mn);
    }
    cout << sol << endl;
}