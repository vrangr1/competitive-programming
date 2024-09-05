/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep  4 21:50:06 IST 2024
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
    auto create = [&](ll l, ll r) -> vector<ll> {
        vector<ll> b = {0ll};
        ll last = a[l], dir = -1;
        rep(i,l+1ll,r,1) {
            if (a[i] == last) continue;
            if (dir == -1) {
                dir = (a[i] > last);
                b.back()+=llabs(last-a[i]);
                last = a[i];
                continue;
            }
            if (dir == (a[i]>last)) {
                b.back() += llabs(last-a[i]);
                last = a[i];
                continue;
            }
            b.push_back(llabs(last-a[i]));
            dir = (a[i]>last);
            last = a[i];
        }
        return b;
    };
    while(q--) {
        ll l, r, k; cin >> l >> r >> k;
        --l;--r;
        auto b = create(l,r);
        ll sum = accumulate(all(b),0ll), mx = *max_element(all(b));
        debug(sum,mx);
        if (sum <= k) {
            cout << "0\n";
            continue;
        }
        if (mx <= sum-mx || mx-(sum-mx) <= k) {
            cout << (sum-k+1ll)/2ll << endl;
            continue;
        }
        ll sol = sum-mx;
        sum-=2ll*sol;
        assert(sum > k);
        sol += sum-k;
        cout << sol << endl;
    }
}