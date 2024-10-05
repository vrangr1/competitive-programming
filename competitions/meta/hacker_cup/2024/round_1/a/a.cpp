/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct  5 22:28:05 IST 2024
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
void solve(int test_case);

int main() {
	fastIO;
	int T;cin>>T;rep(t,T)solve(t+1);
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(int test_case) {
    cout << "Case #" << test_case << ": ";
    int n; cin >> n;
    ld l = 0, r = (ld)LLONG_MAX;
    rep(i,1,n,1) {
        ld d = i;
        ld a, b; cin >> a >> b;
        ld cr = d/a, cl = d/b;
        if (cr < l || cl > r) return void(cout << "-1\n");
        l = max(l,cl);
        r = min(r,cr);
    }
    cout << fixed << setprecision(10) << l << endl;
}