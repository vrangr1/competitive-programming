/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Aug 12 20:13:43 IST 2024
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
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    priority_queue<pair<ll,ll>> pq;
    rep(i,n) if (c[i] > 0) pq.emplace(c[i],i);
    ll sol = 0ll, d = a-b;
    vector<ll> cts(n,0);
    auto get = [&](ll ind) -> ll {
        return c[ind] - cts[ind]*a - (sol-cts[ind])*b;
    };
    debug(pq);
    // ll ict = 0ll;
    while (!pq.empty()) {
        debug(pq);
        // ict++;
        // if (ict > 20) break;
        auto [val, ind] = pq.top();
        pq.pop();
        if (get(ind) <= 0ll) break;
        if (pq.empty()) {
            sol += (get(ind) + a-1ll)/a;
            break;
        }
        auto [nxt, nind] = pq.top();
        if (get(nind) <= 0ll) {
            sol += (get(ind) + a-1ll)/a;
            break;
        }
        ll ops = max((val-nxt + d-1ll)/d,1ll);
        assert(ops > 0ll);
        val -= ops*d;
        cts[ind] += ops;
        sol += ops;
        if (get(ind) > 0ll)
            pq.emplace(val,ind);
    }
    cout << sol << endl;
}

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    ll d = a-b;
    auto pos = [&](ll bd) -> ll {
        ll ops = 0;
        rep(i,n)
            if (c[i] <= bd) continue;
            else ops += (c[i]-bd+d-1ll)/d;
        rep(i,n)
            if (c[i] <= bd) {
                if (c[i]-ops*b > 0ll) return false;
                continue;
            }
            else {
                ll cur = (c[i]-bd+d-1ll)/d;
                if (c[i]-cur*a-(ops-cur)*b > 0ll) return false;
            }
        return true;
    };
    ll bd;
    {
        ll low = 0ll, high = *max_element(all(c));
        while(low < high) {
            ll mid = (low+high+1ll)/2ll;
            if (pos(mid)) low = mid;
            else high = mid-1ll;
        }
        bd = low;
    }
    ll ops = 0ll;
    rep(i,n)
        if (c[i] <= bd) continue;
        else ops += (c[i]-bd+d-1ll)/d;
    ll low = 0ll, high = ops;
    auto pos2 = [&](ll ct) -> bool {
        ll r = b*ct;
        ll req = 0ll;
        rep(i,n) {
            if (c[i]-r <= 0ll) continue;
            req += (c[i]-r+d-1ll)/d;
        }
        return req <= ct;
    };
    while (low < high) {
        ll mid = (low+high)/2ll;
        if (pos2(mid)) high = mid;
        else low = mid+1ll;
    }
    cout << high << endl;
}