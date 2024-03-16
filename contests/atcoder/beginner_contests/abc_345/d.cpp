/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 17:40:49 IST 2024
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

void solve(){
    int n, h, w; cin >> n >> h >> w;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    auto valid_pt = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < h && y < w;
    };
    auto is_prob = [&](const vector<vector<int>> &occ, pair<int,int> pt) -> bool {
        auto [x, y] = pt;
        if (!valid_pt(x,y)) return true;
        for (auto &tile : occ){
            int tx = tile[0], ty = tile[1], dx = tile[2], dy = tile[3];
            if (x == tx && y == ty) return true;
            if (x <= tx || y <= ty) continue;
            if (x <= tx+dx-1 && y <= ty+dy-1) return true;
        }
        return false;
    };
    auto get_start = [&](vector<vector<int>> &occ) -> pair<int,int> {
        pair<int,int> pt(0,0);
        if (!is_prob(occ,pt)) return pt;
        pt = {h,w};
        for (const auto &tile : occ){
            int tx = tile[0], ty = tile[1], dx = tile[2], dy = tile[3];
            if (!is_prob(occ,{tx+dx,ty})) pt = min(pt,{tx+dx,ty});
            if (!is_prob(occ,{tx,ty+dy})) pt = min(pt,{tx,dy+ty});
        }
        return pt;
    };
    auto is_inside = [&](int tx, int ty, int dx, int dy, int x, int y) -> bool {
        return x >= tx && x <= tx+dx-1 && y >= ty && y <= ty+dy-1;
    };
    auto tile_intersect = [&](int x1, int y1, int dx1, int dy1, int x2, int y2, int dx2, int dy2) -> bool {
        return is_inside(x1,y1,dx1,dy1,x2,y2) || is_inside(x1,y1,dx1,dy1,x2+dx2-1,y2) ||
            is_inside(x1,y1,dx1,dy1,x2,y2+dy2-1) || is_inside(x1,y1,dx1,dy1,x2+dx2-1,y2+dy2-1);
    };
    auto any_tile_intersect = [&](const vector<vector<int>> &occ, int x, int y, int dx, int dy) -> bool {
        for (auto &tile : occ)
            if (tile_intersect(tile[0],tile[1],tile[2],tile[3],x,y,dx,dy)){
                return true;
            }
        return false;
    };
    auto can_place = [&](int x, int y, int dx, int dy, const vector<vector<int>> &occ) -> bool {
        return valid_pt(x,y) && valid_pt(x+dx-1,y+dy-1) && (!any_tile_intersect(occ,x,y,dx,dy));
    };
    auto bf = [&](auto &&self, vector<vector<int>> &occ, int vis) -> bool {
        auto [x,y] = get_start(occ);
        debug(x,y,occ,vis);
        if (x == h && y == w){
            debug(true,endl);
            return true;
        }
        rep(i,n){
            if (vis&(1<<i)) continue;
            if (can_place(x,y,a[i],b[i],occ)){
                occ.push_back({x,y,a[i],b[i]});
                if (self(self,occ,vis|(1<<i))){
                    debug(true,endl);
                    return true;
                }
                occ.pop_back();
            }
            if (a[i] != b[i] && can_place(x,y,b[i],a[i],occ)){
                occ.push_back({x,y,b[i],a[i]});
                if (self(self,occ,vis|(1<<i))){
                    debug(true,endl);
                    return true;
                }
                occ.pop_back();
            }
        }
        debug(false,endl);
        return false;
    };
    vector<vector<int>> occ;
    if (bf(bf,occ,0)) cout << yes;
    else cout << no;
}