/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep 17 19:56:10 IST 2024
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
    int n, m; cin >> n >> m;
    int ct = (n-3)*(m-2);
    if (ct <= 1) return void(cout << "0\n");
    auto get = [](int r, int c) -> int {
        int sol = (r-3)*(c-2);
        if (sol <= 0) return 0;
        return sol;
    };
    int sol = 0;
    rep(i,n-3) {
        rep(j,m-2) {
            debug(endl,i,j,sol);
            sol += get(i,m) + get(n-i-4,m);
            int l = j-2, r = (m-j-3-2);
            l = max(0,l);
            r = max(0,r);
            sol += (l+r)*(min(i,3)+min(n-i-4,3)+1);
            debug(sol);
        }
    }
    cout << sol << endl;
}