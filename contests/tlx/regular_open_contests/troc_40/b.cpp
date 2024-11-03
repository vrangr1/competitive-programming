/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov  3 11:37:53 IST 2024
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
    ll n, x, y, p; cin >> n >> x >> y >> p;
    auto ans = [](int v) -> void {
        if (v) cout << "YA\n";
        else cout << "TIDAK\n";
    };
    if (x >= y) {
        if (p >= x) {
            if (p-x <= n)
                ans(1);
            else ans(0);
        }
        else {
            if (p <= max(y-1ll,0ll)) {
                if (y == 0ll){
                    if (p == 0) ans(1);
                    else ans(0);
                } else {
                    if (y-p <= n) ans(1);
                    else ans(0);
                }
            }
            else ans(0);
        }
        return;
    }
    if (p <= x) {
        if (x-p <= n) ans(1);
        else ans(0);
    }
    else {
        if (p > y) {
            if (p-y <= n) ans(1);
            else ans(0);
        }
        else ans(0);
    }
}

/*

x > y
x-y+1
1) y-1, x+1
2) x+1, y-1

x, 0
0,x+1 or x+1,0



x >= y:
    x wins: diff  : 1
            final : x+1,y-1
    y wins: diff  : x-y+1
            final : y-1,x+1
x , 0:
    x wins: x+1,0
    y wins:  0 ,x+1
x < y: x wins: y+1,x-1
       y wins: x-1,y+1
0,y:
    x wins: y+1,0
    y wins: 0,y+1
*/