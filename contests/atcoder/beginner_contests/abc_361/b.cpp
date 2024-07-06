/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul  6 17:32:15 IST 2024
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
#define yes "Yes\n"
#define no "No\n"
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

void solve() {
    vector<int> a(6), b(6);
    rep(i,6) cin >> a[i];
    rep(i,6) cin >> b[i];
    auto ints = [](int x1, int x2, int y1, int y2) -> bool {
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);
        return (x1 <= y1 && y1 <= x2) || (y1 <= x1 && x1 <= y2);
    };
    if (!ints(a[0],a[3],b[0],b[3]) || !ints(a[1],a[4],b[1],b[4]) || !ints(a[2],a[5],b[2],b[5]))
        return void(cout << no);
    auto neq = [&ints](int x1, int x2, int y1, int y2) -> bool {
        assert(ints(x1,x2,y1,y2));
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);
        if (x1 <= y1 && y1 <= x2) return y1 != x2;
        return x1 != y2;
    };
    if (!neq(a[0],a[3],b[0],b[3]) || !neq(a[1],a[4],b[1],b[4]) || !neq(a[2],a[5],b[2],b[5]))
        return void(cout << no);
    cout << yes;
}