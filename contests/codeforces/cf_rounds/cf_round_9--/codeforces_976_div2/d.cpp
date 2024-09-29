/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep 29 21:16:37 IST 2024
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

class DSU {
public:
    int n, cn;
    vector<int> parent, rank;
    DSU(int gn) : parent(gn+1,-1), rank(gn+1,0) {
        n = gn;
        cn = n;
    }

    int find(int x) {
        assert(x > 0 && x <= n);
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        --cn;
        if (rank[x] > rank[y]) swap(x,y);
        parent[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    auto ins = [](int l, int r, set<pair<int,int>> &st) {
        if (st.empty()) {
            st.emplace(l,r);
            return;
        }
        auto it = st.lower_bound({l,-1});
        vector<pair<int,int>> del;
        if (it != st.begin()) {
            auto pv = prev(it);
            if (pv->second >= l) {
                del.push_back(*pv);
                l = min(l,pv->first);
                r = max(l,pv->second);
            }
        }
        if (it != st.end()) {
            if (it->first <= r) {
                del.push_back(*it);
                l = min(l,it->first);
                r = max(r,it->second);
            }
        }
        for (auto d : del)
            st.erase(d);
        st.emplace(l,r);
    };
    vector<vector<set<pair<int,int>>>> dp(11,vector<set<pair<int,int>>>(10));
    while(m--) {
        int a, d, k; cin >> a >> d >> k;
        int l = a, r = a+k*d;
        if (k == 0) continue;
        debug(l,r);
        ins(l,r,dp[d][l%d]);
    }
    debug(dp);
    DSU dsu(n);
    rep(d,1,10,1) {
        rep(stt,d) {
            for (auto [l,r] : dp[d][stt]) {
                int lv = l;
                rep(v,l+d,r,d) {
                    dsu.unite(v,lv);
                    lv = v;
                }
            }
        }
    }
    cout << dsu.cn << endl;
}