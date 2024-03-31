/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 20:32:57 IST 2024
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
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> v(x);
    rep(i,x) cin >> v[i];
    sort(all(v));
    ll sol = 0ll, sy = y;
    if (x+y == n) return void(cout << n-2ll << endl);
    if (x+y == n-1ll) return void(cout << n-2ll << endl);
    if (x+y == 2ll){
        assert(x==2ll);
        sol = (v[1]==v[0]+2ll) + (v[0]-1ll+n-v[1]+1ll == 2ll);
        cout << sol << endl;
        return;
    }
    vector<ll> diffs,best;
    rep(i,x-1ll){
        ll d = v[i+1]-v[i];
        if (d == 1){
            // sol--;
            continue;
        }
        if (d == 2){
            sol++;
            continue;
        }
        if (d%2ll == 0ll){
            best.push_back(d);
        }
        else diffs.push_back(d);
    }
    {
        ll d = v.front()-1ll+n-v.back()+1ll;
        if (d == 2ll) sol++;
        else if (d%2ll == 0ll) best.push_back(d);
        else if (d > 1ll) diffs.push_back(d);
    }
    sort(rall(best));
    sort(rall(diffs));
    while(y > 0 && !best.empty()){
        ll d = best.back();
        best.pop_back();
        d>>=1ll;
        if (y >= d-1ll){
            sol += d;
            y-=d-1ll;
            continue;
        }
        sol += y;
        y = 0ll;
    }
    while(y > 0 && !diffs.empty()){
        ll d = diffs.back();
        diffs.pop_back();
        d--;
        d>>=1ll;
        if (y >= d){
            sol += d;
            y-=d;
            continue;
        }
        sol += y;
        y = 0;
    }
    debug(y);
    sol += (max(0ll,x+(sy-y)-2ll));
    cout << sol << endl;
}