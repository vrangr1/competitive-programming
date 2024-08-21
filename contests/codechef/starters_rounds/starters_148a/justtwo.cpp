/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 21 20:11:12 IST 2024
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

const ll mod = ll(1e9) + 7ll;

void solve() {
    ll n, k; cin >> n >> k;
    auto comp = [&](const pair<ll,ll> &a, const pair<ll,ll> &b) -> bool {
        auto [av, ap] = a;
        auto [bv, bp] = b;
        if (ap == bp) return av > bv;
        if (ap > bp) {
            ll p = ap-bp;
            assert(p <= 32);
            return (av*(1ll<<p)) > bv;
        }
        ll p = bp-ap;
        assert(p <= 32);
        return av > (bv*(1ll<<p));
    };
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, decltype(comp)> pq(comp);
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        pq.emplace(a[i],0ll);
    }
    auto inc = [&](ll r) {
        if (r == 0) return;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, decltype(comp)> temp(comp);
        while(!pq.empty()) {
            auto [v, p] = pq.top();
            pq.pop();
            p+=r;
            temp.emplace(v,p);
        }
        while(!temp.empty()) {
            pq.push(temp.top());
            temp.pop();
        }
    };
    ll sol = 0ll;
    ll ct = n;
    bool done = false;
    while(k--) {
        auto [v, p] = pq.top();
        pq.pop();
        p++;
        if (p == 1ll) ct--;
        pq.emplace(v,p);
        if (!ct && !done) {
            done = true;
            ll r = k/n;
            k%=n;
            inc(r);
        }
    }
    auto pwr = [](auto &&self, ll v, ll p) -> ll {
        if (p == 0ll) return 1ll;
        ll v2 = (v*v)%mod;
        if (p%2ll) return (v*self(self,v2,p/2ll))%mod;
        return self(self,v2,p/2ll);
    };
    while(!pq.empty()) {
        auto [v, p] = pq.top();
        pq.pop();
        sol += (v*pwr(pwr,2ll,p))%mod;
        sol%=mod;
    }
    cout << sol << endl;
}