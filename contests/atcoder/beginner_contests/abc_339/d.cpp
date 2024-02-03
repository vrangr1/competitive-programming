/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Feb  3 17:58:45 IST 2024
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

#define none '.'
#define block '#'
#define player 'P'

const vector<int> dirx = {0,-1,0,1};
const vector<int> diry = {-1,0,1,0};

void solve1(){
    int n; cin >> n;
    vector<string> g(n);
    rep(i,n) cin >> g[i];
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    rep(i,n){
        rep(j,n){
            if (g[i][j] == player){
                if (x1 == -1){
                    x1 = i;
                    y1 = j;
                }
                else{
                    x2 = i;
                    y2 = j;
                }
            }
            if (x2!=-1) break;
        }
        if (x2!=-1)break;
    }
    vector<vector<int>> p1dists(n,vector<int>(n,INT_MAX)), p2dists(n,vector<int>(n,INT_MAX));
    vector<vector<int>> p1blk(n,vector<int>(n,false)), p2blk(n,vector<int>(n,false));
    auto valid = [&n](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };
    auto bfs = [&](int x, int y, vector<vector<int>> &dists, vector<vector<int>> &blk){
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        assert(g[x][y] == player);
        q.emplace(x,y);
        int dist = 1;
        vis[x][y] = true;
        dists[x][y] = 0;
        while(!q.empty()){
            int s = sz(q);
            while(s--){
                pair<int,int> pr = q.front();
                x = pr.first;
                y = pr.second;
                q.pop();
                rep(dir,4){
                    int nx = x+dirx[dir],ny=y+diry[dir];
                    if (!valid(nx,ny)) continue;
                    if (g[nx][ny] == block){
                        blk[x][y] = true;
                        continue;
                    }
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    dists[nx][ny] = dist;
                    q.emplace(nx,ny);
                }
            }
            dist++;
        }
    };
    bfs(x1,y1,p1dists,p1blk);
    bfs(x2,y2,p2dists,p2blk);
    int sol = INT_MAX;
    debug(g,x1,y1,x2,y2,p1dists,p2dists);
    debug(p1blk);
    rep(i,n){
        rep(j,n){
            assert(p1blk[i][j] == p2blk[i][j]);
            if (!p1blk[i][j] && !p2blk[i][j]){
                if (p1dists[i][j] != p2dists[i][j]) continue;
                sol = min(sol,p1dists[i][j]);
            }
            else{
                sol = min(sol,max(p1dists[i][j],p2dists[i][j]));
            }
        }
    }
    cout << sol << endl;
}

void solve(){
    int n; cin >> n;
    vector<string> g(n);
    rep(i,n) cin >> g[i];
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    rep(i,n){
        rep(j,n){
            if (g[i][j] == player){
                if (x1 == -1){
                    x1 = i;
                    y1 = j;
                }
                else{
                    x2 = i;
                    y2 = j;
                }
            }
            if (x2!=-1) break;
        }
        if (x2!=-1)break;
    }
    auto valid = [&n](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };
    vector<vector<int>> p1dists(n,vector<int>(n,INT_MAX)), p2dists(n,vector<int>(n,INT_MAX));
    vector<vector<int>> blk(n,vector<int>(n,false));
    auto valid = [&n](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };
    vector<vector<vector<int>>> p1steps(n,vector<vector<int>>(n)), p2steps(n,vector<vector<int>>(n));
    auto bfs = [&](int x, int y, vector<vector<int>> &dists, int sol = -1){
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        assert(g[x][y] == player);
        q.emplace(x,y);
        int dist = 1;
        vis[x][y] = true;
        dists[x][y] = 0;
        while(!q.empty()){
            int s = sz(q);
            while(s--){
                pair<int,int> pr = q.front();
                x = pr.first;
                y = pr.second;
                q.pop();
                rep(dir,4){
                    int nx = x+dirx[dir],ny=y+diry[dir];
                    if (!valid(nx,ny)) continue;
                    if (sol != -1){
                        
                    }
                    if (!blk[x][y] && g[nx][ny] == block){
                        blk[x][y] = true;
                        continue;
                    }
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    dists[nx][ny] = dist;
                    q.emplace(nx,ny);
                }
            }
            dist++;
        }
    };
}