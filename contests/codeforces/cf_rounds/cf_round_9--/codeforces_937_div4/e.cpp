/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Mar 28 20:33:02 IST 2024
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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<int> fst;
    auto get_facs = [&]() -> void {
        fst.insert(1);
        int sq = bsqrt(n);
        if (n%2 == 0){
            fst.insert(2);
            fst.insert(n/2);
        }
        rep(f,3,sq,1){
            if (n%f) continue;
            fst.insert(f);
            fst.insert(n/f);
        }
        fst.insert(n);
    };
    get_facs();
    vector<int> facs(all(fst));
    auto check = [&](int k) -> bool {
        assert(n%k == 0);
        int ct = 0, cur = 0;
        rep(i,k,n-1,k){
            cur = 0;
            rep(j,i,i+k-1,1){
                if (s[j] != s[j-i]) cur++;
            }
            if (cur > 1) return false;
            ct += cur;
        }
        if (ct <= 1) return true;
        if (ct != n/k - 1) return false;
        ct = 0;
        rep(i,0,n-k,k){
            cur = 0;
            rep(j,i,i+k-1,1)
                cur += (s[j] != s[j-i+n-k]);
            if (cur > 1) return false;
            ct += cur;
        }
        return ct <= 1;
    };
    for (int k : facs){
        assert(n%k == 0);
        if (!check(k)) continue;
        cout << k << endl;
        return;
    }
}