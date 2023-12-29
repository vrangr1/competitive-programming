/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec 28 20:27:13 IST 2023
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
    vector<vector<int>> p;
    rep(i,n){
        int a, b; cin >> a >> b;
        p.push_back({a,i,0});
        p.push_back({b,i,1});
    }
    sort(all(p),[](const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    });
    vector<ll> opens(n,-1ll),closes(n,-1ll);
    ll o = 0ll, c = 0ll, sol = 0ll;
    debug(p);
    rep(i,2*n){
        debug(i,o,c,p[i]);
        if (p[i][2] == 0){
            opens[p[i][1]] = o;
            closes[p[i][1]] = c;
            o++;
            debug(opens[p[i][1]]);
            debug(closes[p[i][1]],endl);
            continue;
        }
        assert(opens[p[i][1]] != -1ll);
        assert(closes[p[i][1]] != -1ll);
        debug(opens[p[i][1]]);
        debug(closes[p[i][1]],sol,'c');
        // sol += max((opens[p[i][1]] - (c-closes[p[i][1]])),0ll);
        ll ind = p[i][1];
        // sol += opens[ind] - closes[ind] - (c-closes[ind])
        debug(sol,endl);
        c++;
    }
    cout << sol << endl;
}

/*

5

1
2
2 3
1 4

1
6
2 6
3 9
4 5
1 8
7 10
-2 100


4
-10 10
-5 5
-12 12
-13 13
5
-4 9
-2 5
3 4
6 7
8 10
4
1 2
3 4
5 6
7 8




*/