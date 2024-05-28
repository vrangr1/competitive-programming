/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 29 03:58:58 IST 2024
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
private:
    void do_update(int l, int r, int x) {
        for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if (l&1) {
                if (ts[l] > time) {
                    ts[l] = time;
                    tree[l] = x;
                }
                l++;
            }
            if (r&1) {
                --r;
                if (ts[r] > time) {
                    ts[r] = time;
                    tree[r] = x;
                }
            }
        }
    }

    void push() {
        rep(i,1,n-1,1) {
            if (ts[i] < ts[i<<1]) {
                ts[i<<1] = ts[i];
                tree[i<<1] = tree[i];
            }
            if (ts[i] < ts[i<<1|1]) {
                ts[i<<1|1] = ts[i];
                tree[i<<1|1] = tree[i];
            }
        }
    }

public:
    int n, time;
    vector<int> tree, ts;

    segtree(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = 1<<(32-__builtin_clz(gn));
        tree.assign(gn,-1);
        time = 0;
        ts.assign(gn,INT_MAX);
    }

    void update(int l, int r, int x) {
        do_update(l,x,x);
        do_update(x+1,r,x);
        time++;
    }

    void print() {
        push();
        rep(i,n)
            if (tree[i+n] != i)
                cout << tree[i+n]+1 << " \n"[i==n-1];
            else cout << 0 << " \n"[i==n-1];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segtree st(n);
    while(m--) {
        int l, r, x; cin >> l >> r >> x;
        --l;--x;
        st.update(l,r,x);
    }
    st.print();
}

