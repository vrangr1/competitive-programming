/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 01:39:30 IST 2024
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
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
    vector<ll> tree;
    segtree(ll gn) {
        n = gn;
        gn<<=1ll;
        if (__builtin_popcountll(gn) != 1ll)
            gn = 1ll<<(64ll-__builtin_clzll(gn));
        tree.assign(gn,0);
    }

    void clear() {
        fill(all(tree),0ll);
    }

    void update(ll ind, ll x) {
        for(tree[ind+=n]=x; ind > 1; ind>>=1ll)
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

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    rep(i,n) a[order[i]] = i;
    segtree st(n);
    vector<ll> ct(n,0ll);
    rep(i,n-1ll,0ll,-1) {
        ct[i] = st.query(0,a[i]);
        st.update(a[i],1ll);
    }
    st.clear();
    ll sol = 0ll;
    rep(i,n-1ll,0ll,-1ll) {
        sol += st.query(0,a[i]);
        st.update(a[i],ct[i]);
    }
    cout << sol << endl;
}