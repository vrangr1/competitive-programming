/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 18:44:32 IST 2023
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

const ll mod = 998244353ll;

ll inv(ll n){
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*(inv(mod%n)))%mod;
}

const ll p = 1001ll;

ll get_ind(ll x, ll y){
    return x*p + y;
}

class DSU{
private:
    vector<ll> parent, rank;
    ll n, ogcs;
public:
    ll compsize;
    DSU(ll gn, ll gcs):parent(gn,-1),rank(gn,0){
        this->n = gn;
        this->compsize = gcs;
        this->ogcs = gcs;
    }

    void rebuild(){
        fill(all(parent),-1);
        fill(all(rank),0);
        this->compsize = ogcs;
    }

    ll find(ll x){
        if (parent[x] == -1) return x;
        else return parent[x] = find(parent[x]);
    }

    void unite(ll x, ll y){
        ll px = this->find(x), py = this->find(y);
        if (px == py) return;
        compsize--;
        if (this->rank[px] < this->rank[py]){
            this->rank[px] = this->rank[py];
            this->parent[px] = py;
        }
        else if (this->rank[px] > this->rank[py]){
            this->rank[py] = this->rank[px];
            this->parent[py] = px;
        }
        else{
            this->rank[px] = ++this->rank[py];
            this->parent[px] = py;
        }
    }
};

const char red = '.', green = '#';
const vector<ll> dx = {-1,0,0,1};
const vector<ll> dy = {0,-1,1,0};

void solve(){
    ll h, w; cin >> h >> w;
    [[maybe_unused]] ll rct = 0ll, gct = 0ll;
    vector<string> grid(h);
    vector<vector<bool>> crucial(get_ind(h,w),vector<bool>(4,false));
    rep(i,h) cin >> grid[i];
    rep(i,h){
        rep(j,w){
            if (grid[i][j] == red) ++rct;
            else gct++;
        }
    }
    DSU dsu(get_ind(h,w),gct);
    auto valid = [&](ll i, ll j) -> bool {
        return (i >= 0ll && i < h && j >= 0ll && j < w);
    };
    rep(i,h){
        rep(j,w){
            if (grid[i][j] != green) continue;
            rep(k,2,3ll,1){
                ll nx = i+dx[k], ny = j+dy[k];
                if (!valid(nx,ny) || grid[nx][ny] != green) continue;
                ll src = get_ind(i,j), dest = get_ind(nx,ny);
                if (dsu.find(src) == dsu.find(dest)) continue;
                crucial[src][k] = true;
                dsu.unite(src,dest);
                // dsu.unite(get_ind(i,j),get_ind(nx,ny));
            }
        }
    }
    dsu.rebuild();
    rep(i,h-1ll,0ll,-1ll){
        rep(j,w-1ll,0ll,-1ll){
            if (grid[i][j] != green) continue;
            rep(k,0,1ll,1){
                ll nx = i+dx[k], ny = j+dy[k];
                if (!valid(nx,ny) || grid[nx][ny] != green) continue;
                ll src = get_ind(i,j), dest = get_ind(nx,ny);
                if (dsu.find(src) == dsu.find(dest)) continue;
                crucial[src][k] = true;
                dsu.unite(src,dest);
                // dsu.unite(get_ind(i,j),get_ind(nx,ny));
            }
        }
    }
    ll exp = 0ll;
    auto oppdir = [](const ll dir) -> ll {
        switch(dir){
            case 0: return 3;
            case 1: return 2;
            case 2: return 3;
            case 3: return 0;
        }
        assert(false);
        return -1;
    };
    rep(i,h){
        rep(j,w){
            if (grid[i][j] == red) continue;
            ll ct = 0ll, e = 0ll;
            rep(k,4){
                ll nx = i+dx[k], ny = j+dy[k];
                if (!valid(nx,ny) || grid[nx][ny] != green) continue;
                e++;
                ll src = get_ind(i,j), dest = get_ind(nx,ny);
                if (crucial[src][k] && crucial[dest][oppdir(k)])
                    ct++;
            }
            if (e == 0ll){
                exp += dsu.compsize-1ll;
                exp %= mod;
                continue;
            }
            else if (ct == 0ll){
                exp += dsu.compsize;
                exp %= mod;
                continue;
            }
            else if (ct == 1ll){
                exp += dsu.compsize+1ll;
                exp %= mod;
                continue;
            }
            exp += dsu.compsize + 1ll;
            exp %= mod;
        }
    }
    exp *= inv(gct);
    exp %= mod;
    cout << exp << endl;
}