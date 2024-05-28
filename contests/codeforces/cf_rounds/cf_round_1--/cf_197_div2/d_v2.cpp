/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 29 03:37:48 IST 2024
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

class segtree {
public:
    int n, xr;
    vector<int> tree;
    
    segtree(const vector<int> &a) {
        n = sz(a);
        xr = (32-__builtin_clz(n))&1;
        tree.assign((n<<1),0);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1,-1) {
            if (xr == ((32-__builtin_clz(i))&1))
                tree[i] = tree[i<<1]^tree[i<<1|1];
            else 
                tree[i] = tree[i<<1]|tree[i<<1|1];
        }
    }

    void update(int ind, int x) {
        for (tree[ind+=n]=x;ind>0;ind>>=1)
            if (xr == ((32-__builtin_clz((ind>>1)))&1))
                tree[ind>>1] = tree[ind]^tree[ind^1];
            else
                tree[ind>>1] = tree[ind]|tree[ind^1];
    }

    int query() {
        return tree[1];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    n = (1<<n);
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree st(a);
    while(m--) {
        int i, x; cin >> i >> x;
        --i;
        st.update(i,x);
        cout << st.query() << endl;
    }
}