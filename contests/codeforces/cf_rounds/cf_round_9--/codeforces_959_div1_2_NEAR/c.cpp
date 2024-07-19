/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 18 20:42:59 IST 2024
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

class segtree {
public:
    ll n;
    vector<ll> tree;
    segtree(ll gn) {
        n = gn;
        gn<<=1ll;
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
    }

    void update(ll ind, ll x) {
        for (tree[ind+=n]=x;ind>1;ind>>=1ll)
            tree[ind>>1ll] = tree[ind]+tree[ind^1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // segtree seg(n);
    reverse(all(a));
    vector<ll> psum(n);
    vector<ll> zeros(n,0ll);
    partial_sum(all(a),psum.begin());
    x++;
    vector<ll> sol(n);
    auto proc = [&](ll i) -> void {
        if (psum[i] < x) {
            sol[i] = i+1ll;
            return;
        }
        auto it = lower_bound(all(psum),psum[i]-x);
        ll j = (ll)(it-psum.begin());
        assert(psum[i]-psum[j] <= x);
        if (psum[i]-psum[j] == x)
            j++;
        // assert(j >= 0ll);
        // assert(j <= i);
        assert(psum[i] - psum[j] < x);
        debug(endl,i,j);
        sol[i] = max(0ll,i-j);
        if (j >= 1) {
            assert(psum[i]-psum[j-1] >= x);
            sol[i] += sol[j-1];
        }
        // if (i) sol[i] += zeros[i-1ll];
        // if (j) sol[i] += sol[j-1ll]-zeros[j-1ll];
        // ll sol = seg.query(j,i) + j-i;
        // zeros[i] = 1ll;
        // if (i) zeros[i] += zeros[i-1ll];
        // if (j) zeros[i] += zeros[j-1ll];
    };
    rep(i,n) {
        proc(i);
    }
    debug(psum,zeros,sol);
    cout << accumulate(all(sol),0ll) << endl;
}