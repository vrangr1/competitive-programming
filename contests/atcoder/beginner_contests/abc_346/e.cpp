/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 23 18:22:30 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
    ll h, w, m; cin >> h >> w >> m;
    vector<ll> cols(w,0), rows(h,0);
    vector<ll> colsts(w,0), rowsts(h,0);
    rep(i,m){
        ll t, a, x; cin >> t >> a >> x; --a;
        if (t == 1){
            rows[a] = x;
            rowsts[a] = i+1;
        }
        else{
            cols[a] = x;
            colsts[a] = i+1;
        }
    }
    vector<ll> corder(w), rorder(h);
    iota(all(corder),0);
    iota(all(rorder),0);
    sort(all(corder),[&](const ll &i, const ll &j){
        return colsts[i] < colsts[j];
    });
    sort(all(rorder),[&](const ll &i, const ll &j){
        return rowsts[i] < rowsts[j];
    });
    vector<ll> rhinder(h,0), chinder(w,0);
    auto get_hinder = [&](ll ts, ll color, bool row = true) -> ll {
        
    };
    rep(row, h){
        ll ts = rowsts[row];

    }
    map<ll,ll> rct, cct;
    set<ll> colors;
    rep(i,w){
        cct[cols[i]]++;
        colors.insert(cols[i]);
    }
    rep(i,h){
        rct[rows[i]]++;
        colors.insert(rows[i]);
    }
    ll k = sz(colors);
    cout << k << endl;
    auto get = [&](ll color) -> ll {
        ll r;
        if (rct.find(color) != rct.end())
            r = rct[color];
        else r = 0;
        ll sol = r*w;
        ll c;
        if (cct.find(color) != cct.end())
            c = cct[color];
        else c = 0;
        sol += ((c*h)-(c*r));
        return sol;
    };
    for (ll color : colors){
        cout << color << " " << get(color) << endl;
    }
}