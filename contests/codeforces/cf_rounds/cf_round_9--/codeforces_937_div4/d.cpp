/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Mar 28 20:24:35 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
#endif
// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1(){
    int n; cin >> n;
    vector<pair<int,int>> pfs;
    auto pf = [&pfs](int n) -> void {
        if (n == 1) return;
        int f = 2, ct = 0;
        while(n%f == 0){
            n/=f;
            ct++;
        }
        if (ct) pfs.emplace_back(f,ct);
        int sq = bsqrt(n);
        for(f=3;f<=sq; f+=2){
            if(n%f) continue;
            ct = 0;
            while(n%f == 0){
                n/=f;
                ct++;
            }
            pfs.emplace_back(f,ct);
        }
        if (n > 1) pfs.emplace_back(n,1);
    };
    pf(n);
    int ct = -1;
    debug(pfs);
    for (auto pr : pfs){
        if (pr.first == 2){
            ct = pr.second;
            continue;
        }
        if (pr.second == 5){
            if (ct != pr.second) return void(cout << no);
            continue;
        }
        
    }
    cout << yes;
}

const ll maxn = (ll)1e5+1;
vector<bool> check(maxn,false);

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    check[0] = check[1] = true;
    vector<ll> cur;
    auto chk = [](ll n) -> bool {
        while(n > 0){
            if (n%10ll >= 2) return false;
            n/=10ll;
        }
        return true;
    };
    auto prop = [&](ll n) -> void {
        for (ll v : cur){
            ll n2 = v*n;
            if (n2 >= maxn) break;
            check[n2] = true;
        }
    };
    rep(n,10ll,maxn-1ll,1ll){
        if (check[n]){
            cur.push_back(n);
            prop(n);
            continue;
        }
        if (chk(n)){
            check[n] = true;
            cur.push_back(n);
            prop(n);
        }
    }
}

void solve(){
    init();
    int n; cin >> n;
    if (check[n]) cout << yes;
    else cout << no;
}

/*

11
121
1
14641

1
12221

10110
100000
99
112
2024
12421
1001



*/