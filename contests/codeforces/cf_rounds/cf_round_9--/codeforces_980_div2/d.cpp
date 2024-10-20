/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct 20 15:44:04 IST 2024
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
    vector<ll> tree;
    segtree(vector<ll> &a) {
        n = sz(a);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1ll,-1)
            tree[i] = tree[i<<1ll] + tree[i<<1ll|1ll];
    }

    void update(ll ind) {
        for (tree[ind+=n]=0ll; ind > 1ll; ind>>=1ll)
            tree[ind>>1ll] = tree[ind] + tree[ind^1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for(l+=n,r+=n; l < r; l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

class seg2 {
public:
    ll n; 
    vector<ll> tree;
    seg2(vector<ll> &a) {
        n = sz(a);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,LLONG_MIN);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1ll,-1)
            tree[i] = max(tree[i<<1ll], tree[i<<1ll|1ll]);
    }

    void update(ll ind) {
        for (tree[ind+=n]=0ll; ind > 1ll; ind>>=1ll)
            tree[ind>>1ll] = max(tree[ind],tree[ind^1ll]);
    }

    ll query(ll l, ll r) {
        ll res = LLONG_MIN;
        for(l+=n,r+=n; l < r; l>>=1ll,r>>=1ll) {
            if (l&1ll) res = min(res,tree[l++]);
            if (r&1ll) res = min(tree[--r],res);
        }
        return res;
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        cin >> b[i];
        --b[i];
    }
    // segtree sum(a);
    // seg2 mnind(b);
    // ll ind = 0ll, sol = 0ll;
    vector<ll> cost(n,LLONG_MAX);
    cost[0] = 0;
    multiset<pair<ll,ll>> costs, inds;
    costs.emplace(a[0],b[0]);
    inds.emplace(b[0],a[0]);
    rep(i,1,n-1,1) {
        while(!inds.empty() && inds.begin()->first < i) {
            auto [ind,c] = *inds.begin();
            inds.erase(inds.begin());
            costs.erase(costs.find({c,ind}));
        }
        if (costs.empty()) break;
        ll cur = costs.begin()->first;
        cost[i] = cur;
        costs.emplace(cur+a[i],b[i]);
        inds.emplace(b[i],cur+a[i]);
    }
    ll sol = a[0], sum = 0ll;
    rep(i,n) {
        if (cost[i] == LLONG_MAX) break;
        sum += a[i];
        sol = max(sol, sum - cost[i]);
    }
    cout << sol << endl;
}