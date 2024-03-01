/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar  1 21:43:07 IST 2024
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
    ll n; cin >> n;
    auto get = [](ll n) -> ll {
        return __builtin_popcountll(n);
    };
    bool wrong = false;
    auto proc = [&get,&wrong](ll n) -> void {
        assert(n > 0ll);
        ll ct = get(n);
        if (ct%2ll){
            ll p1 = (n&(-n)), p2 = (n^p1);
            if (p1 == 0ll || p2 == 0ll){
                cout << "0 0\n";
                cout.flush();
                wrong = true;
                return;
            }
            cout << p1 << " " << p2 << endl;
            cout.flush();
            return;
        }
        ll p1 = (n&(-n)), p2 = (n^p1);
        cout << p1 << " " << p2 << endl;
        cout.flush();
    };
    ll ct = __builtin_popcountll(n);
    ll p1, p2, p1ct,p2ct;
    auto check = [](ll p1, ll p2) -> bool {
        return p1 > 0ll && p2 > 0ll;
    };
    if (ct%2ll){
        cout << "second\n";
        cout.flush();
        cin >> p1 >> p2;
        while(check(p1,p2)){
            assert(p1 > 0ll && p2 > 0ll);
            p1ct = get(p1);
            p2ct = get(p2);
            assert(p1ct%2ll == 0ll || p2ct%2ll == 0ll);
            if (p1ct%2ll) swap(p1,p2);
            proc(p1);
            cin >> p1 >> p2;
        }
        return;
    }
    cout << "first\n";
    cout.flush();
    proc(n);
    cin >> p1 >> p2;
    while(check(p1,p2)){
        assert(p1 > 0ll && p2 > 0ll);
        p1ct = get(p1);
        p2ct = get(p2);
        assert(p1ct%2ll == 0ll || p2ct%2ll == 0ll);
        if (p1ct%2ll) swap(p1,p2);
        proc(p1);
        cin >> p1 >> p2;
    }
    return;
}