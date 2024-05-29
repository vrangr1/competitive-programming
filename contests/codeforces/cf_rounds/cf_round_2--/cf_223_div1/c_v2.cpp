/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 01:53:23 IST 2024
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

#define open '('
#define close ')'

class segtree {
private:
    void merge(array<int,3> &res, array<int,3> &left, array<int,3> &right) {
        int m = min(left[1],right[2]);
        res[0] = left[0] + right[0] + m;
        res[1] = left[1] + right[1] - m;
        res[2] = left[2] + right[2] - m;
    }

    array<int,3> merge(array<int,3> &left, array<int,3> &right) {
        array<int,3> res;
        int m = min(left[1],right[2]);
        res[0] = left[0] + right[0] + m;
        res[1] = left[1] + right[1] - m;
        res[2] = left[2] + right[2] - m;
        return res;
    }
public:
    int n;
    vector<array<int,3>> tree;
    
    segtree(const string &s) {
        n = sz(s);
        if (__builtin_popcount(n) != 1)
            n = (1<<(32-__builtin_clz(n)));
        tree.resize((n<<1));
        rep(i,n)
            if (i < sz(s))
                tree[i+n] = {0,s[i]==open,s[i]==close};
            else
                tree[i+n] = {0,0,0};
        rep(i,n-1,1,-1)
            merge(tree[i],tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r) {
        array<int,3> resl({0,0,0}), resr({0,0,0});
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) resl = merge(resl,tree[l++]);
            if (r&1) resr = merge(tree[--r],resr);
        }
        return merge(resl,resr)[0]*2;
    }
};

void solve() {
    string s; cin >> s;
    segtree st(s);
    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r; --l;
        cout << st.query(l,r) << endl;
    }
}