/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 28 20:47:39 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto get_psum = [&](ll l, ll r) -> ll {
        assert(l >= 0ll && l <= r && r < n);
        if (l == 0) return psum[r];
        return psum[r] - psum[l-1ll];
    };
    vector<ll> tsum(n);
    tsum[0] = psum[0];
    rep(i,1,n-1ll,1)
        tsum[i] = tsum[i-1] + psum[i];
    auto get_tsum = [&](ll stt, ll len) -> ll {
        assert(stt + len-1ll <= n-1ll);
        assert(stt >= 0ll);
        assert(len >= 1ll);
        if (stt == 0ll) return tsum[len-1ll];
        ll sol = tsum[stt+len-1ll] - tsum[stt-1ll];
        sol -= psum[stt-1ll]*len;
        return sol;
    };
    vector<ll> sttsum(n);
    rep(i,n)
        sttsum[i] = get_tsum(i,n-i);
    vector<ll> sttpsum(n);
    partial_sum(all(sttsum),sttpsum.begin());
    auto get_sttrsum = [&](ll l, ll r) -> ll {
        assert(l <= r && l >= 0ll && r <= n-1ll);
        if (l == 0ll) return sttpsum[r];
        return sttpsum[r] - sttpsum[l-1ll];
    };
    auto get_csum = [&](ll l, ll r) -> ll {
        assert(n >= l && l >= r && r >= 1);
        ll sol = (l*(l+1ll))/2ll;
        if (r == 1) return sol;
        sol -= (r*(r-1ll))/2ll;
        return sol;
    };
    auto find_stt = [&](ll ind) -> pair<ll,ll> {
        ll p, q;
        ll low = 0ll, high = n-1ll;
        while(low < high) {
            ll mid = (low+high)/2ll;
            ll cur = n-mid;
            if (ind < get_csum(n,cur)) high = mid;
            else low = mid+1ll;
        }
        p = high;
        q = get_csum(n,n-p);
        if (p != 0) {
            q -= get_csum(n,n-(p-1));
            ind -= get_csum(n,(n-(p-1)));
        }
        assert(ind >= 0 && ind < q);
        q = ind+p;
        assert(q >= p && q < n);
        return {p,q};
    };
    auto get_midsttsum = [&](ll p, ll ql, ll qr) -> ll {
        assert(ql <= qr && qr < n && ql >= p && p >= 0 && p < n);
        if (ql == p) {
            return get_tsum(p,qr-ql+1ll);
        }
        ll sol = get_tsum(ql,qr-ql+1ll);
        sol += get_psum(p,ql-1ll) * (qr-ql+1ll);
        return sol;
    };
    ll q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        --l;--r;
        auto [lp,lq] = find_stt(l);
        auto [rp,rq] = find_stt(r);
        assert(lp < rp || (lp == rp && lq <= rq));
        if (lp == rp) {
            cout << get_midsttsum(lp, lq, rq) << endl;
            continue;
        }
        ll sol = get_midsttsum(lp,lq,n-1ll) + get_midsttsum(rp,rp,rq);
        if (lp != rp - 1ll) sol += get_sttrsum(lp+1ll,rp-1ll);
        cout << sol << endl;
    }
}