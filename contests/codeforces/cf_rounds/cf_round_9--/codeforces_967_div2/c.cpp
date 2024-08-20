/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 20 20:20:47 IST 2024
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
    int n; cin >> n;
    auto ask = [&](int a, int b) -> int {
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int x; cin >> x;
        if (x == -1) exit(0);
        return x;
    };
    auto ans = [&](vector<vector<int>> &g) -> void {
        //     cout << "!";
        // for (int i = 1; i <= n; ++i) {
        //     if (g[i].empty()) continue;
        //     for (int v : g[i]) {
        //         if (i > v) continue;
        //         cout << " " << i << " " << v;
        //     }
        // }
        cout << "!";
        for (auto &e : g) {
            cout << " " << e[0] << " " << e[1];
        }
        cout << endl;
        cout.flush();
    };
    vector<vector<int>> g;
    if (n == 2) {
        g.push_back({1,2});
        ans(g);
        return;
    }
    // vector<vector<int>> g(n+1);
    // set<int> rem, seen;
    // rep(i,1,n,1) rem.insert(i);
    rep(i,2,n,1) {
        int u = i, v = 1;
        while(true) {
            int nx = ask(u,v);
            if (nx == u) {
                g.push_back({u,v});
                break;
            }
            v = nx;
        }
    }
    assert(sz(g) == n-1);
    ans(g);
}