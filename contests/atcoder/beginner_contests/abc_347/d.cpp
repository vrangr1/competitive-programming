/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 17:57:13 IST 2024
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
    ll a, b, c; cin >> a >> b >> c;
    ll cp = __builtin_popcountll(c);
    if (a+b == cp){
        ll ct = 0;
        ll sa = 0, sb = 0;
        while(c){
            ll bit = (c&(-c));
            if (ct < a){
                sa += bit;
                ct++;
            }
            else{
                sb += bit;
            }
            c -= bit;
        }
        cout << sa << " " << sb << endl;
        return;
    }
    if (a+b < cp || (a+b-cp)%2ll) return void(cout << "-1\n");
    ll rem = (a+b-cp)/2ll, com = 0ll, ct = 0ll, sa = 0ll, sb = 0ll;
    if (60ll-cp < rem || a < rem || b < rem) return void(cout << "-1\n");
    rep(i,60ll){
        ll bit = (1ll<<i);
        if (bit&c){
            if (ct < a-rem){
                sa += bit;
                ct++;
            }
            else sb += bit;
            continue;
        }
        if (com < rem){
            com++;
            sa += bit;
            sb += bit;
        }
    }
    cout << sa << " " << sb << endl;
}