/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

#define up 0
#define left 1
#define down 2
#define right 3

void solve(){
    ll n, k; cin >> n >> k;
    ll maxx = LLONG_MIN, minx = LLONG_MAX, maxy = LLONG_MIN, miny = LLONG_MAX;
    unordered_map<ll,ll> xcts, ycts;
    ll x, y;
    rep(i,n){
        cin >> x >> y;
        maxx = max(maxx,x);
        minx = min(minx,x);
        maxy = max(maxy,y);
        miny = min(miny,y);
        xcts[x]++;
        ycts[y]++;
    }
    ll sol = max(maxx-minx,maxy-miny);
    ll moves = 0ll;
    while(maxy - miny > maxx - minx){
        if (ycts[maxy] <= ycts[miny]){
            moves += ycts[maxy];
            ycts[maxy-1ll] += ycts[maxy];
            ycts[maxy] = 0ll;
            --maxy;
            if (moves > k) return void(cout << sol << endl);
            sol = max(maxx-minx,maxy-miny);
            continue;
        }
        moves += ycts[miny];
        ycts[miny+1ll] += ycts[miny];
        ycts[miny] = 0ll;
        ++miny;
        if (moves > k) return void(cout << sol << endl);
        sol = max(maxx-minx,maxy-miny);
    }
    while(maxx - minx > maxy-miny){
        if (xcts[maxx] <= xcts[minx]){
            moves += xcts[maxx];
            xcts[maxx-1ll] += xcts[maxx];
            xcts[maxx] = 0ll;
            --maxx;
            if (moves > k) return void(cout << sol << endl);
            sol = max(maxx-minx,maxy-miny);
            continue;
        }
        moves += xcts[minx];
        xcts[minx+1ll] += xcts[minx];
        xcts[minx] = 0ll;
        ++minx;
        if (moves > k) return void(cout << sol << endl);
        sol = max(maxx-minx,maxy-miny);
    }
    assert(moves <= k);
    if (moves == k) return void(cout << sol << endl);
    while(moves <= k){
        sol = max(maxx-minx,maxy-miny);
        ll cdir = -1, cct = LLONG_MAX, ct;
        rep(dir,4){
            ct = moves;
            switch(dir){
                case up:
                    ct += ycts[maxy];
                    ct += xcts[minx];
                    break;
                case left:
                    ct += xcts[minx];
                    ct += ycts[miny];
                    break;
                case down:
                    ct += ycts[miny];
                    ct += xcts[maxx];
                    break;
                case right:
                    ct += xcts[maxx];
                    ct += ycts[maxy];
                    break;
            }
            if (cdir == -1){
                cdir = dir;
                cct = ct;
                continue;
            }
            if (cct > ct){
                cct = ct;
                cdir = dir;
            }
        }
        switch(cdir){
            case up:
                moves += ycts[maxy];
                ycts[maxy-1ll] += ycts[maxy];
                ycts[maxy] = 0ll;
                --maxy;
                moves += xcts[minx];
                xcts[minx+1ll] += xcts[minx];
                xcts[minx] = 0ll;
                ++minx;
                break;
            case left:
                moves += xcts[minx];
                xcts[minx+1ll] += xcts[minx];
                xcts[minx] = 0ll;
                ++minx;
                moves += ycts[miny];
                ycts[miny+1ll] += ycts[miny];
                ycts[miny] = 0ll;
                ++miny;
                break;
            case down:
                moves += ycts[miny];
                ycts[miny+1ll] += ycts[miny];
                ycts[miny] = 0ll;
                ++miny;
                moves += xcts[maxx];
                xcts[maxx-1ll] += xcts[maxx];
                xcts[maxx] = 0ll;
                --maxx;
                break;
            case right:
                moves += xcts[maxx];
                xcts[maxx-1ll] += xcts[maxx];
                xcts[maxx] = 0ll;
                --maxx;
                moves += ycts[maxy];
                ycts[maxy-1ll] += ycts[maxy];
                ycts[maxy] = 0ll;
                --maxy;
                break;
        }
    }
    cout << moves << endl;
    return;
}