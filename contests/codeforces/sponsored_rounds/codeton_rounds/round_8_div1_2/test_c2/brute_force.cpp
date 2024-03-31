/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 21:31:06 IST 2024
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
    assert(x+y <= n);
    set<ll> st;
    rep(i,x){
        ll v; cin >> v;
        st.insert(v);
    }
    auto get = [](ll n, ll x, vector<ll> v) -> ll {
        sort(all(v));
        ll sol = max(0ll,(x-2));
        ll ct = 0ll;
        rep(i,x-1ll){
            ct += (v[i+1]-v[i] == 2ll);
        }
        if (v.front() - 1ll + n-v.back() + 1ll == 2ll) ct++;
        sol += ct;
        return sol;
    };
    vector<bool> choose(n,false);
    fill(choose.begin(), choose.begin()+x+y,true);
    reverse(all(choose));
    ll sol = 0ll;
    do{
        bool skip = false;
        vector<ll> v;
        rep(i,n){
            if (st.find(i+1ll) != st.end() && !choose[i]){
                skip = true;
                break;
            }
            if (choose[i]) v.push_back(i+1);
        }
        if (skip) continue;
        assert(sz(v) == x+y);
        sol = max(sol,get(n,x+y,v));
    }while(next_permutation(all(choose)));
    cout << sol << endl;
}