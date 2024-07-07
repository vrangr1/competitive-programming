/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul  7 20:51:53 IST 2024
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
    segtree(const vector<ll> &a) {
        n = sz(a);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
    }

    void update(ll ind) {
        for(tree[ind+=n]++;ind>1;ind>>=1ll)
            tree[ind>>1ll] = tree[ind]+tree[ind^1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if( r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    {
        auto ca = a;
        auto cb = b;
        sort(all(ca));
        sort(all(cb));
        if (ca != cb) return void(cout << no);
    }
    auto get = [n](vector<ll> &vals) {
        vector<ll> order(n);
        iota(all(order),0ll);
        sort(all(order),[&](const ll &i, const ll &j) {
            return vals[i] < vals[j];
        });
        segtree st(order);
        ll sol = 0ll;
        rep(i,n-1ll,0ll,-1ll) {
            sol += st.query(0,order[i]);
            st.update(order[i]);
        }
        return sol;
    };
    ll ia = get(a), ib = get(b);
    debug(ia,ib);
    if (llabs(ia-ib)%2ll) cout << no;
    else cout << yes;
}