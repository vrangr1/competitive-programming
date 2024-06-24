/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 23 20:23:40 IST 2024
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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    auto comp = [&](const array<int,3> &i, const array<int,3> &j) -> bool {
        if (i[0] != j[0]) return i[0] > j[0];
        if (i[1] != j[1]) return i[1] < j[1];
        return i[2] < j[2];
    };
    set<array<int,3>, decltype(comp)> st(comp);
    rep(i,n) rep(j,m) st.insert({a[i][j],i,j});
    auto valid = [&](int i, int j) -> bool {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    auto get = [&](int i, int j) -> int {
        int mx = INT_MIN;
        if (valid(i-1,j)) mx = max(mx,a[i-1][j]);
        if (valid(i+1,j)) mx = max(mx,a[i+1][j]);
        if (valid(i,j-1)) mx = max(mx,a[i][j-1]);
        if (valid(i,j+1)) mx = max(mx,a[i][j+1]);
        assert(mx != INT_MIN);
        return mx;
    };
    while(!st.empty()) {
        auto [val, i, j] = *st.begin();
        int mx = get(i,j);
        st.erase(st.begin());
        if (val <= mx) continue;
        a[i][j] = mx;
        st.insert({a[i][j],i,j});
    }
    rep(i,n) print_vec(a[i]);
}