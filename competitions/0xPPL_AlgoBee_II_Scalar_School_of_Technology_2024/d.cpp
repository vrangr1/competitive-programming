/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Apr 14 22:11:34 IST 2024
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

void solve(){
    int n; cin >> n;
    vector<int> c(n), a(n);
    rep(i,n){
        cin >> c[i];
        --c[i];
    }
    rep(i,n) cin >> a[i];
    vector<vector<int>> v(n);
    rep(i,n){
        v[c[i]].push_back(i);
    }
    rep(i,n)
        sort(rall(v[i]),[&](const int &i, const int &j){
            return a[i] < a[j];
        });
    {
        auto vcp = v;
        vector<int> b;
        rep(i,n){
            assert(!vcp[c[i]].empty());
            assert(vcp[c[i]].back() >= 0 && vcp[c[i]].back() < n);
            b.push_back(a[vcp[c[i]].back()]);
            vcp[c[i]].pop_back();
        }
        if (!is_sorted(all(b))) return void(cout << "-1\n");
    }
    vector<pair<int,int>> sol;
    auto process = [&](int color) -> void {
        int m = sz(v[color]);
        auto &vec = v[color];
        if (vec.empty()) return;
        sort(all(vec));
        debug(vec);
        vector<int> order(m);
        iota(all(order),0);
        stable_sort(all(order),[&](const int &i, const int &j){
            return a[vec[i]] < a[vec[j]];
        });
        debug(order);
        rep(i,m){
            if (i == order[i])
                continue;
            while(i != order[i]){
                sol.emplace_back(vec[order[i]],vec[order[order[i]]]);
                swap(order[i],order[order[i]]);
            }
        }
        rep(i,m) assert(i==order[i]);
    };
    rep(i,n) process(i);
    cout << sz(sol) << endl;
    for (auto [x, y] : sol)
        cout << x << " " << y << endl;
}