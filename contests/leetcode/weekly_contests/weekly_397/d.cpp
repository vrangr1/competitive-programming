/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun May 12 08:25:48 IST 2024
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

void solve1(){
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    if (is_sorted(all(a))) return void(print_vec(a));
    vector<int> src(n);
    for (int i = 0; i < n; ++i)
        src[a[i]] = i;
    vector<vector<int>> cycles;
    vector<bool> vis(n,false);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<int> cur;
        cur.push_back(i);
        vis[i] = true;
        int ind = i;
        while(!vis[src[ind]]) {
            ind = src[ind];
            cur.push_back(ind);
            vis[ind] = true;
        }
        cycles.push_back(cur);
    }
    debug(cycles);
    for (auto &c : cycles) {
        int m = (int)c.size();
        int v = c.front(), ind = 0;
        for (int i = 1; i < m; ++i)
            if (c[i] < v) {
                v = c[i];
                ind = i;
            }
        rotate(c.begin(),c.begin()+ind,c.end());
    }
    sort(all(cycles),[&](const vector<int> &a, const vector<int> &b) {
        return a.front() < b.front();
    });
    vector<int> sol;
    for (auto &c : cycles)
        sol.insert(sol.end(),all(c));
    print_vec(sol);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    if (is_sorted(all(a))) return void(print_vec(a));
    vector<int> src(n);
    for (int i = 0; i < n; ++i)
        src[a[i]] = i;
    int t = (1<<n)-1;
    vector<int> sol;
    int mncost = INT_MAX;
    auto rec = [&](auto &&self, int ind, int vis, int cost, vector<int> &ord) -> void {
        assert(ord.back() == ind);
        if ((int)ord.size() == n) {
            assert(vis == t);
            if (cost < mncost) {
                sol = ord;
                mncost = cost;
            }
            return;
        }
        vector<int> pos;
        for (int i = -1; i <= 1; ++i){
            if (ind+i < 0 || ind+i >= n) continue;
            int j = src[ind+i], bit = (1<<j);
            if (vis&bit) continue;
            pos.push_back(j);
        }
        sort(all(pos));
        for (int j : pos) {
            ord.push_back(j);
            self(self,j,(vis|(1<<j)),cost+abs(ind-a[j]), ord);
            ord.pop_back();
        }
        if (!sol.empty()) return;
        pos.clear();
        for (int dist = 2; dist < n && sol.empty(); ++dist) {
            if (ind+dist >= n && ind-dist < 0) break;
            pos.clear();
            if (ind-dist >= 0) {
                int j = src[ind-dist], bit = (1<<j);
                if ((vis&bit) == 0) {
                    pos.push_back(j);
                    // ord.push_back(j);
                    // self(self,j,(vis|bit),cost+abs(ind-a[j]),ord);
                    // ord.pop_back();
                }
            }
            if (ind+dist < n) {
                int j = src[ind+dist], bit = (1<<j);
                if ((vis&bit) == 0) {
                    pos.push_back(j);
                    // ord.push_back(j);
                    // self(self,j,(vis|bit),cost+abs(ind-a[j]),ord);
                    // ord.pop_back();
                }
            }
            sort(all(pos));
            for (int j : pos) {
                int bit = (1<<j);
                ord.push_back(j);
                self(self,j,(vis|bit),cost+abs(ind-a[j]),ord);
                ord.pop_back();
            }
        }
    };
    vector<int> ord = {0};
    rec(rec,0,1,0,ord);
    // assert(!sol.empty());
    print_vec(sol);
    debug(mncost);
}