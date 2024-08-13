/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Aug 12 19:54:18 IST 2024
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1) return void(cout<<"-1\n");
    ll as = accumulate(all(a),0ll);
    vector<int> b(n,0);
    rep(i,1,n-1,2)
        b[i] = 1;
    if (as != n/2) {
        print_vec(b);
        return;
    }
    if (a != b) {
        print_vec(b);
        return;
    }
    if (n%2) {
        b.back() = 1;
        b[n-2] = 0;
        assert(a!=b);
        print_vec(b);
        return;
    }
    if (n == 2) return void(cout << "0 0\n");
    b[n-3] = 0;
    b[n-2] = 1;
    assert(a!=b);
    print_vec(b);
}