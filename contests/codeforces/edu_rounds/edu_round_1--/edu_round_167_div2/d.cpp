/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jun 27 21:47:33 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class segtree {
public:
    ll n;
    vector<ll> tree, a, b;
    segtree(const vector<ll> &ga, const vector<ll> &gb, const vector<ll> &ord) {
        n = sz(ga);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll) {
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        }
        tree.assign(gn,INT_MAX);
        a.resize(gn);
        b.resize(gn);
        rep(i,n) {
            tree[i+n] = ga[ord[i]] - gb[ord[i]];
            a[i+n] = ga[ord[i]];
            b[i+n] = gb[ord[i]];
        }
        rep(i,n-1ll,1ll,-1ll) {
            if (tree[i<<1ll] <= tree[i<<1ll|1ll]) {
                tree[i] = tree[i<<1ll];
                a[i] = a[i<<1ll];
                b[i] = b[i<<1ll];
            }
            else {
                tree[i] = tree[i<<1ll|1ll];
                a[i] = a[i<<1ll|1ll];
                b[i] = b[i<<1ll|1ll];
            }
        }
    }

    tuple<ll,ll,ll> query(ll l, ll r) {
        tuple<ll,ll,ll> res = {INT_MAX,INT_MAX,-1};
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                if (get<0>(res) > tree[l]) {
                    res = {tree[l],a[l],b[l]};
                }
                else if (get<0>(res) == tree[l] && get<1>(res) > a[l]) {
                    res = {tree[l],a[l],b[l]};
                }
                ++l;
            }
            if (r&1ll) {
                --r;
                if (get<0>(res) > tree[r]) {
                    res = {tree[r],a[r],b[r]};
                }
                else if (get<0>(res) == tree[r] && get<1>(res) > a[r]) {
                    res = {tree[r],a[r],b[r]};
                }
            }
        }
        return res;
    }
};

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n), c(m);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(rall(c));
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] > a[j];
    });
    segtree st(a, b, order);
    vector<ll> orda = a;
    sort(all(orda));
    auto get_ind = [&](ll lim) -> ll {
        auto it = upper_bound(all(orda),lim);
        if (it == orda.begin()) return n;
        it = prev(it);
        assert(*it <= lim);
        return n - (ll)(it-orda.begin()) - 2ll;
    };
    auto proc = [&](ll val) -> ll {
        ll lim = val;
        ll ind = get_ind(lim), sol = 0;
        while(ind != n) {
            auto [diff, ga, gb] = st.query(ind, n);
            assert(ga <= val);
            
        }
    };
    ll sol = 0ll;
    for (ll val : c) {

    }
}