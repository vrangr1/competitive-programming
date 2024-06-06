/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jun  7 00:13:54 IST 2024
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
    int n, d; cin >> n >> d;
    vector<pair<int,int>> pts(n);
    rep(i,n) cin >> pts[i].first >> pts[i].second;
    auto dist = [](pair<int,int> a, pair<int,int> b) -> int {
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        return abs(x1-x2) + abs(y1-y2);
    };
    rep(i,n) {
        rep(j,i+1,n-1,1) {
            rep(k,j+1,n-1,1) {
                int d1 = dist(pts[i],pts[j]), d2 = dist(pts[i],pts[k]), d3 = dist(pts[j],pts[k]);
                int ct = (d1 == d) + (d2 == d) + (d3 == d);
                if (ct >= 2) {
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    return;
                }
            }
        }
    }
    cout << "0 0 0\n";
}