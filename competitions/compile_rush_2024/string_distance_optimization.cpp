/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Apr 18 20:16:11 IST 2024
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
    ll n; cin >> n;
    vector<vector<ll>> cts(n,vector<ll>(400,0ll));
    ll symbct = 0;
    map<char,ll> mp;
    string symbs;
    rep(i,n){
        string s; cin >> s;
        for (char ch : s){
            if (mp.find(ch) == mp.end()){
                mp[ch] = symbct++;
                symbs.push_back(ch);
                assert(sz(symbs) == symbct);
            }
            assert(symbct <= 400);
            cts[i][mp[ch]]++;
        }
    }
    ll sol = LLONG_MAX;
    char sch = '.';
    auto get_cost = [&](ll ch) -> ll {
        vector<vector<ll>> m(n,vector<ll>(n,LLONG_MAX));
        rep(i,n){
            rep(j,n){
                if (i == j) continue;
                ll com = 0ll;
                rep(k,symbct){
                    if (k == ch) continue;
                    com += min(cts[i][k],cts[j][k]);
                }
                m[i][j] = (com*com)+1ll;
                m[j][i] = m[i][j];
            }
        }
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    if (i == j || j == k || i == k) continue;
                    if (m[i][k] == LLONG_MAX || m[k][j] == LLONG_MAX) continue;
                    if (m[i][j] > m[i][k]+m[k][j])
                        m[i][j] = m[i][k]+m[k][j];
                }
            }
        }
        debug(ch,symbs[ch],m);
        ll cost = 0ll;
        rep(i,n){
            rep(j,n){
                if (i == j) continue;
                // ll com = 0ll;
                // rep(k,symbct){
                //     if (k == ch) continue;
                //     com += min(cts[i][k],cts[j][k]);
                // }
                // cost += (com*com)+1ll;
                cost += m[i][j];
            }
        }
        return cost;
    };
    rep(ch,symbct){
        ll cost = get_cost(ch);
        if (cost < sol){
            sol = cost;
            sch = symbs[ch];
        }
        else if (cost == sol && sch > symbs[ch]){
            sch = symbs[ch];
        }
    }
    cout << sol << " " << sch << endl;
}