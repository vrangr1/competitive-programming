/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri May 31 02:47:39 IST 2024
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
private:
    int get_val(int ind) {
        if (ind < sz(a)) return a[ind];
        return 0;
    }
public:
    int n, time;
    vector<int> tree, ts, len, a;
    segtree(const vector<int> &arr, const vector<int> &b) {
        a = arr;
        n = sz(a);
        if (__builtin_popcount(n) != 1)
            n = 1<<(32-__builtin_clz(n));
        int gn = (n<<1);
        tree.assign(gn,-1);
        ts.assign(gn,-1);
        len.assign(gn,0);
        rep(i,sz(b)) {
            tree[i+n] = b[i];
            len[i+n] = 1;
        }
        rep(i,n-1,1,-1)
            len[i] = len[i<<1] + len[i<<1|1];
        time = 0;
    }

    void update(int l, int r, int ind) {
        time++;
        int il = ind, ir = ind+(r-l)-1;
        for (l+=n,r+=n; l < r; l>>=1,r>>=1) {
            if (l&1) {
                if (l < n)
                    tree[l] = il;
                else tree[l] = a[il];
                ts[l] = time;
                il += len[l];
                l++;
            }
            if (r&1) {
                --r;
                if (r < n) tree[r] = ir;
                else tree[r] = a[ir];
                ts[r] = time;
                ir -= len[r-1];
            }
            if (r >= 2)
                ir -= len[r-2];
        }
    }

    int query(int ind) {
        ind += n;
        int res = tree[ind], cts = ts[ind], off = 0;
        if (ind&1) off = 1;
        for(ind>>=1;ind>0;ind>>=1) {
            if (ts[ind] > cts) {
                cts = ts[ind];
                res = a[tree[ind]+off];
            }
            if (ind&1) off += len[ind^1];
        }
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    segtree st(a,b);
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, k; cin >> x >> y >> k;
            --x;--y;
            st.update(y,y+k,x);
        }
        else {
            int x; cin >> x; --x;
            cout << st.query(x) << endl;
        }
    }
}