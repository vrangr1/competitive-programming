/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
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
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define qwe(r,t,y)
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class DSU{
public:
    vector<i128> parent, rank;
    DSU(i128 n) : parent(n,-1), rank(n,0){}

    i128 find(i128 x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(i128 x, i128 y){
        i128 px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]){
            rank[px] = rank[py];
            parent[px] = py;
        }
        else if (rank[px] > rank[py]){
            rank[py] = rank[px];
            parent[py] = px;
        }
        else{
            rank[px] = ++rank[py];
            parent[px] = py;
        }
    }
};

void solve(){
    ll n1, m1, k1; cin >> n1 >> m1 >> k1;
    i128 n, m, k; n = n1; m = m1; k = k1;
    auto comp = [](const vector<i128> &a, const vector<i128> &b){
        return a[0] > b[0];
    };
    // priority_queue<vector<i128>, vector<vector<i128>>, decltype(comp)> pq(comp);
    multiset<vector<i128>, decltype(comp)> mset(comp);
    rep(i,m){
        ll u, v, w; cin >> u >> v >> w;
        --u; --v;
        mset.insert({w%k, u, v});
        // pq.push({w%k, u, v});
    }

    auto mst = [&](){
        DSU dsu(n);
        i128 mstw = 0;
        i128 sw, su, sv, lw, lu, lv;
        while(!mset.empty()){
            if (sz(mset) == 1){
                sw = mset.begin()->at(0);
                su = mset.begin()->at(1);
                sv = mset.begin()->at(2);
                mset.erase(mset.begin());
                if (dsu.find(su) == dsu.find(sv)) continue;
                mstw += sw;
                mstw %= k;
                continue;
            }
            sw = mset.begin()->at(0);
            su = mset.begin()->at(1);
            sv = mset.begin()->at(2);
            if (dsu.find(su) == dsu.find(sv)){
                mset.erase(mset.begin());
                continue;
            }
            auto it = mset.lower_bound({k-mstw,-1,-1});
            if (it == mset.end()){
                mset.erase(mset.begin());
                if (dsu.find(su) == dsu.find(sv)) continue;
                mstw += sw;
                mstw %= k;
                continue;
            }
            lw = it->at(0);
            lu = it->at(1);
            lv = it->at(2);
            if (dsu.find(lu) == dsu.find(lv)){
                mset.erase(it);
                continue;
            }
            if ((mstw+sw)%k <= (mstw+lw)%k){
                mset.erase(mset.begin());
                mstw += sw;
                mstw %= k;
                continue;
            }
            mset.erase(it);
            mstw += lw;
            mstw %= k;
        }
        // while(!pq.empty()){
        //     i128 w = pq.top().at(0);
        //     i128 u = pq.top().at(1);
        //     i128 v = pq.top().at(2);
        //     pq.pop();
        //     if (dsu.find(u) == dsu.find(v)) continue;
        //     dsu.unite(u,v);
        //     mstw += w;
        //     mstw %= k;
        // }
        return mstw%k;
    };
    cout << (ll)mst() << endl;
}