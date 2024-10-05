/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct  5 17:59:22 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n, x; cin >> n >> x;
    vector<array<ll,4>> ps(n);
    for (auto &[a,p,b,q] : ps)
        cin >> a >> p >> b >> q;
    auto comp = [&](ll a, ll p, ll b, ll q, ll w, ll act) -> ll {
        if (act*a >= w) return act*p;
        return act*p + ((w-(act*a)+b-1ll)/b)*q;
    };
    auto bsch = [&](ll a, ll p, ll b, ll q, ll w) -> ll {
        ll low = 0ll, high = (w+a-1ll)/a;
        while (low < high) {
            if (low == high-1ll) {
                return min(comp(a,p,b,q,w,low), comp(a,p,b,q,w,high));
            }
            ll mid = (low+high)/2ll, cmid = comp(a,p,b,q,w,mid);
            ll prev = mid-1ll, nxt = mid+1ll, cp = comp(a,p,b,q,w,prev), cn = comp(a,p,b,q,w,nxt);
            if (cp >= cmid && cn >= cmid) return cmid;
            if (!((cp >= cmid && cmid >= cn) || (cp <= cmid && cmid <= cn))) {
                debug(a,p,b,q,w,low,high,mid,prev,nxt,cmid,cp,cn);
                exit(0);
            }
            assert((cp >= cmid && cmid >= cn) || (cp <= cmid && cmid <= cn));
            if (cp >= cmid && cmid >= cn) {
                assert(nxt <= high);
                assert(nxt > low);
                low = nxt;
                continue;
            }
            assert(prev < high);
            assert(low <= prev);
            high = prev;
        }
        return comp(a,p,b,q,w,low);
    };
    auto pos = [&](ll w) -> bool {
        ll cost = 0ll;
        for (auto &[a,p,b,q] : ps) {
            ll cur = bsch(a,p,b,q,w);
            // ll cur = min({((w+a-1ll)/a)*p, ((w+b-1ll)/b)*q, (w/a)*p + ((w%a + b-1ll)/b)*q,(w/b)*q + ((w%b + a-1ll)/a)*p});
            if (w/a) cur = min(cur, ((w/a)-1ll)*p + ((w%a + a + b-1ll)/b)*q);
            if (w/b) cur = min(cur, ((w/b)-1ll)*q + ((w%b + b + a-1ll)/a)*p);
            cost += cur;
        }
        return cost <= x;
    };
    ll low = 0ll, high = INT_MAX;
    while (low < high) {
        ll mid = (low + high + 1ll)/2ll;
        if (pos(mid)) low = mid;
        else high = mid-1ll;
    }
    cout << low << endl;
}