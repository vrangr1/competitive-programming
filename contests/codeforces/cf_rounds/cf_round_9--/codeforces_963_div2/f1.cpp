/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug  4 20:59:02 IST 2024
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

const vector<ll> dx = {-1,1,0,0};
const vector<ll> dy = {0,0,1,-1};

void solve1() {
    int n, k, w, h; cin >> n >> k >> w >> h;
    string s; cin >> s;
    

    int sol = 0;
    int rc = 0, vc = 0;
    map<char,int> mp;
    mp['L'] = 0;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x <= w && y >= 0 && y <= h;
    };
    int x = 0, y = 0;
    auto inc = [&]() -> void {
        sol += (x==0&&y==0);
    };
    rep(i,k) {
        char dir = s[i];
        if (dir == 'L' || dir == 'R') {
            if (rc%2) dir = (dir == 'L'?'R':'L');
        }
        else {
            if (vc%2) dir = (dir == 'U'?'D':'U');
        }
        int nx = x + dx[mp[dir]], ny = y + dy[mp[dir]];
        if (valid(nx,ny)) {
            x = nx;
            y = ny;
            inc();
            continue;
        }
        if (dir == 'L' || dir == 'R') {
            rc++;
            dir = (dir == 'L'?'R':'L');
        }
        else {
            vc++;
            dir = (dir == 'U'?'D':'U');
        }
        nx = x + dx[mp[dir]];
        ny = y + dy[mp[dir]];
        assert(valid(nx,ny));
        x = nx;
        y = ny;
        inc();
    }
    
}

#define left 'L'
#define right 'R'
#define up 'U'
#define down 'D'

void solve() {
    ll n, k, w, h; cin >> n >> k >> w >> h;
    string s; cin >> s;
    map<char,ll> mp;
    map<ll,char> rev;
    mp['L'] = 0;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    rev[0] = left;
    rev[1] = right;
    rev[2] = up;
    rev[3] = down;
    vector<vector<ll>> cts(4,vector<ll>(n,0));
    rep(i,n) {
        rep(dir,4)
            cts[dir][i] = (i?cts[dir][i-1]:0) + (s[i] == rev[dir]);
    }
    auto get = [&](ll l, ll r, char dir) -> ll {
        return cts[r][dir] - (l?cts[l-1][dir]:0ll);
    };
    ll x = 0, y = 0, sol = 0;
    auto inc = [&]() -> void {
        sol += (x==0&&y==0);
    };
    rep(c,k) {
        ll i = 0;
        while(i < n) {
            rep(dir,4ll) {
                
            }
        }
    }
}