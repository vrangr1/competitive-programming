/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 21 17:34:52 IST 2024
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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int sol = 0;
    auto chk = [&](int i) -> int {
        if (i >= n-2 || i < 0) return 0;
        return s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C';
    };
    rep(i,n-2) {
        sol += chk(i);
    }
    while(q--) {
        int i; char ch; cin >> i >> ch;i--;
        sol -= chk(i-2) + chk(i-1) + chk(i);
        s[i] = ch;
        sol += chk(i-2) + chk(i-1) + chk(i);
        
        cout << sol << endl;
    }
}