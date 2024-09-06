/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Sep  6 23:40:45 IST 2024
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
void solve(int t);

int main() {
	fastIO;
	int T;cin>>T;rep(t,T)solve(t);
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(int t) {
    cout << "Case #" << t+1 << ": ";
    int p, x, y; cin >> p >> x >> y;
    if (p == 0) return void(cout << "white\n");
    auto dist = [](int x1, int y1, int x2, int y2) -> int {
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    };
    if (dist(x,y,50,50) > 2500) return void(cout << "white\n");
    ld cx = y-50, cy = x-50;
    debug(cx,cy);
    const ld pi = M_PI;
    ld ang = atan2l(cy,cx);
    if (ang < 0) ang = pi + (pi+ang);
    debug(ang);
    ld ap = ((ang/(ld(2)*pi))*(ld(100)));
    debug(ap);
    if (ap <= p) cout << "black\n";
    else cout << "white\n";

}