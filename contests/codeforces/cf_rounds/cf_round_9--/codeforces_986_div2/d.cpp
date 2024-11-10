/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 10 22:13:57 IST 2024
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

class segtree {
public:
    int n;
    vector<pair<int,int>> tree;
    
    segtree() {}
    
    // segtree(vector<int> &p) {
    //     n = sz(p);
    //     int gn = (n<<1);
    //     if (__builtin_popcount(gn) != 1)
    //         gn = (1<<(32-__builtin_clz(gn)));
    //     tree.assign(gn,{0,0});
    // }

    void build(vector<int> &p) {
        n = sz(p);
        int gn = (n<<1);
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,{0,0});
        rep(i,n)
            tree[p[i]+n] = {0,i};
        rep(i,n-1,1,-1) {
            auto [lmx, lnxt] = tree[i<<1];
            auto [rmx, rnxt] = tree[i<<1|1];
            if (lmx >= rmx) tree[i] = tree[i<<1];
            else tree[i] = tree[i<<1|1];
        }
    }

    pair<int,int> query(int l, int r) {
        pair<int,int> res = {-1,0};
        for(l+=n,r+=n; l < r; l>>=1,r>>=1) {
            if (l&1) {
                auto [mx, nxt] = tree[l];
                if (mx > res.first) {
                    res = tree[l];
                }
                ++l;
            }
            if (r&1) {
                --r;
                auto [mx, nxt] = tree[r];
                if (mx > res.first) {
                    res = tree[r];
                }
            }
        }
        return res;
    }

    void update(int ind, int mx, int nxt) {
        ind+=n;
        if (tree[ind].first >= mx) return;
        tree[ind] = {mx,nxt};
        for(;ind>1;ind>>=1) {
            auto [lmx, lnxt] = tree[ind];
            auto [rmx, rnxt] = tree[ind^1];
            if (lmx >= rmx) tree[ind>>1] = tree[ind];
            else tree[ind>>1] = tree[ind^1];
        }
    }
};

void solve() {
    int n; cin >> n;
    vector<vector<int>> ps(3,vector<int>(n));
    rep(i,3) rep(j,n) {
        cin >> ps[i][j];
        --ps[i][j];
    }
    vector<segtree> segs(3);
    rep(i,3) segs[i].build(ps[i]);
    debug(segs[1].query(0,1));
    vector<array<int,3>> dp(n); // max card, player, nxt card type
    dp[n-1] = {n-1,0,n-1};
    rep(i,3)
        segs[i].update(ps[i][n-1],n-1,n-1);
    rep(i,n-2,0,-1) {
        dp[i] = {i,0,i};
        rep(j,3) {
            auto [mx, nxt] = segs[j].query(0,ps[j][i]);
            if (mx < i) {
                mx = i;
                nxt = i;
            }
            if (mx > dp[i][0]) {
                dp[i] = {dp[mx][0],j,nxt};
            }
            segs[j].update(ps[j][i], mx, nxt);
        }
    }
    debug(dp,segs[1].query(0,1));
    if (dp[0][0] < n-1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int curind = 0;
    vector<pair<int,int>> ops;
    while(curind != n-1) {
        assert(dp[curind][0] == n-1);
        ops.emplace_back(dp[curind][1],dp[curind][2]);
        curind = dp[curind][2];
    }
    cout << sz(ops) << endl;
    for (auto [p, typ] : ops) {
        switch(p) {
            case 0: cout << "q "; break;
            case 1: cout << "k "; break;
            default: cout << "j "; break;
        }
        cout << typ+1 << endl;
    }
}