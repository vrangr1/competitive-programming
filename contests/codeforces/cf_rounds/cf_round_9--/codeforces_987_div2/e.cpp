/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Nov 15 19:42:21 IST 2024
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
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int v; cin >> v;
        --v;
        g[i+1].push_back(v);
        g[v].push_back(i+1);
    }
    auto dfs = [&](auto &&self, int u, int p) -> int {
        int mxcd = 0, ct = sz(g[u])-1;
        for (const int &v : g[u]) {
            if (v == p) continue;
            ct++;
            int cd = self(self,v,u);
            mxcd = max(mxcd,cd+1);
        }
        int d = mxcd;
        return d;
    };
    cout << dfs(dfs,0,-1) << endl;
}