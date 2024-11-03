/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 20:46:17 IST 2024
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
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(n,vector<int>(k));
    rep(i,n) {
        rep(j,k) {
            cin >> a[i][j];
            if (i) a[i][j] |= a[i-1][j];
        }
    }
    while(q--) {
        int m; cin >> m;
        int l = 0, r = n-1;
        while(m--) {
            int j, c;
            char op;
            cin >> j >> op >> c;
            --j;
            if (l > r) continue;
            if (op == '<') {
                if (a[n-1][j] < c) continue;
                if (a[0][j] >= c) {
                    l = 1;
                    r = 0;
                    continue;
                }
                int low = 0, high = n-1;
                while(low < high) {
                    int mid = (low+high+1)/2;
                    if (a[mid][j] < c) low = mid;
                    else high = mid-1;
                }
                l = max(l,0);
                r = min(r,low);
            } else {
                if (a[0][j] > c) continue;
                if (a[n-1][j] <= c) {
                    l = 1;
                    r = 0;
                    continue;
                }
                int low = 0, high = n-1;
                while(low < high) {
                    int mid = (low+high)/2;
                    if (a[mid][j] > c) high = mid;
                    else low = mid+1;
                }
                l = max(l,high);
                r = min(r,n-1);
            }
        }
        if (l > r) cout << "-1\n";
        else cout << l+1 << endl;
    }
}