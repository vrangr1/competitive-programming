/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Apr  6 17:38:34 IST 2024
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
#define yes "Yes\n"
#define no "No\n"
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

#define emt '.'
#define block '#'

const vector<int> dirx = {-1,1,0,0};
const vector<int> diry = {0,0,-1,1};

void solve1(){
    int h, w; cin >> h >> w;
    vector<string> grid(h,string(w,'-'));
    pair<int,int> src, dest;
    rep(i,h){
        cin >> grid[i];
        rep(j,w){
            if (grid[i][j] == 'S'){
                src.first = i;
                src.second = j;
            }
            else if (grid[i][j] == 'T'){
                dest.first = i;
                dest.second = j;
            }
        }
    }
    vector<vector<int>> med(h,vector<int>(w,0));
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> pts = {src,dest};
    int ct = 0;
    mp[src] = ct++;
    mp[dest] = ct++;
    int n; cin >> n;
    rep(i,n){
        int r, c; cin >> r >> c; --r;--c;
        pair<int,int> pt = {r,c};
        int e; cin >> e;
        med[r][c] = e;
        if (pt != src && pt != dest){
            mp[pt] = ct++;
            pts.emplace_back(r,c);
        }
    }
    assert(sz(pts) == ct);
    vector<vector<int>> scost(h,vector<int>(w,INT_MAX)), tcost(h,vector<int>(w,INT_MAX));
    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < h && y < w;
    };
    auto comp = [&](int sx, int sy, vector<vector<int>> &cost) -> vector<int> {
        queue<pair<int,int>> q;
        q.emplace(sx,sy);
        vector<vector<bool>> vis(h,vector<bool>(w,false));
        vis[sx][sy] = true;
        cost[sx][sy] = 0;
        vector<int> inds;
        int dist = -1;
        while(!q.empty()){
            int len = sz(q);
            dist++;
            while(len--){
                auto [x,y] = q.front();
                q.pop();
                assert(vis[x][y]);
                assert(valid(x,y));
                rep(d,4){
                    int nx = x+dirx[d], ny = y+diry[d];
                    if (!valid(nx,ny) || vis[nx][ny] || grid[nx][ny] == block) continue;
                    cost[nx][ny] = dist;
                    vis[nx][ny] = true;
                    q.emplace(nx,ny);
                    if (mp.find({nx,ny}) != mp.end())
                        inds.push_back(mp[{nx,ny}]);
                }
            }
        }
        return inds;
    };
    vector<int> sinds = comp(src.first,src.second, scost);
    if (find(all(sinds),1) == sinds.end()) return void(cout << no);
    if (med[src.first][src.second] >= scost[dest.first][dest.second]) return void(cout << yes);
    vector<int> tinds = comp(dest.first,dest.second, tcost);
    assert(find(all(tinds),0) != tinds.end());
    {
        vector<int> inds;
        for (int ind : sinds){
            if (ind <= 1) continue;
            if (scost[pts[ind].first][pts[ind].second] > med[src.first][src.second])
                continue;
            inds.push_back(ind);
        }
        swap(sinds,inds);
    }
    {
        vector<int> inds;
        for (int ind : tinds){
            if (ind <= 1) continue;
            if (tcost[pts[ind].first][pts[ind].second] > med[pts[ind].first][pts[ind].second])
                continue;
            inds.push_back(ind);
        }
        swap(tinds,inds);
    }
    sort(all(sinds));
    sort(all(tinds));
    vector<int> its(max(sz(sinds),sz(tinds)));
    auto itend = set_intersection(all(sinds),all(tinds),its.begin());
    its.erase(itend,its.end());
    if (!its.empty()) return void(cout << yes);


    
}

void solve(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    pair<int,int> src(-1,-1), dest(-1,-1);
    rep(i,h){
        cin >> grid[i];
        rep(j,w)
            if (grid[i][j] == 'S') src = {i,j};
            else if (grid[i][j] == 'T') dest = {i,j};
    }
    assert(src.first != -1 && dest.first != -1);
    int n; cin >> n;
    vector<vector<int>> med(h,vector<int>(w,0));
    rep(i,n){
        int r, c; cin >> r >> c; --r;--c;
        cin >> med[r][c];
    }
    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < h && y < w;
    };
    auto bfs = [&]() -> bool {
        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(h,vector<int>(w,-1));
        auto [sx, sy] = src;
        vis[sx][sy] = med[sx][sy];
        q.emplace(sx,sy,med[sx][sy]);
        while(!q.empty()){
            int len = sz(q);
            while(len--){
                auto [x, y, engy] = q.front();
                debug(x,y,engy,endl);
                q.pop();
                assert(engy >= 0);
                if (engy == 0) continue;
                --engy;
                rep(d,4){
                    int nx = x+dirx[d], ny = y+diry[d];
                    if (!valid(nx,ny) || grid[nx][ny] == block) continue;
                    int cur = max(engy,med[nx][ny]);
                    if (vis[nx][ny] >= cur) continue;
                    if (dest.first == nx && dest.second == ny)
                        return true;
                    q.emplace(nx,ny,cur);
                    vis[nx][ny] = cur;
                }
            }
        }
        return false;
    };
    if (bfs()) cout << yes;
    else cout << no;
}