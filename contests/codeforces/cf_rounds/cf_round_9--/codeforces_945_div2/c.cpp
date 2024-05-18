/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri May 17 20:25:59 IST 2024
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
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j) {
        return p[i] < p[j];
    });
    vector<int> sol(n,-1);
    const int t = 1-(order.front()%2);
    int cur = n;
    rep(i,n) {
        int ind = order[i];
        if (ind == 0 || ind == n-1) continue;
        if ((ind%2) == t) {
            sol[ind] = cur--;
        }
    }
    // if (sol[1] != -1) {
    //     if (cur+p[0] < sol[1]+p[1]) {
    //         sol[0] = cur--;
    //         sol[n-1] = cur--;
    //     }
    //     else {
    //         sol[n-1] = cur--;
    //         sol[0] = cur--;
    //     }
    // }
    // else {
    //     sol[0] = cur--;
    //     sol[n-1] = cur--;
    // }
    // assert(cur == n/2 - 1);
    assert(cur == n/2+1);
    cur = 1;
    rep(i,n-1,0,-1) {
        int ind = order[i];
        if (sol[ind] != -1) continue;
        sol[ind] = cur++;
    }
    print_vec(sol);
    if (DEBUG) {
        rep(i,n) {
            sol[i] += p[i];
        }
        int ct = 0;
        rep(i,1,n-2,1) {
            ct += (sol[i] > sol[i-1] && sol[i] > sol[i+1]);
        }
        debug(sol);
        assert(ct == (n-1)/2);
    }
}