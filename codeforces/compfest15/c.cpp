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

const ll mod = 998244353;

void solve(){
    int n; cin >> n;
    vector<vector<pair<int,ll>>> edges(n);
    int s;
    rep(i,n){
        cin >> s;
        edges[i].resize(s);
        rep(j,s){
            cin >> edges[i][j].first >> edges[i][j].second;
            edges[i][j].first--;
        }
    }
    vector<vector<ll>> vals(n,vector<ll>(3,0));
    vector<bool> vis(n,false);
    auto dfs = [&](auto self, int node) -> void{
        vis[node] = true;
        assert(vals[node][0] == vals[node][1] && vals[node][0] == vals[node][2] && vals[node][0] == 0);
        for (auto &pr : edges[node]){
            if (!vis[pr.first])
                self(self, pr.first);
            if (pr.second == 0){
                vals[node][2] += vals[node][1];
                vals[node][2] %= mod;
                vals[node][2] += (vals[pr.first][0]*vals[node][1])%mod;
                vals[node][2] %= mod;
                vals[node][0]++;
                vals[node][0] %= mod;
            }
            else{
                vals[node][1]++;
                vals[node][1] %= mod;
                vals[node][2] += (vals[pr.first][0]*vals[node][1])%mod;
                vals[node][2] %= mod;
            }
            vals[node][2] += vals[pr.first][2];
            vals[node][2] %= mod;
            vals[node][0] = (vals[node][0] + vals[pr.first][0])%mod;
            vals[node][1] = (vals[node][1] + vals[pr.first][1])%mod;
        }
    };
    dfs(dfs,0);
    cout << vals[0][2] << endl;
}