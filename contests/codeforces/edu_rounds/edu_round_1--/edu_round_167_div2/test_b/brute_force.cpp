/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jun 27 21:01:49 IST 2024
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

void solve1() {
    string a, b, c; cin >> a >> b >> c;
    cout << sz(c) << endl;
}

void solve2() {
    string a, b; cin >> a >> b;
    int n = sz(a), m = sz(b);
    int sol = n+m;
    rep(i,m) {
        int k = 0;
        int cur = n + i;
        rep(j, i, m-1, 1) {
            if (k >= n) {
                cur++;
                continue;
            }
            while(k < n && a[k] != b[j]) {
                k++;
            }
            if (k == n) cur++;
        }
        sol = min(sol,cur);
    }
    reverse(all(a));
    reverse(all(b));
    rep(i,m) {
        int k = 0;
        int cur = n + i;
        rep(j, i, m-1, 1) {
            if (k >= n) {
                cur++;
                continue;
            }
            while(k < n && a[k] != b[j]) {
                k++;
            }
            if (k == n) cur++;
        }
        sol = min(sol,cur);
    }
    cout << sol << endl;
}

void solve() {
    string a, b; cin >> a >> b;
    int n = sz(a), m = sz(b);
    auto check = [&](int l, int r) -> bool {
        int i = l;
        for (char ch : a) {
            if (i > r) return true;
            if (ch == b[i])
                i++;
        }
        return i > r;
    };
    auto pos = [&](int len) -> bool {
        if (len < n) return false;
        if (len >= n + m) return true;
        int rem = len-n;
        assert(rem < m);
        rep(i,rem+1) {
            int left = i, right = rem-left;
            if (check(left,m-right-1)) return true;
        }
        return false;
    };
    auto bsch = [&](auto &&self, int low, int high) -> int {
        assert(low <= high);
        if (low == high) {
            assert(pos(high));
            return high;
        }
        int mid = (low+high)/2;
        if (pos(mid)) return self(self, low, mid);
        return self(self, mid+1, high);
    };
    cout << bsch(bsch, n, n+m) << endl;
}