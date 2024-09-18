/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 18 20:10:28 IST 2024
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> psum(n,vector<int>(3,0));
    psum[0][a[0]-1]++;
    rep(i,1,n-1,1) {
        psum[i] = psum[i-1];
        psum[i][a[i]-1]++;
    }
    auto get = [&](int l, int r) -> vector<int> {
        assert(l <= r);
        auto sol = psum[r];
        if (!l) return sol;
        rep(i,3) sol[i]-=psum[l-1][i];
        return sol;
    };
    while(q--) {
        int l, r; cin >> l >> r;
        --l;--r;
        int m = r-l+1;
        if (m%2) {
            cout << "No\n";
            continue;
        }
        auto ct = get(l,r);
        sort(all(ct));
        if (ct.back() != m/2) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}