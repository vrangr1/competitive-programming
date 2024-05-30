/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 21:07:26 IST 2024
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

#define open '('
#define close ')'

class segtree{
public:
    int n;
    vector<int> tree;
    segtree(vector<int> &a) {
        n = sz(a)+1;
        int gn = (n)<<1;
        if (__builtin_popcount(gn) != 1)
            gn = 1<<(32-__builtin_clz(gn));
        tree.assign(gn,0);
    }

    void update(int ind, int x) {
        
    }
};

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> f(n);
    f[0] = (s[0] == open?1:-1);
    rep(i,1,n-1,1)
        f[i] = f[i-1] + (s[i] == open?1:-1);
    vector<vector<int>> inds(n+1);
    rep(i,n)
        inds[f[i]].push_back(i);
    auto get = [&](int l, int r, int v) -> ll {
        if (l > r) return 0ll;
        auto &vec = inds[v];
        return (ll)(upper_bound(all(vec),r) - lower_bound(all(vec),l));
    };
    
    ll sol = 0ll;
    debug(f);
    rep(i,1,n-1,1) {
        if (f[i-1] == 0) continue;
        int ind = (int)(upper_bound(f.begin()+i,f.end(),2*f[i-1])-f.begin());
        debug(i,ind,f[i-1],get(i,ind-1,f[i-1]));
        sol += get(i,ind-1,f[i-1]); 
    }
    cout << sol << endl;
}