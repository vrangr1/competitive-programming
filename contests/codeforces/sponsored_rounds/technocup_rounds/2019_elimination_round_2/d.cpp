/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Aug 22 20:05:01 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1() {
    int n, k; cin >> n >> k;
    vector<string> mat(n);
    rep(i,n) cin >> mat[i];
    auto hash = [&](int i, int j) -> int {
        return i*n+j;
    };
    auto get = [&](int h) -> pair<int,int> {
        return {h/n, h%n};
    };
    string sol;
    set<int> ninds;
    auto rec = [&](auto &&self, set<int> &inds, int r) -> void {
        // if (inds.empty()) {
        //     debug(sol);
        //     exit(0);
        // }
        debug(endl,sol,inds,r);
        assert(!inds.empty());
        if (sz(inds) == 1 && *inds.begin() == hash(n-1,n-1))
            return;
        char mn = 'z';
        for (int h : inds) {
            auto [x,y] = get(h);
            if (x != n-1) mn = min(mat[x+1][y],mn);
            if (y != n-1) mn = min(mat[x][y+1],mn);
        }
        ninds.clear();
        if (mn != 'a' && r > 0) {
            sol.push_back('a');
            r--;
            for (int h : inds) {
                auto [x,y] = get(h);
                if (x != n-1) ninds.insert(hash(x+1,y));
                if (y != n-1) ninds.insert(hash(x,y+1));
            }
            swap(inds,ninds);
            self(self,inds,r);
            return;
        }
        sol.push_back(mn);
        for (int h : inds) {
            auto [x,y] = get(h);
            if (x != n-1 && mat[x+1][y] == mn) ninds.insert(hash(x+1,y));
            if (y != n-1 && mat[x][y+1] == mn) ninds.insert(hash(x,y+1));
        }
        swap(inds,ninds);
        self(self,inds,r);
    };
    set<int> inds = {0};
    if (mat[0][0] == 'a' || k > 0) {
        sol.push_back('a');
        if (mat[0][0] != 'a') k--;
    }
    else sol.push_back(mat[0][0]);
    rec(rec,inds,k);
    cout << sol << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<string> g(n);
    rep(i,n) cin >> g[i];
    k = min(k,2*n-1);
    if (k == 2*n-1) return void(cout << string(2*n-1,'a') << endl);
    vector<vector<int>> mx(n,vector<int>(n,0));
    rep(i,n) {
        rep(j,n) {
            if (i) mx[i][j] = max(mx[i][j],mx[i-1][j]);
            if (j) mx[i][j] = max(mx[i][j],mx[i][j-1]);
            if (g[i][j] != 'a' || i+j-mx[i][j] > k) continue;
            mx[i][j]++;
        }
    }
    if (k+mx[n-1][n-1] >= 2*n-1) return void(cout << string(2*n-1,'a') << endl);
    auto hash = [&](int i, int j) -> int {
        return i*n+j;
    };
    auto get = [&](int h) -> pair<int,int> {
        return {h/n,h%n};
    };
    string sol = string(k+mx[n-1][n-1],'a');
    auto rec = [&](auto &&self, set<int> &inds) -> void {
        assert(!inds.empty());
        if (sz(inds) == 1 && *inds.begin() == hash(n-1,n-1)) {
            return;
        }
        char mn = 'z';
        for (int h : inds) {
            auto [x,y] = get(h);
            if (x != n-1) mn = min(mn,g[x+1][y]);
            if (y != n-1) mn = min(mn,g[x][y+1]);
        }
        sol.push_back(mn);
        set<int> ninds;
        for (int h : inds) {
            auto [x, y] = get(h);
            if (x != n-1 && g[x+1][y] == mn) ninds.insert(hash(x+1,y));
            if (y != n-1 && g[x][y+1] == mn) ninds.insert(hash(x,y+1));
        }
        swap(inds,ninds);
        self(self,inds);
    };
    int mval = mx[n-1][n-1];
    set<int> inds;
    rep(i,0,mval+k-1,1) {
        int j = mval+k-1-i;
        if (j >= n) continue;
        if (j < 0 || i >= n) break;
        if (mx[i][j] == mval)
        inds.insert(hash(i,j));
    }
    if (inds.empty()) {
        inds.insert(0);
        sol.push_back(g[0][0]);
    }
    rec(rec,inds);
    assert(sz(sol) == 2*n-1);
    cout << sol << endl;
}