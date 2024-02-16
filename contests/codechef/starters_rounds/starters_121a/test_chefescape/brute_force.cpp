/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

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
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class DSU{
private:
    const pair<ll,ll> null = {-1,-1};
    pair<ll,ll> get_parent(pair<ll,ll> pr){
        if (parent.find(pr) != parent.end()) return parent[pr];
        return parent[pr] = null;
    }
    ll get_rank(pair<ll,ll> pr){
        if (rank.find(pr) != rank.end()) return rank[pr];
        return rank[pr] = 0ll;
    }
public:
    map<pair<ll,ll>,pair<ll,ll>> parent;
    map<pair<ll,ll>,ll> rank;
    DSU(){
        parent.clear();
        rank.clear();
    }

    pair<ll,ll> find(pair<ll,ll> x){
        if (get_parent(x) == null) return x;
        else return parent[x] = find(parent[x]);
    }

    void unite(pair<ll,ll> x, pair<ll,ll> y){
        pair<ll,ll> px = find(x), py = find(y);
        if (px == py) return;
        if (get_rank(px) < get_rank(py)){
            parent[px] = py;
            rank[px] = rank[py];
        }
        else if (get_rank(px) > get_rank(py)){
            parent[py] = px;
            rank[py] = rank[px];
        }
        else{
            parent[px] = py;
            rank[px] = ++rank[py];
        }
    }
};

void solve(){
    ll n, m; cin >> n >> m;
    set<pair<ll,ll>> st;
    DSU dsu;
    auto valid = [&](ll x, ll y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };
    rep(i,m){
        ll x, y; cin >> x >> y;
        st.emplace(x,y);
    }
    pair<ll,ll> pr, src = {1,1}, dest = {n,n};
    rep(i,1,n,1){
        rep(j,1,n,1){
            if (valid(i,j+1)){
                pr = {i,j+1};
                if (st.find(pr) == st.end())
                    dsu.unite({i,j},pr);
            }
            if (valid(i+1,j)){
                pr = {i+1,j};
                if (st.find(pr) == st.end())
                    dsu.unite({i,j},pr);
            }
        }
    }
    if (dsu.find(src) == dsu.find(dest)) return void(cout << yes);
    cout << no;
}