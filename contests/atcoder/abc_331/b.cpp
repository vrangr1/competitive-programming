/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  2 17:33:03 IST 2023
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
    int n, s, m, l; cin >> n >> s >> m >> l;
    int mn;
    if (n%6 == 0 && n%8 == 0 && n%12 == 0){
        mn = min((n/6)*s,(n/8)*m);
        mn = min(mn,(n/12)*l);
        cout << mn << endl;
        return;
    }
    mn = (n/6)*s + ((n%6)?s:0);
    int k = n/6, cur, cost, k2, temp, cur2;
    k+=2;
    rep(i,k){
        cost = i*s;
        cur = n-i*6;
        if (cur <= 0){
            mn = min(mn, cost);
            break;
        }
        k2 = cur/8;
        k2+=2;
        rep(j,k2){
            cur2 = cur - j*8;
            if (cur2 <= 0){
                temp = cost + (j*m);
                mn = min(mn,temp);
                break;
            }
            temp = cost + (j*m) + (cur2/12)*l + (cur2%12?l:0);
            mn = min(mn,temp);
        }
    }
    cout << mn << endl;
}