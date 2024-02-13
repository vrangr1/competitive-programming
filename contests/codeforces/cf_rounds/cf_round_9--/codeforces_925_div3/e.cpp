/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb 13 20:43:01 IST 2024
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

#define sasha "Sasha\n"
#define anna "Anna\n"

void solve(){
    ll n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        v[i].first = sz(a[i]);
        v[i].second = 0;
        rep(j,v[i].first-1ll,0ll,-1){
            if (a[i][j] != '0'){
                v[i].second = v[i].first-j-1ll;
                break;
            }
            else v[i].second++;
        }
    }
    debug(v);
    auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return a.second > b.second;
    };
    multiset<pair<ll,ll>,decltype(comp)> st(comp);
    rep(i,n) st.insert(v[i]);
    debug(st);
    while(sz(st) > 1){
        auto pr = *st.begin();
        st.erase(st.begin());
        pr.first -= pr.second;
        pr.second = 0;
        st.insert(pr);
        pr = *st.begin();

        debug('a',st);
        assert(sz(st) >= 2);
        st.erase(st.begin());
        auto pr2 = *st.begin();
        st.erase(st.begin());
        pr.first += pr2.first;
        pr.second = pr2.second;
        st.insert(pr);
        debug('s',st);
    }
    assert(sz(st) == 1);
    auto pr = *st.begin();
    pr.first -= pr.second;
    if (pr.first >= m+1) return void(cout << sasha);
    cout << anna;
}