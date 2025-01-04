/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Jan  4 21:01:01 IST 2025
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

class segtree {
public:
    ll n;
    vector<array<ll,3>> tree;
    segtree(const vector<ll> &a) {
        n = sz(a);
        assert(__builtin_popcountll(n) == 1ll);
        ll gn = (n<<1ll);
        tree.assign(gn,{LLONG_MIN,INT_MIN,INT_MAX});
        rep(i,n)
            tree[i+n] = {0ll,a[i],a[i]};
        rep(i,n-1,1ll,-1) {
            auto [ldiff, lmx, lmn] = tree[i<<1ll];
            auto [rdiff, rmx, rmn] = tree[i<<1ll|1ll];
            ll diff = max({ldiff, rdiff, rmx-lmn});
            tree[i] = {diff,max(lmx,rmx),min(rmn,lmn)};
        }
    }

    void update(ll ind, ll x) {
        ind += n;
        tree[ind] = {0ll,x,x};
        while(ind>1) {
            ll p = (ind>>1ll);
            ll l = ind, r = (ind^1ll);
            if (l > r) swap(l,r);
            auto [ldiff, lmx, lmn] = tree[l];
            auto [rdiff, rmx, rmn] = tree[r];
            tree[p] = {max({ldiff,rdiff,rmx-lmn}), max(lmx,rmx), min(rmn,lmn)};
            ind>>=1ll;
        }
    }

    ll get() {
        return tree[1][0];
    }

    void dbg() {
        debug(tree);
    }
};

void solve() {
    ll n, q; cin >> n >> q;
    ll og = n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> fd = a, bk = a;
    reverse(all(bk));
    while(__builtin_popcountll(n) != 1) {
        fd.push_back(INT_MIN);
        bk.push_back(INT_MIN);
        ++n;
    }
    rep(i,n) {
        fd[i] -= i;
        bk[i] -= i;
    }
    segtree s1(fd), s2(bk);
    debug(n,og);
    cout << max(s1.get(), s2.get()) << endl;
    s1.dbg();
    s2.dbg();
    while(q--) {
        ll p, x; cin >> p >> x;
        --p;
        s1.update(p,x-p);
        s2.update(og-p-1,x-(og-p-1));
        debug(endl,p,x,s1.get(),s2.get());
        s1.dbg();
        s2.dbg();
        cout << max(s1.get(),s2.get()) << endl;
    }
}