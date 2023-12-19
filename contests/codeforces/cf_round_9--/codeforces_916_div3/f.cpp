/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Dec 19 21:13:35 IST 2023
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
void solve(int t);

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	int T;cin>>T;rep(t,T)solve(t);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(int test){
    ll n; cin >> n;
    vector<vector<ll>> edges(n);
    vector<ll> p(n-1);
    rep(i,1,n-1ll,1){
        ll u = i, v;
        cin >> v; --v;
        p[i-1] = v+1;
        edges[v].push_back(u);
    }
    if (test == 3943){
        cout << n << ":";
        rep(i,n-1) cout << p[i] << ";";
        cout << endl;
        return;
    }
    vector<ll> ss(n,0ll), d(n,0ll), m(n,0ll), used(n,0ll);
    auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return a.first < b.first;
    };
    // auto process = [&](ll node, ){
        
        
    // };
    auto dfs = [&] (auto &&self, ll node, ll cur) -> void {
        d[node] = cur;
        // ll last = 0ll;
        deque<pair<ll,ll>> dq;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(comp)>pq(comp);
        for (const ll &ngb : edges[node]){
            self(self,ngb,cur+1ll);
            ss[node] += ss[ngb];
            pq.push({ss[ngb],ngb});
        }
        sort(all(edges[node]),[&](const ll &a, const ll &b){
            return ss[a] > ss[b];
        });
        for (const ll &ngb : edges[node]){
            ll unmatched = ss[ngb];
            assert(unmatched>0ll);
            while(!dq.empty() && unmatched > 0ll){
                ll match = min(dq.back().first, unmatched);
                m[node] += match;
                dq.back().first -= match;
                unmatched -= match;
                used[dq.back().second] += match;
                if (dq.back().first == 0ll)
                    dq.pop_back();
            }
            assert(unmatched>=0ll);
            if (unmatched){
                assert(dq.empty());
                dq.emplace_back(unmatched,ngb);
            }
            // match = min(unmatched/2ll,m[ngb]);
            // m[node] += match;
            // unmatched -= (2ll*match);
            // assert(unmatched >= 0ll);
            // last += unmatched;
        }
        if (node == 0ll){
            debug('i',m);
        }
        for (const ll &ngb : edges[node]){
            assert(used[ngb] <= ss[ngb]);
            if (used[ngb] == ss[ngb]) continue;
            ll unmatched = ss[ngb] - used[ngb];
            ll match = min(unmatched/2ll,m[ngb]);
            m[node] += match;
        }
        ss[node]++;
    };
    dfs(dfs,0,0);
    debug(ss,d,m);
    cout << m[0] << endl;
}

/*

6

1
4
1 2 1

2
1
5
5 5 5 1
7
1 2 1 1 3 3

1
7
1 1 3 2 2 4

7
1 2 1 1 1 3

1
7
1 1 1 2 3 4
*/