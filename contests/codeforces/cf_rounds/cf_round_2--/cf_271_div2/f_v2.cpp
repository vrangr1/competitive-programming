/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 02:45:10 IST 2024
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

class segtree {
public:
    int n;
    vector<int> tree;

    segtree(const vector<int> &a) {
        n = sz(a);
        int gn = n<<1;
        if (__builtin_popcount(gn) != 1)
            gn = 1<<(32-__builtin_clz(gn));
        tree.assign(gn,0);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1,-1)
            tree[i] = gcd(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r) {
        int res = 0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res = gcd(res,tree[l++]);
            if (r&1) res = gcd(tree[--r],res);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int,vector<int>> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    segtree st(a);
    auto get = [&](int l, int r, int v) -> int {
        if (mp.find(v) == mp.end()) return 0;
        auto &vec = mp[v];
        return (int)(upper_bound(all(vec),r)-lower_bound(all(vec),l));
    };
    int t; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;--l;
        cout << (r-l-get(l,r-1,st.query(l,r))) << endl;
    }
}