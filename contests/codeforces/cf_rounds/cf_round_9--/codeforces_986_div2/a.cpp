/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 10 21:01:16 IST 2024
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

const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    auto gdir = [&](char ch) -> int {
        switch(ch) {
            case 'N': return 0;
            case 'E': return 1;
            case 'S': return 2;
            default: return 3;
        }
    };
    int x = 0, y = 0;
    rep(i,int(1e5)) {
        int ind = i%n;
        int d = gdir(s[ind]);
        int nx = x+dx[d], ny = y+dy[d];
        x = nx;
        y = ny;
        if (x == a && y == b) return void(cout << "YES\n");
    }
    cout << "NO\n";
}