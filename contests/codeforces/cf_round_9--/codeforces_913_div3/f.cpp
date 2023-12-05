/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec  5 21:09:18 IST 2023
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (is_sorted(all(a))) return void(cout << "0\n");
    if (is_sorted(rall(a))) return void(cout << "1\n");
    if (n == 1) return void(cout << "0\n");
    if (n == 2 && is_sorted(all(a))) return void(cout << "0\n");
    else if (n == 2){
        return void(cout << "1\n");
    }
    if (n == 3){
        vector<ll> og(all(a));
        ll sol = LLONG_MAX;
        rep(i,n){
            if (is_sorted(all(a))){
                sol = min(sol,i);
                break;
            }
            else if (is_sorted(rall(a))){
                sol = min(sol,i+1);
            }
            rotate(a.begin(),a.begin()+n-1,a.end());
        }
        reverse(all(og));
        rep(i,n) a[i] = og[i];
        rep(i,n){
            if (is_sorted(all(a))){
                sol = min(sol,i+1);
                break;
            }
            else if (is_sorted(rall(a))){
                sol = min(sol,i+2);
            }
            rotate(a.begin(),a.begin()+n-1,a.end());
        }
        if (sol == LLONG_MAX) return void(cout << "-1\n");
        cout << sol << endl;
        return;
    }
    ll inc = 0, dec = 0;
    rep(i,n-1){
        if (a[i] <= a[i+1]) inc++;
        else dec++;
    }
    debug(inc,dec);
    if (inc == 0) return void(cout << "1\n");
    if (dec == 0) return void(cout << "0\n");
    auto get_sol = [&](auto comp){
        // if (inc != 1 && dec != 1) return void(cout << "-1\n");
        if (inc != 1 && dec != 1) return LLONG_MAX;
        if (inc == 1){
            // if (a.back() < a.front()) return void(cout << "-1\n");
            if (a.back() < a.front()) return LLONG_MAX;
            ll ind = 0;
            while(ind < n-1){
                // if (a[ind] <= a[ind+1]) break;
                if (comp(a[ind],a[ind+1])) break;
                ind++;
            }
            assert(ind < n-1);
            return min((n-ind),ind+2ll);
            // cout << min((n-ind),ind+2) << endl;
            // return;
        }
        if (a.front() < a.back()) return LLONG_MAX;
        // if (a.front() < a.back()) return void(cout << "-1\n");
        ll ind = 0;
        while(ind < n-1){
            // if (a[ind] > a[ind+1]) break;
            if (!comp(a[ind],a[ind+1])) break;
            ind++;
        }
        assert(ind < n-1);
        // cout << min((n-ind-1),ind+3) << endl;
        return min((n-ind-1ll),ind+3ll);
    };
    auto c1 = [](ll p, ll q) -> bool {
        return p <= q;
    };
    auto c2 = [](ll p, ll q) -> bool {
        return p < q;
    };
    ll sol = get_sol(c1);
    inc = 0; dec = 0;
    rep(i,n-1){
        if (a[i] < a[i+1]) inc++;
        else dec++;
    }
    debug(inc,dec);
    sol = min(sol,get_sol(c2));
    if (sol == LLONG_MAX) return void(cout << "-1\n");
    cout << sol << endl;
}

/*


11


5
3 2 1 5 4

5
1 1 2 1 1

4
3 7 10 5

5
1 2 3 4 5

2
5 1


1
3
3 4 1



5
4 1 3 4 4
3
5 1 1

1
4
2 5 5 4

1
5
2 2 1 1 2

2
5 5




*/