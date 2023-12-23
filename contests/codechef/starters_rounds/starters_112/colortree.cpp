/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 13 20:39:35 IST 2023
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

const ll mod = (ll)1e9+7ll;
// const ll red = 0, blue = 1;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> edges(n);
    rep(i,n-1ll){
        ll u,v; cin >> u >> v;--u;--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<ll> ss(n,0ll), odds(n,0ll);
    vector<ll> gc(n,0ll);
    auto inv = [] (auto &&self, ll val) -> ll {
        if (val <= 1ll) return val;
        return ((mod - mod/val)*self(self,mod%val))%mod;
    };
    ll inv2 = inv(inv,2ll);
    auto pairsum = [&odds,&inv2] (ll os) -> ll {
        assert(os <= sz(odds));
        if (os <= 1ll) return 0ll;
        ll csum = 0ll, tsum = 0ll;
        rep(i,os){
            tsum += (odds[i]*csum);
            csum += odds[i];
            tsum %= mod;
        }
        assert(tsum > 0ll);
        tsum *= inv2;
        tsum %= mod;
        return tsum;
    };
    auto dfs = [&] (auto &&self, ll node, ll parent) -> void {
        // debug(node);
        if (parent != -1 && sz(edges[node]) == 1){
            // debug('h');
            ss[node] = 1ll;
            gc[node] = 2ll;
            return;
        }
        ll sum = 0ll, prod = 1ll, osize = 0ll;
        assert(node < sz(edges));
        for (auto ngb : edges[node]){
            if (ngb == parent) continue;
            self(self,ngb,node);
            // continue;
            if (sum%2ll == ss[ngb]%2ll){
                prod *= gc[ngb];
                assert(prod > 0ll);
                prod %= mod;
                if (sum%2ll == 1ll){
                    prod *= inv2;
                    assert(prod > 0ll);
                    prod %= mod;
                    assert(osize < sz(odds));
                    odds[osize++] = gc[ngb];
                }
            }
            else{
                prod *= gc[ngb];
                assert(prod > 0ll);
                prod %= mod;
                if (ss[ngb]%2ll == 1ll){
                    assert(osize < sz(odds));
                    odds[osize++] = gc[ngb];
                }
            }
            sum += ss[ngb];
        }
        if (node == 1) debug(node,osize,prod);
        // return;
        if (sum%2ll == 0ll){
            prod *= 2ll;
            prod %= mod;
            gc[node] = pairsum(osize);
        }
        else{
            --osize;
            assert(osize >= 0ll);
            ll temp = pairsum(osize);
            temp *= odds[osize];
            temp %= mod;
            temp *= inv2;
            temp %= mod;
            gc[node] = temp;
        }
        ss[node] = ++sum;
        gc[node] += prod;
        gc[node] %= mod;
    };
    dfs(dfs,0ll,-1ll);
    debug(gc,ss);
    cout << gc[0] << endl;
    // vector<vector<ll>> gc(n,vector<ll>(2,0ll));
    // auto get = [&](ll node) -> ll {
    //     return (gc[node][red] + gc[node][blue])%mod;
    // };
    // auto dfs = [&](auto &&self, ll node, ll parent) -> void {
    //     if (sz(edges[node]) == 1){
    //         ss[node] = 1ll;
    //         gc[node][red] = 1ll;
    //         gc[node][blue] = 1ll;
    //         return;
    //     }
    //     ll sum = 0ll, prod = 1ll;
    //     gc[node][red] = 1ll;
    //     gc[node][blue] = 1ll;
    //     for (const auto &ngb : edges[node]){
    //         if (ngb == parent) continue;
    //         self(self,ngb,node);
    //         sum += ss[ngb];
    //         if (ss[ngb]%2ll == 0ll){
    //             prod *= get(ngb);
    //             prod %= mod;
    //             gc[node][red] *= get(ngb);
    //             gc[node][blue] *= get(ngb);
    //             gc[node][red] %= mod;
    //             gc[node][blue] %= mod;
    //             continue;
    //         }
    //         gc[node][red] *= gc[ngb][blue];
    //         gc[node][blue] *= gc[ngb][red];
    //         gc[node][red] %= mod;
    //         gc[node][blue] %= mod;
    //     }
    //     ss[node] = ++sum;
    // };
    // dfs(dfs,0ll,-1ll);
    // cout << get(0) << endl;
}


/*
5

1
2
1 2

1
5
1 2
1 3
2 4
2 5

1
6
1 2
1 3
1 4
2 5
2 6

1
7
1 2
2 3
2 4
1 6
1 5
1 7

1
8
1 2
1 3
1 4
2 5
2 6
6 7
7 8


*/