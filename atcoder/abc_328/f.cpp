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
    vector<ll> parent, rank;
    DSU(ll n) : parent(n,-1),rank(n,0){}

    ll find(ll x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(ll x, ll y){
        ll px = find(x), py = find(y);
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
    ll n, q; cin >> n >> q;
    vector<ll> x(n,LLONG_MIN);
    vector<ll> soln;
    DSU dsu(n);
    rep(i,1ll,q,1ll){
        ll a, b, d; cin >> a >> b >> d; --a; --b;
        if (a == b && d != 0) continue;
        if (a == b && d == 0){
            soln.push_back(i);
            continue;
        }
        if (dsu.find(a) != dsu.find(b)){
            dsu.unite(a,b);
            if (x[a] == LLONG_MIN && x[b] == LLONG_MIN){
                x[b] = 0;
                x[a] = d;
                soln.push_back(i);
                continue;
            }
            else if (x[a] == LLONG_MIN || x[b] == LLONG_MIN){
                if (x[a] != LLONG_MIN){
                    x[b] = x[a] - d;
                }
                else
                    x[a] = x[b] + d;
                soln.push_back(i);
            }
            else{
                if (x[a] - x[b] != d) continue;
                soln.push_back(i);
            }
            x[b] = 0;
            x[a] = d;
            soln.push_back(i);
            continue;
        }
        else if (x[a] == LLONG_MIN || x[b] == LLONG_MIN){
            if (x[a] != LLONG_MIN){
                x[b] = x[a] - d;
            }
            else
                x[a] = x[b] + d;
            soln.push_back(i);
        }
        else{
            if (x[a] - x[b] != d) continue;
            soln.push_back(i);
        }
    }
    print_vec(soln);
    if (sz(soln) == 0) cout << endl;
}