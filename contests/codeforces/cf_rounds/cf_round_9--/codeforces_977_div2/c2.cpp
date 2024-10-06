/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct  6 12:01:48 IST 2024
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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<set<int>> inds(n+1);
    vector<int> p(n+1);
    rep(i,n) p[a[i]] = i;
    rep(i,m)
        inds[b[i]].insert(i);
    rep(i,1,n,1) inds[i].insert(m);
    int ct = 0;
    rep(i,n-1)
        ct += (*inds[a[i]].begin() > *inds[a[i+1]].begin());
    auto ans = [&]() -> void {
        cout << (ct ? "TIDAK\n":"YA\n");
    };
    auto upd = [&](int i, int c = 1) -> void {
        if (i) ct += c*(*inds[a[i-1]].begin() > *inds[a[i]].begin());
        if (i != n-1) ct += c*(*inds[a[i]].begin() > *inds[a[i+1]].begin());
    };
    auto rem = [&](int v1, int v2) -> void {
        int i1 = p[v1], i2 = p[v2];
        if (i1 == i2) {
            upd(i1,-1);
            return;
        }
        if (i1 > i2) swap(i1,i2);
        if (i2-i1 > 1) {
            upd(i1,-1);
            upd(i2,-1);
        } else {
            upd(i1,-1);
            if (i2 != n-1)
                ct -= (*inds[a[i2]].begin() > *inds[a[i2+1]].begin());
        }
    };
    auto add = [&](int v1, int v2) -> void {
        int i1 = p[v1], i2 = p[v2];
        if (i1 == i2) {
            return upd(i1);
        }
        if (i1 > i2) swap(i1,i2);
        if (i2-i1 > 1) {
            upd(i1);
            upd(i2);
        } else {
            upd(i1);
            if (i2 != n-1)
                ct += (*inds[a[i2]].begin() > *inds[a[i2+1]].begin());
        }
    };
    ans();
    while(q--) {
        int s, t; cin >> s >> t;
        --s;
        int temp = b[s];
        rem(temp,t);
        inds[b[s]].erase(s);
        b[s] = t;
        inds[b[s]].insert(s);
        add(temp,t);
        ans();
    }
}