/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 21 17:48:01 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class DSU {
public:
    int n;
    vector<int> p;
    vector<set<int>> st;
    DSU(int gn) : p(gn,-1) {
        n = gn;
        st.resize(n);
        rep(i,n) st[i].insert(i+1);
    }

    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz(st[x]) > sz(st[y])) swap(x,y);
        p[x] = y;
        st[y].insert(all(st[x]));
    }
};

void solve() {
    int n, q; cin >> n >> q;
    DSU dsu(n);
    while(q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1)
            dsu.unite(u-1,v-1);
        else {
            int p = dsu.find(u-1);
            if (sz(dsu.st[p]) < v) cout << "-1\n";
            else {
                // auto temp = dsu.st[p];
                // while(--v)
                //     temp.erase(prev(temp.end()));
                // assert(!temp.empty());
                // cout << *temp.rbegin() << endl;
                auto it = dsu.st[p].rbegin();
                while(--v) {
                    it = next(it);
                }
                cout << *it << endl;
            }
        }
    }
}