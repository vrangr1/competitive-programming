/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Apr  8 20:15:32 IST 2024
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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    map<int,int> bmp, amp, ump;
    rep(i,m) bmp[b[i]]++;
    int sum = 0;
    rep(i,m){
        amp[a[i]]++;
        if (bmp[a[i]] == 0) continue;
        ump[a[i]]++;
        sum++;
        bmp[a[i]]--;
    }
    int sol = (sum>=k);
    rep(i,m,n-1,1){
        amp[a[i-m]]--;
        if (ump[a[i-m]]){
            ump[a[i-m]]--;
            sum--;
            bmp[a[i-m]]++;
            if (amp[a[i-m]] > ump[a[i-m]]){
                bmp[a[i-m]]--;
                ump[a[i-m]]++;
                sum++;
            }
        }

        amp[a[i]]++;
        if (bmp[a[i]]){
            bmp[a[i]]--;
            ump[a[i]]++;
            sum++;
        }

        sol += (sum >= k);
    }
    cout << sol << endl;
}

/*

1
11 5 3
9 9 2 2 10 9 7 6 3 6 3
6 9 7 8 10

n = 11, m = 5, k = 3

9 9 2 2 10 9 7 6 3 6 3

6 7 8 9 10

*/