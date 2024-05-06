/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat May  4 17:47:33 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
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
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class DSU {
public:
    ll n, ct;
    vector<ll> parent, rank;

    DSU(ll gn) : parent(gn,-1), rank(gn,0) {
        n = gn;
        ct = gn;
    }

    ll find(ll x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(ll x, ll y) {
        ll px = find(x), py = find(y);
        if (px == py) return;
        --ct;
        if (rank[px] > rank[py]) swap(px,py);
        parent[px] = py;
        if (rank[px] == rank[py]) ++rank[py];
    }
};

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<vector<ll>,ll>> ops(m);
    rep(i,m){
        ll k; cin >> k >> ops[i].second;
        ops[i].first.resize(k);
        rep(j,k){
            cin >> ops[i].first[j];
            ops[i].first[j]--;
        }
    }
    {
        DSU dsu(n);
        for(auto [st, c] : ops) {
            ll k = sz(st);
            rep(i,1,k-1ll,1)
                dsu.unite(st[0],st[i]);
        }
        if (dsu.ct != 1) return void(cout << "-1\n");
    }
    sort(all(ops),[](const pair<vector<ll>,ll> &a, const pair<vector<ll>,ll> &b) {
        return a.second < b.second;
    });
    DSU dsu(n);
    ll sol = 0ll;
    for (auto [st, c] : ops) {
        vector<ll> connect;
        set<ll> p;
        for(auto v : st) {
            ll vp = dsu.find(v);
            if (p.find(vp) == p.end()) {
                connect.push_back(v);
                p.insert(vp);
            }
        }
        sol += (ll)(sz(connect)-1ll)*c;
        rep(i,1,sz(connect)-1,1)
            dsu.unite(connect[0],connect[i]);
    }
    cout << sol << endl;
}