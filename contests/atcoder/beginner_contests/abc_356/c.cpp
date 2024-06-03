/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun  1 17:37:04 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

#define open 'o'
#define close 'x'

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<vector<int>,char>> res(m);
    int opct = 0;
    rep(i,m) {
        int len; cin >> len;
        res[i].first.resize(len);
        rep(j,len) {
            cin >> res[i].first.at(j);
        }
        cin >> res[i].second;
        opct += (res[i].second == open);
    }
    debug(res);
    auto eval = [&](int cur) -> bool {
        for (auto [vec, r] : res) {
            int ct = 0;
            for (int key : vec) {
                key = (1<<(key-1));
                if (key&cur) ct++;
            }
            if (ct >= k && r == close) return false;
            if (ct < k && r == open) return false;
        }
        return true;
    };
    int t = 1<<n, sol = 0;
    rep(i,t) {
        sol += eval(i);
    }
    cout << sol << endl;
}