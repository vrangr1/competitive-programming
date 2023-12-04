/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Nov 27 23:57:41 IST 2023
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

#ifndef IMPORT_HASH_SET_SNIPPET
#define IMPORT_HASH_SET_SNIPPET
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
typedef long long int ll;
using namespace std;

// Source: Neal Wu (codeforces handle: neal)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename type>
using hash_set = conditional_t <is_same<type,int>::value || is_same<type,ll>::value, unordered_set<type, custom_hash>, unordered_set<type>>;

template<typename t1, typename t2>
using hash_map = conditional_t<is_same<t1,ll>::value || is_same<t1,int>::value, unordered_map<t1, t2, custom_hash>, unordered_map<t1,t2>>;

template <typename type>
using hash_multiset = conditional_t<is_same<type,int>::value || is_same<type,ll>::value, unordered_multiset<type, custom_hash>, unordered_multiset<type>>;

template<typename t1, typename t2>
using hash_multimap = conditional_t<is_same<t1,int>::value || is_same<t2,ll>::value, unordered_multimap<t1, t2, custom_hash>, unordered_multimap<t1,t2>>;

#endif // IMPORT_HASH_SET_SNIPPET

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
    ll m; cin >> m;
    vector<ll> n(m), l(m), r(m);
    vector<vector<ll>> a(m), c(m);
    ll minlen = 0, maxlen = 0, allct = 0, mx = LLONG_MIN;
    hash_map<ll, vector<pair<ll,ll>>> locs;
    vector<ll> msct(m,0ll);
    rep(i,m){
        cin >> n[i] >> l[i] >> r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        rep(j,n[i]) cin >> a[i][j];
        rep(j, n[i]){
            cin >> c[i][j];
            msct[i] += c[i][j];
            allct += c[i][j];
            locs[a[i][j]].push_back({i,j});
            mx = max(mx,a[i][j]);
        }
        minlen += l[i];
        maxlen += r[i];
    }
    maxlen = min(maxlen, allct);
    if (maxlen > mx) return void(cout << "0\n");
    auto anti_beauty = [&](const ll len) -> ll {
        if (locs.find(len) == locs.end()) return 0;
        ll curlen = maxlen, i, j, x = 0;
        for (auto &loc : locs[len]){
            i = loc.first;
            j = loc.second;
            if (msct[i]-c[i][j] >= r[i])
                continue;
            if (msct[i]-c[i][j] >= l[i]){
                curlen -= (c[i][j]-(msct[i]-r[i]));
                continue;
            }
            x += l[i] - (msct[i] - c[i][j]);
            curlen -= r[i]-l[i];
        }
        if (curlen >= len) return x;
        return x + len-curlen;
    };
    ll sol = LLONG_MAX;
    rep(len, minlen, maxlen, 1ll){
        sol = min(sol, anti_beauty(len));
        if (sol == 0) break;
    }
    cout << sol << endl;
}