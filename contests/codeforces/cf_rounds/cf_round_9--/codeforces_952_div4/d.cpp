/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Thu Sep 19 02:00:13 IST 2024
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
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<int> ct(n);
    rep(i,n) {
        cin >> grid[i];
        ct[i] = int(count(all(grid[i]),'#'));
    }
    auto ans = [](int x, int y) -> void {
        cout << x+1 << " " << y + 1 << endl;
    };
    rep(i,n) {
        if (ct[i] == 0) continue;
        if (ct[i] == 1) {
            if (i == n-1) {
                rep(j,m)
                    if (grid[i][j] == '#')
                        return ans(i,j);
                assert(false);
                return;
            }
            if (ct[i+1] == 0) 
                rep(j,m)
                    if (grid[i][j] == '#')
                        return ans(i,j);
            continue;
        }
        assert(i != n-1);
        if (ct[i+1] > ct[i]) continue;
        rep(j,m)
            if (grid[i][j] == '#') 
                return ans(i,j+ct[i]/2);
        assert(false);
    }
    assert(false);
}