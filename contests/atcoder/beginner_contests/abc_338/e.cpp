/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 27 18:31:51 IST 2024
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
    int n; cin >> n;
    vector<int> edge(2*n,-1);
    vector<bool> vis(2*n,false);
    rep(i,n){
        int a, b; cin >> a >> b;
        --a;--b;
        assert(edge[a] == -1 && edge[b] == -1);
        edge[a] = b;
        edge[b] = a;
    }
    int m = 2*n;
    assert(*min_element(all(edge)) != -1);
    auto iscontained = [&](auto &&self, int a, int b) -> bool {
        debug(a,b);
        assert(!vis[a]);
        vis[a] = true;
        if (a == b) return false;
        if ((abs(a-b)+1)%2) return false;
        if (b == (a+1)%m) return edge[a] == b;
        if (edge[a] == (a+1)%m) return self(self,(a+2)%m,b);
        if (edge[a] == b)
            return self(self,(a+1)%m, (b-1+m)%m);
        int ea = edge[a];
        assert(a != (ea+1)%m);
        if (a < b && (ea < a || ea > b)) return false;
        // if (a > b && ())
        return self(self,(a+1)%m, (ea-1+m)%m) && self(self,(ea+1)%m,b);
    };
    if (iscontained(iscontained,0,m-1)) cout << no;
    else cout << yes;
}

/*

8
10 1
13 2
14 3
7 4
6 5
9 8
12 11
16 15




6
12 1
7 2
8 3
9 4
10 5
11 6

*/