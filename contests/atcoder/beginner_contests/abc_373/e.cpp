/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 28 17:50:51 IST 2024
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
    ll n, m, k; cin >> n >> m >> k;
    ll sum = 0ll;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    k = k-sum;
    vector<ll> b = a, order(n), abind(n), psum(n);
    sort(all(b));
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    rep(i,n)
        abind[order[i]] = i;
    partial_sum(all(b),psum.begin());
    auto getsum = [&](ll i, ll j, ll ind = -1) -> ll {
        if (ind != -1ll) ind = abind[ind];
        if (ind < i || ind > j)
            return psum[j] - (i?psum[i-1]:0ll);
        if (i > 1ll) return psum[j] - psum[i-2ll] - b[ind];
        return psum[j] - b[ind];
    };
    auto valid = [&](ll ind, ll x) -> bool {
        ll v = a[ind] + x;
        auto it = lower_bound(all(b),v+1ll);
        ll bind = ll(it-b.begin()), ct = n-bind, rem = m-ct;
        if (ct >= m) return false;
        if (bind < rem+1ll) return true;
        ll csum = getsum(bind-rem,bind-1ll,ind);
        csum = (v+1ll)*rem - csum;
        return csum > k-x;
    };
    rep(i,n) {
        if (!valid(i,k)) {
            cout << "-1" << " \n"[i==n-1ll];
            continue;
        }
        ll low = 0ll, high = k;
        while(low < high) {
            ll mid = (low+high)/2ll;
            if (valid(i,mid)) high = mid;
            else low = mid+1ll;
        }
        cout << high << " \n"[i==n-1ll];
    }
}