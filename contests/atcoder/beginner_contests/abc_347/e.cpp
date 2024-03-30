/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 30 18:13:05 IST 2024
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
    ll n, q; cin >> n >> q;
    vector<ll> ind(n+1,-1);
    vector<ll> psum(q,0);
    auto get = [&](ll i, ll j) -> ll {
        assert(i <= j);
        if (i) return psum[j]-psum[i-1ll];
        return psum[j];
    };
    set<ll> st;
    vector<ll> sol(n,0);
    rep(i,q){
        ll x; cin >> x;
        if (st.find(x) != st.end()){
            if (i) psum[i] = psum[i-1];
            assert(ind[x] != -1);
            sol[x-1] += get(ind[x],i);
            psum[i] += (ll)sz(st)-1ll;
            ind[x] = -1;
            st.erase(x);
        }
        else{
            st.insert(x);
            if (i) psum[i] = psum[i-1];
            psum[i] += (ll)sz(st);
            assert(ind[x] == -1);
            ind[x] = i;
        }
    }
    while(!st.empty()){
        ll x = *st.begin();
        assert(ind[x] != -1);
        sol[x-1] += get(ind[x],q-1);
        ind[x] = -1;
        st.erase(st.begin());
    }
    print_vec(sol);
}