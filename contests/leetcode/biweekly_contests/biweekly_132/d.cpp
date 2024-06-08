/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun  8 20:33:38 IST 2024
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

class segtree {
public:
    int n;
    vector<int> tree;
    segtree(){}

    segtree(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,0);
    }

    void build(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,0);
    }

    void update(int ind, int x) {
        ind+=n;
        tree[ind] = max(tree[ind],x);
        for(;ind>1;ind>>=1)
            tree[ind>>1] = max(tree[ind],tree[ind^1]);
    }

    int query(int ind) {
        return tree[ind+n];
    }

    int query(int l, int r) {
        int res = 0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res = max(tree[l++],res);
            if (r&1) res = max(res,tree[--r]);
        }
        return res;
    }
};

class Solution {
public:
    int maximumLength1(vector<int>& vals, int k) {
        int n = vals.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        for(int i = 0; i < n; ++i) dp[i][0] = 1;
        int sol = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int l = 0; l <= k; ++l) {
                    if (vals[i] == vals[j]) {
                        dp[i][l] = max(dp[i][l],dp[j][l]+1);
                    }
                    else if (l != k) {
                        dp[i][l+1] = max(dp[i][l+1],dp[j][l]+1);
                        sol = max(sol,dp[i][l+1]);
                    }
                    sol = max(sol,dp[i][l]);
                }
            }
        }
        debug(dp);
        return sol;
    }

    int maximumLength(vector<int>& vals, int k) {
        int n = vals.size();
        int ct = 0;
        vector<int> a(n);
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.find(vals[i]) != mp.end())
                a[i] = mp[vals[i]];
            else a[i] = mp[vals[i]] = ct++;
        }
        int sol = 0;
        vector<segtree> sts(k+1);
        for (auto &st : sts) st.build(ct);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                int cur = sts[j].query(a[i]) + 1;
                assert(cur >= 1);
                if (j == 0) cur = max(cur,1);
                else {
                    cur = max({cur,sts[j-1].query(0,a[i])+1,sts[j-1].query(a[i]+1,ct)+1});
                }
                sts[j].update(a[i],cur);
                sol = max(sol,cur);
            }
        }
        return sol;
    }
};

/*
[1,2,1,1,3]
2
[1,2,3,4,5,1]
0
[29,30,30]
0
[2]
0
[39,39,38,38]
0

4
2
2
1
2

5
5 2
1 2 1 1 3
6 0
1 2 3 4 5 1
3 0
29 30 30
1 0
2
4 0
39 39 38 38

*/

void solve() {
    Solution sol;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto cursol = sol.maximumLength(a,k);
    cout << cursol << endl;
}