/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 21 22:21:00 IST 2024
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
    segtree(const vector<ll> &vals) {
        n = sz(vals);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
        rep(i,n)
            tree[i+n] = vals[i];
        rep(i,n-1,1ll,-1ll)
            tree[i] = tree[i<<1ll]+tree[i<<1ll|1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }

    void update(ll ind, ll x) {
        for(tree[ind+=n]=x;ind>1;ind>>=1ll)
            tree[ind>>1ll] = tree[ind]+tree[ind^1ll];
    }
};

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> diff(n);
    rep(i,n) diff[i] = b[i]-a[i];
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return diff[i] < diff[j];
    });
    vector<pair<ll,ll>> range(n);
    rep(i,n) {
        ll l = (i-k+n)%n, r = (i+k)%n;
        range[i] = {l,r};
    }
    segtree seg(a);
    auto get_sum = [&](ll l, ll r) -> ll {
        if (l < r) return seg.query(l,r+1ll);
        return seg.query(r,n) + seg.query(0,l+1ll);
    };
    ll sol = 0ll;
    rep(i,n) {
        ll ind = order[i];
        debug(endl,ind,diff[ind]);
        if (!diff[ind]) continue;
        if (diff[ind] < 0ll) return void(cout << "-1\n");
        auto [l,r] = range[ind];
        ll sum = get_sum(l,r);
        debug(sum);
        if (diff[ind]%sum) return void(cout << "-1\n");
        a[i] = b[i];
        sol++;
        seg.update(i,a[i]);
    }
    cout << sol << endl;
}