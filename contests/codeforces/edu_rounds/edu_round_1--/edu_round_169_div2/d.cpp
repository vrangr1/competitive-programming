/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Aug 15 20:24:42 IST 2024
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

#define red 'R'
#define blue 'B'
#define green 'G'
#define yellow 'Y'
unordered_map<char,ll> ind;
unordered_map<ll,char> rev;
map<pair<char,char>,ll> cind;

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    ind[red] = 0;
    ind[blue] = 1;
    ind[green] = 2;
    ind[yellow] = 3;
    rev[0] = red;
    rev[1] = blue;
    rev[2] = green;
    rev[3] = yellow;
    cind[{red,blue}] = 0;
    cind[{blue,red}] = 0;
    cind[{red,green}] = 1;
    cind[{green,red}] = 1;
    cind[{red,yellow}] = 2;
    cind[{yellow,red}] = 2;
    cind[{blue,green}] = 3;
    cind[{green,blue}] = 3;
    cind[{blue,yellow}] = 4;
    cind[{yellow,blue}] = 4;
    cind[{green,yellow}] = 5;
    cind[{yellow,green}] = 5;
}

class segtree {
public:
    vector<vector<ll>> mntree, mxtree;
    ll n;
    segtree(vector<vector<bool>> &exist) {
        n = sz(exist);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        mntree.assign(gn,vector<ll>(6,n));
        mxtree.assign(gn,vector<ll>(6,-1));
        rep(i,n) {
            rep(c1,4) {
                char col1 = rev[c1];
                rep(c2,c1+1,3,1) {
                    char col2 = rev[c2];
                    if (exist[i][c1] && exist[i][c2]) {
                        mntree[i+n][cind[{col1,col2}]] = i;
                        mxtree[i+n][cind[{col1,col2}]] = i;
                    }
                    
                }
            }
        }
        rep(i,n-1ll,1ll,-1) {
            rep(c,6) {
                mntree[i][c] = min(mntree[i<<1ll][c],mntree[i<<1ll|1ll][c]);
                mxtree[i][c] = max(mxtree[i<<1ll][c],mxtree[i<<1ll|1ll][c]);
            }
        }
        debug(mntree);
    }

    ll mnq(ll l, ll r, ll c1, ll c2) {
        char col1 = rev[c1], col2 = rev[c2];
        ll ci = cind[{col1,col2}];
        ll res = n;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                res = min(res,mntree[l][ci]);
                l++;
            }
            if (r&1ll) {
                res = min(res,mntree[--r][ci]);
            }
        }
        return res;
    }

    ll mxq(ll l, ll r, ll c1, ll c2) {
        char col1 = rev[c1], col2 = rev[c2];
        ll ci = cind[{col1,col2}];
        ll res = -1;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                res = max(res,mxtree[l][ci]);
                l++;
            }
            if (r&1ll) {
                res = max(res,mxtree[--r][ci]);
            }
        }
        return res;
    }
};

void solve() {
    init();
    ll n, q; cin >> n >> q;
    vector<set<ll>> inds(4);
    vector<vector<ll>> cols(n);
    vector<vector<bool>> exist(n,vector<bool>(4,false));
    rep(i,n) {
        string s; cin >> s;
        for (char &c : s) {
            inds[ind[c]].insert(i);
            cols[i].push_back(ind[c]);
            exist[i][ind[c]] = true;
        }
    }
    debug(exist);
    segtree seg(exist);
    auto get = [&](ll x, ll y) -> ll {
        if (x > y) swap(x,y);
        if (x == y) {
            return 0;
        }
        rep(c,4) {
            if (inds[c].find(x) != inds[c].end() && inds[c].find(y) != inds[c].end())
                return y-x;
        }
        ll sol = LLONG_MAX;
        for (ll c1 : cols[x]) {
            for (ll c2 : cols[y]) {
                ll p = seg.mnq(x+1ll,y,c1,c2);
                if (p != n) {
                    return y-x;
                }
                p = seg.mnq(y,n,c1,c2);
                assert(p > y);
                if (p != n) {
                    sol = min(sol,p-x+p-y);
                }
                p = seg.mxq(0,x,c1,c2);
                if (p != -1) sol = min(sol,x-p+y-p);
            }
        }
        if (sol == LLONG_MAX) return -1;
        return sol;
    };
    while(q--) {
        ll x, y; cin >> x >> y;
        --x;--y;
        cout << get(x,y) << endl;
    }
}