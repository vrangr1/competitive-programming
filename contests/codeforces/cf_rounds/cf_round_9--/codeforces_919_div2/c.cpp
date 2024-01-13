/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 13 20:36:00 IST 2024
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto process = [&a,&n](int k){
        int l = n/k, g = 0;
        rep(i,1,k-1,1){
            int s = i*l, cur = 0;
            rep(j,s,s+l-1,1){
                int diff = abs(a[j-s]-a[j]);
                if (!cur) cur = diff;
                else if (diff) cur = gcd(cur,diff);
            }
            if (!cur) continue;
            if (!g) g = cur;
            else g = gcd(g,cur);
            if (g == 1) return false;
        }
        return true;
    };
    int pt = 0;
    rep(i,1,n,1){
        if (n%i) continue;
        pt += process(i);
    }
    cout << pt << endl;
}

/*

8

1
4
1 2 1 4

1
3
1 2 3

1
5
1 1 1 1 1


6
1 3 1 1 3 1
6
6 2 6 2 2 2
6
2 6 3 6 6 6
10
1 7 5 1 4 3 1 3 1 4
1
1




*/