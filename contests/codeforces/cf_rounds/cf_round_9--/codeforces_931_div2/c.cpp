/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar  1 20:23:09 IST 2024
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
    int n, m; cin >> n >> m;
    auto ask = [](int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        cout.flush();
        int d; cin >> d;
        return d;
    };
    auto write = [](int x, int y) -> void {
        cout << "! " << x << " " << y << endl;
        cout.flush();
    };
    int dist = ask(1,1);
    if (dist == 0){
        write(1,1);
        return;
    }
    int x0 = dist+1;
    if (x0 <= n){
        int dx = ask(x0,1);
        if (dx == 0){
            write(x0,1);
            return;
        }
        assert(x0+dx+1 >= dist+2);
        if (((x0+dx+1)-(dist+2))%2 == 0){
            int diff = ((x0+dx+1)-(dist+2))/2;
            if (x0-diff >= 1 && dx+1-diff >= 1 && dx+1-diff <= m){
                int check = ask(x0-diff,dx+1-diff);
                if (check == 0){
                    write(x0-diff,dx+1-diff);
                    return;
                }
            }
        }
    }
    else{
        x0 = n;
        int y0 = dist+2-n;
        assert(y0 <= m && y0 >= 1);
        int dx = ask(x0,y0);
        if (dx == 0){
            write(x0,y0);
            return;
        }
        assert(dist+2 >= x0-dx+y0);
        int diff = (dist+2-x0+dx-y0);
        if (diff%2 == 0){
            diff/=2;
            if (x0-dx+diff >= 1 && x0-dx+diff <= n && y0+diff <= m){
                int check = ask(x0-dx+diff,y0+diff);
                if (check == 0){
                    write(x0-dx+diff,y0+diff);
                    return;
                }
            }
        }
    }
    int y0 = dist+1;
    if (y0 <= m){
        x0 = 1;
        int dy = ask(x0,y0);
        if (dy == 0){
            write(x0,y0);
            return;
        }
        assert(1+dy+y0 >= dist+2);
        int diff = (1+dy+y0-dist-2);
        assert(diff%2 == 0);
        diff/=2;
        x0 = 1+dy-diff;
        y0 = y0-diff;
        assert(x0>=1 && x0 <= n && y0 >= 1 && y0 <= m);
        write(x0,y0);
        return;
    }
    assert(y0>m);
    y0 = m;
    x0 = dist+2-m;
    assert(x0 <= n && x0 >= 1);
    int dy = ask(x0,y0);
    if (dy == 0){
        write(x0,y0);
        return;
    }
    assert(dist+2 >= (x0+y0-dy));
    int diff = (dist+2)-(x0+y0-dy);
    assert(diff%2 == 0);
    diff/=2;
    write(x0+diff,y0-dy+diff);
}