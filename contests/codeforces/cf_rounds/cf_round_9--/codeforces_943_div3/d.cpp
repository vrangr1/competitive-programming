/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May  2 20:31:37 IST 2024
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
    ll n, k, b, s; cin >> n >> k >> b >> s; --b;--s;
    vector<ll> p(n), a(n);
    rep(i,n){
        cin >> p[i];
        --p[i];
    }
    rep(i,n) cin >> a[i];
    auto get = [&](ll ind) -> ll {
        ll sum = 0, mx = 0, mv = 0, mxmv = 0, mxsum = 0;
        vector<bool> vis(n,false);
        ll sol = 0ll;
        while(mv < k && !vis[ind]) {
            if (a[ind] > mx) {
                mx = a[ind];
                mxmv = mv;
                mxsum = sum;
            }
            sol = max(sol,sum + a[ind]*(k-mv));
            sum += a[ind];
            vis[ind] = true;
            ind = p[ind];
            mv++;
        }
        return sol;
    };
    ll bval = get(b), sval = get(s);
    if (bval == sval) cout << "Draw\n";
    else if (bval > sval) cout << "Bodya\n";
    else cout << "Sasha\n";
}

/*

10

4 2 3 2
4 1 2 3
7 2 5 6

10 8 2 10
3 1 4 5 2 7 8 10 6 9
5 10 5 1 3 7 10 15 4 3

2 1000000000 1 2
1 2
4 4

8 10 4 1
5 1 4 3 2 8 6 7
1 1 2 1 2 100 101 102

5 1 2 5
1 2 4 5 3
4 6 9 4 2
4 2 3 1
4 1 3 2
6 8 5 3
6 9 5 4
6 1 3 5 2 4
6 9 8 9 5 10
4 8 4 2
2 3 4 1
5 2 8 7
4 2 3 1
4 1 3 2
6 8 5 3
2 1000000000 1 2
1 2
1000000000 2




6 9 5 4
6 1 3 5 2 4
6 9 8 9 5 10
*/