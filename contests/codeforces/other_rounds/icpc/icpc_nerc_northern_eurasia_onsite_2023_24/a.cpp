/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 13 13:06:37 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll x, k; cin >> x >> k;
    vector<vector<ll>> lists(k), best(k), costs(k);
    rep(i,k){
        ll len; cin >> len;
        best[i].resize(len);
        lists[i].resize(len);
        costs[i].resize(len);
        rep(j,len)
            cin >> lists[i][j];
        best[i].back() = lists[i].back();
        costs[i].back() = 0ll;
        rep(j,len-2ll,0ll,-1ll){
            if (best[i][j+1ll] >= 0ll)
                best[i][j] = best[i][j+1ll] + lists[i][j];
            else
                best[i][j] = lists[i][j];
            if (best[i][j] < 0ll) continue;
            if (lists[i][j] >= 0ll){
                costs[i][j] = max(0ll,costs[i][j+1ll]-lists[i][j]);
                continue;
            }
            costs[i][j] = -lists[i][j] + costs[i][j+1ll];
        }
    }
    auto comp = [](const vector<ll> &a, const vector<ll> &b){
        return a[0] < b[0];
    };
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(comp)> pq(comp);
    rep(i,k)
        pq.push({lists[i][0],i,0ll});
    ll lt, ind, val;
    ll sol = x;
    debug(best);
    while(!pq.empty()){
        debug(x,pq);
        val = pq.top().at(0);
        lt = pq.top().at(1);
        ind = pq.top().at(2);
        if (best[lt][ind] < 0ll){
            pq.pop();
            continue;
        }
        if (pq.top().at(0) + x >= 0ll){
            x += val;
            sol = max(sol,x);
            pq.pop();
            ++ind;
            if (ind >= sz(lists[lt])) continue;
            pq.push({lists[lt][ind],lt,ind});
            continue;
        }
        break;
    }
    cout << sol << endl;
}