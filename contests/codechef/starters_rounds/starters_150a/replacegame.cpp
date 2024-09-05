/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep  4 20:15:46 IST 2024
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
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << "0\n");
    int last = n;
    char ch = '.';
    vector<pair<int,char>> ops;
    rep(i,n-k+1) {
        if (((last >= i || i-last >= k) && a[i] == b[i]) || ((last < i && i-last < k) && ch == b[i])) {
            a[i] = b[i];
            continue;
        }
        last = i;
        ch = b[i];
        a[i] = b[i];
        ops.emplace_back(i+1,ch);
    }
    rep(i,n-k+1,n-1,1) {
        if (last >= i || i-last >= k) break;
        a[i] = ch;
    }
    auto ans = [&]() -> void {
        assert(sz(ops) <= 2*n);
        cout << sz(ops) << endl;
        for (auto [i, c] : ops) {
            cout << i << " " << c << endl;
        }
    };
    if (a == b) {
        ans();
        return;
    }
    last = -1;
    ch = '.';
    rep(i,n-1,k-1,-1) {
        if (((last <= i || last-i >= k) && a[i] == b[i]) || ((last > i && last-i < k) && ch == b[i])) {
            a[i] = b[i];
            continue;
        }
        last = i;
        ch = b[i];
        a[i] = b[i];
        ops.emplace_back(i-k+2,ch);
    }
    rep(i,k-2,0,-1) {
        if (last <= i || last-i >= k) break;
        a[i] = ch;
    }
    if (a == b) {
        ans();
        return;
    }
    cout << "-1\n";
}