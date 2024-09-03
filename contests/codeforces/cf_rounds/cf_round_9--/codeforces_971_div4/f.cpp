/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep  3 20:54:57 IST 2024
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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto get = [&](ll l, ll r) -> ll {
        assert(l >= 0ll && l < n);
        assert(r >= 0ll && r < n);
        if (l <= r) return psum[r]-(l?psum[l-1ll]:0ll);
        return psum.back()-psum[l-1ll]+psum[r];
    };
    auto get2 = [&](ll ind, ll r, bool left = true) -> ll {
        ll stt = r, cur = (ind+r)%n;
        if (left) return get(stt,cur);
        else return psum.back()-get(stt,cur)+a[cur];
    };
    while(q--) {
        ll l, r; cin >> l >> r;
        --l;--r;
        ll li = l/n, ri = r/n;
        assert(li <= ri);
        ll ct = max(0ll,ri-li-1ll);
        debug(endl,l,r,li,ri,ct,l%n,r%n);
        ll sol = ct*psum.back();
        if (li == ri) {
            sol += get((l%n+li)%n,(r%n+li)%n);
            cout << sol << endl;
            continue;
        }
        sol += get2(l%n,li,false);
        sol += get2(r%n,ri);
        cout << sol << endl;
    }
}