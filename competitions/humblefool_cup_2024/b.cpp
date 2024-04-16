/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Apr 16 20:04:05 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // int sol = (1<<30)-1, coins = 0;
    // rep(i,n) sol&=a[i];
    // auto proc = [&sol,&coins,n](int bit, vector<int> a) -> bool {
    //     int val = (1<<bit);
    //     int cost = 0, cur;
    //     if (((a.front()&val)==0) && ((a.back()&val)==0)) return false;
    //     cur = ((1<<30)-1);
    //     while(!a.empty() && (a.back()&val)){
    //         cur&=a.back();
    //         a.pop_back();
    //         cost++;
    //     }
    //     reverse(all(a));
    //     while(!a.empty() && (a.back()&val)){
    //         cur&=a.back();
    //         a.pop_back();
    //         cost++;
    //     }
    //     cost = n-cost;
    //     if (bit == 1) debug(cur,cost);
    //     if (cur > sol && cost != n){
    //         sol = cur;
    //         coins = cost;
    //     }
    //     else if (cost != n && cur == sol && cost < coins){
    //         coins = cost;
    //     }
    //     return true;
    // };
    [[maybe_unused]] int l = n-1, r = 0, sol = 0, cost = 0;
    rep(bit,29,0,-1){
        int val = (1<<bit);
        if ((val&a.front())==0 && ((val&a.back()) == 0)) continue;
        int cl = -1;
        rep(i,l+1){
            if ((a[i]&val) == 0) break;
            cl = i;
        }
        int cr = n;
        rep(i,n-1,r,-1){
            if ((a[i]&val) == 0) break;
            cr = i;
        }
        debug(bit,val,cl,cr,l,r,endl);
        if (l == -1 && cr == n) continue;
        if (r == n && cl == -1) continue;
        l = min(l,cl);
        r = max(cr,r);
        if (l == -1 && r == n) break;
        if (l >= 0 || r <= n-1){
            sol += val;
            cost = max(r-l-1,0);
        }
    }
    debug(sol);
    cout << cost << endl;
}

/*

5

1
10

1
4
1 2 3 4

1
6
6 7 2 3 1 3
6
6 14 2 3 7 6
3
3 3 3



*/