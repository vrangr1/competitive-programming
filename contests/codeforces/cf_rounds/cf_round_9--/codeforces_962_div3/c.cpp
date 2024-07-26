/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jul 26 20:13:48 IST 2024
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
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> act(n,vector<int>(26,0)), bct(n,vector<int>(26,0));
    rep(i,n) {
        if (i) {
            act[i] = act[i-1];
            bct[i] = bct[i-1];
        }
        act[i][a[i]-'a']++;
        bct[i][b[i]-'a']++;
    }
    auto get = [&](int l, int r) -> pair<vector<int>,vector<int>> {
        auto ca = act[r];
        auto cb = bct[r];
        if (l) {
            rep(i,26) {
                ca[i] -= act[l-1][i];
                cb[i] -= bct[l-1][i];
            }
        }
        return {ca,cb};
    };
    while(q--) {
        int l, r; cin >> l >> r;
        --l;--r;
        auto [ca, cb] = get(l,r);
        int sol = 0;
        rep(i,26) {
            sol += min(ca[i],cb[i]);
        }
        sol = (r-l+1)-sol;
        cout << sol << endl;
    }
}