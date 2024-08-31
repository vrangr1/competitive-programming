/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 31 17:48:33 IST 2024
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
    vector<pair<int,int>> pt;
    segtree(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,-1);
        pt.assign(gn,{-1,-1});
    }

    void update(int ind, int c, pair<int,int> cpt) {
        ind += n;
        if (tree[ind] >= c) return;
        tree[ind] = c;
        pt[ind] = cpt;
        for(;ind>1;ind>>=1) {
            if (tree[ind>>1] >= tree[ind]) continue;
            tree[ind>>1] = tree[ind];
            pt[ind>>1] = pt[ind];
        }
    }

    pair<int,pair<int,int>> query(int y) {
        int resc = -1;
        pair<int,int> rpt = {-1,-1};
        int l = 0, r = y+1;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) {
                if (resc < tree[l]) {
                    resc = tree[l];
                    rpt = pt[l];
                }
                ++l;
            }
            if (r&1) {
                --r;
                if (resc < tree[r]) {
                    resc = tree[r];
                    rpt = pt[r];
                }
            }
        }
        return {resc,rpt};
    }
};

void solve() {
    int h, w, n; cin >> h >> w >> n;
    vector<pair<int,int>> pts(n);
    rep(i,n) cin >> pts[i].first >> pts[i].second;
    sort(all(pts));
    auto get = [&]() -> pair<int,string> {
        map<pair<int,int>,pair<int,int>> mp;
        segtree seg(w+2);
        seg.update(1,0,{1,1});
        mp[{1,1}] = {-1,-1};
        debug(seg.query(1));
        for (auto [x,y] : pts) {
            auto [mx, pt] = seg.query(y);
            seg.update(y,mx+1,{x,y});
            mp[{x,y}] = pt;
        }
        int x = h, y = w;
        auto [sol,pt] = seg.query(y);
        string s;
        while(pt.first != -1) {
            debug(x,y);
            auto [cx,cy] = pt;
            debug(cx,cy);
            assert(cx <= x && cy <= y);
            s += string(x-cx,'D') + string(y-cy,'R');
            x = cx;
            y = cy;
            pt = mp[{cx,cy}];
        }
        reverse(all(s));
        return {sol,s};
    };
    auto [sol,s] = get();
    debug(sol,s);
    cout << sol << endl;
    assert(sz(s) == h+w-2);
    cout << s << endl;
}