/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 15 20:18:31 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const vector<int> dirx = {1,0,0,-1};
const vector<int> diry = {0,1,-1,0};

void solve(){
    int n; cin >> n;
    vector<string> grid(2);
    cin >> grid[0] >> grid[1];
    vector<vector<bool>> vis(2,vector<bool>(n,false));
    queue<pair<int,int>> q;
    q.emplace(0,0);
    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x < 2 && y >= 0 && y < n;
    };
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        // debug(x,y);
        assert(valid(x,y));
        rep(dir, 4){
            int nx = x+dirx[dir], ny = y+diry[dir];
            if (!valid(nx,ny) || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            if (grid[nx][ny] == '>') ny++;
            else ny--;
            if (nx == 1 && ny == n-1) return void(cout << yes);
            assert(valid(nx,ny));
            q.emplace(nx,ny);
        }
    }
    cout << no;
}
/*
4

1
4
>><<
>>><

2
><
><
4
>>><
>><<
6
>><<><
><>>><



*/