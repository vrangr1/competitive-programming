/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jun  5 20:43:05 IST 2024
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

void solve1() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), h(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> h[i];
    priority_queue<pair<ll,ll>> pq;
    ll low = LLONG_MAX, high = LLONG_MIN;
    ll sum = 0ll;
    rep(i,n) {
        sum += h[i];
        pq.emplace(h[i],i);
        while(!pq.empty() && sum > a[i]) {
            sum -= pq.top().first;
            low = min(low,a[pq.top().second]);
            high = max(high,a[pq.top().second]);
            pq.pop();
        }
        assert(sum <= a[i]);
    }
    if (low >= high) return void(cout << yes);
    if (high-low+1ll > (2ll*k+1ll)) return void(cout << no);
    cout << yes;
}


class segtree {
public:
    ll n;
    vector<ll> tree;
    segtree(const vector<ll> &a, const vector<ll> &h) {
        n = sz(a);
        ll gn = n<<1ll;
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
        rep(i,n)
            if (i)
                tree[i+n] = h[i]+tree[i+n-1ll];
            else tree[i+n] = h[i];
        rep(i,n) tree[i+n] -= a[i];
        rep(i,n-1ll,1ll,-1ll)
            tree[i] = max(tree[i<<1ll],tree[i<<1ll|1ll]);
    }

    void update(ll ind, ll v) {
        ind+=n;
        for(tree[ind]+=v;ind > 1ll; ind>>=1ll)
            tree[ind>>1ll] = max(tree[ind],tree[ind^1ll]);
    }

    ll query(ll l, ll r) {
        ll res = LLONG_MIN;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res = max(res,tree[l++]);
            if (r&1ll) res = max(res,tree[--r]);
        }
        return res;
    }
};

void solve2() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), h(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> h[i];
    segtree st(a,h);
    debug(st.query(0,n));
    ll l = 0ll;
    const ll mx = (2ll*k)+1ll;
    rep(i,n) {
        st.update(i,0);
        while (a[i]-a[l]+1ll > mx) {
            assert(l <= i);
            st.update(l,h[l]);
            l++;
        }
        if (i != n-1ll) {
            if (st.query(0,n) <= a[n-1ll]) {
                debug(l,i);
                return void(cout << yes);
            }
            continue;
        }
        assert(l <= n);
        if (st.query(0,l) <= a[l-1ll]){
            debug(l,i);
            return void(cout << yes);
        }
    }
    cout << no;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), h(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> h[i];
    vector<ll> left(n), right(n);
    vector<ll> psum(n);
    partial_sum(all(h),psum.begin());
    left[0] = LLONG_MIN;
    rep(i,1,n-1,1)
        left[i] = max(left[i-1],psum[i-1]-a[i-1]);
    right.back() = LLONG_MIN;
    rep(i,n-2ll,0ll,-1ll)
        right[i] = max(right[i+1],psum[i+1]-a[i+1]);
    ll l = 0ll, sum = 0ll, dist = 2ll*k+1ll;
    debug(left,right);
    rep(i,n) {
        sum += h[i];
        while(a[i]-a[l]+1ll > dist) {
            assert(l < i);
            sum -= h[l++];
        }
        assert(l <= i);
        debug(i,l,sum);
        if (left[l] > 0ll) break;
        if (right[i]-sum > 0) continue;
        cout << yes;
        return;
    }
    cout << no;
}