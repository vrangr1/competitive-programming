/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep  7 17:47:38 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int h, w, q; cin >> h >> w >> q;
    vector<vector<bool>> grid(h,vector<bool>(w,true));
    vector<set<int>> rows(h), cols(w);
    for (auto &st : rows)
        rep(i,w) st.insert(i);
    for (auto &st : cols)
        rep(i,h) st.insert(i);
    auto get = [&](int x, set<int> &st) -> pair<int,int> {
        if (st.empty()) return {-1,-1};
        auto it = st.lower_bound(x);
        assert(it == st.end() || *it != x);
        if (it == st.end())
            return {*st.rbegin(),-1};
        if (it == st.begin()) return {-1,*it};
        return {*prev(it),*it};
    };
    debug(h,w);
    while(q--) {
        int x, y; cin >> x >> y;
        --x;--y;
        debug(endl,x,y);
        if (grid[x][y]) {
            grid[x][y] = false;
            rows[x].erase(y);
            cols[y].erase(x);
            continue;
        }
        auto [y1,y2] = get(y,rows[x]);
        debug(y1,y2);
        if (y1 != -1) {
            assert(grid[x][y1]);
            grid[x][y1] = false;
            rows[x].erase(y1);
            cols[y1].erase(x);
        }
        if (y2 != -1) {
            assert(grid[x][y2]);
            grid[x][y2] = false;
            rows[x].erase(y2);
            cols[y2].erase(x);
        }
        auto [x1,x2] = get(x,cols[y]);
        debug(x1,x2);
        if (x1 != -1) {
            assert(grid[x1][y]);
            grid[x1][y] = false;
            cols[y].erase(x1);
            rows[x1].erase(y);
        }
        if (x2 != -1) {
            assert(grid[x2][y]);
            grid[x2][y] = false;
            cols[y].erase(x2);
            rows[x2].erase(y);
        }
    }
    debug(grid);
    int sol = 0;
    for (auto &g : grid)
        sol += accumulate(all(g),0);
    cout << sol << endl;
}