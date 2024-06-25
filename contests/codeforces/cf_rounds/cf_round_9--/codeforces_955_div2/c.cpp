/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jun 25 20:45:25 IST 2024
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
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    vector<vector<ll>> inds(n+1ll);
    vector<ll> psum(n);
    partial_sum(all(a),psum.begin());
    auto get_sum = [&](ll i, ll j) -> ll {
        if (i > j) return 0ll;
        if (!i) return psum[j];
        return psum[j]-psum[i-1];
    };
    ll mx;
    if (a[0] >= l && a[0] <= r) mx = 1;
    else mx = 0;
    inds[0].push_back(-1);
    inds[mx].push_back(0);
    auto bsch = [&](auto &&self, ll low, ll high, const ll cur) -> bool {
        assert(low <= high);
        if (low == high) {
            assert(low < sz(inds[mx]));
            ll sum = get_sum(inds[mx][low]+1ll,cur);
            return sum >= l && sum <= r;
        }
        ll mid = (low+high)/2ll;
        assert(mid < sz(inds[mx]));
        ll sum = get_sum(inds[mx][mid]+1ll,cur);
        if (sum >= l && sum <= r) return true;
        if (sum < l) return self(self, low, mid, cur);
        return self(self, mid+1ll, high, cur);
    };
    debug(a,l,r,mx);
    rep(i,1,n-1ll,1) {
        debug(endl,mx,inds[mx]);
        assert(!inds[mx].empty());
        ll sum = get_sum(inds[mx].back()+1ll,i);
        if (sum >= l && sum <= r) {
            mx++;
            inds[mx].push_back(i);
            continue;
        }
        if (sum > r) {
            inds[mx].push_back(i);
            continue;
        }
        if (bsch(bsch, 0, sz(inds[mx])-1ll, i)) {
            mx++;
        }
        inds[mx].push_back(i);
    }
    debug(inds);
    cout << mx << endl;
}