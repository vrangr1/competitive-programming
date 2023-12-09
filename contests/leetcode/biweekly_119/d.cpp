/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  9 20:58:52 IST 2023
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class Solution {
public:
    int numberOfSets(int n, int maxdist, vector<vector<int>>& roads) {
        int ct = 0;
        vector<int> keep(n), dists(n);
        // vector<bool> vis(n);
        vector<vector<vector<int>>> edges(n);
        for(auto &road : roads){
            edges[road[0]].push_back({road[1],road[2]});
            edges[road[1]].push_back({road[0],road[2]});
        }
        for (int i = 0; i < n; ++i){
            sort(edges[i].begin(), edges[i].end(), [](const vector<int> &a,const vector<int> &b){
                return a[1] < b[1];
            });
        }
        auto comp = [](const vector<int> &a, const vector<int> &b){
            return a[1] > b[1];
        };
        auto find_dists = [&] (int node) -> int {
            if (!keep[node]) return INT_MAX;
            fill(all(dists),INT_MAX);
            dists[node] = 0;
            // fill(all(vis),false);
            priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
            pq.push({node,0});
            // vis[node] = true;
            int curnode, dist;
            while(!pq.empty()){
                curnode = pq.top().at(0);
                dist = pq.top().at(1);
                pq.pop();
                // if (vis[curnode]) continue;
                for(const auto &edge : edges[curnode]){
                    // if (vis[edge[0]] || !keep[edge[0]]) continue;
                    if (!keep[edge[0]]) continue;
                    if (dist + edge[1] >= dists[edge[0]]) continue;
                    dists[edge[0]] = dist+edge[1];
                    // vis[edge[0]] = true;
                    pq.push({edge[0],dists[edge[0]]});
                }
            }
            dist = dists[node];
            for (int i = 0; i < n; ++i)
                if (keep[i]) dist = max(dist,dists[i]);
            return dist;
            // return *max_element(all(dists));
        };
        auto find_max = [&] (){
            int mxdist = 0,cdist;
            for (int i = 0; i < n; ++i){
                if (!keep[i]) continue;
                cdist = find_dists(i);
                debug(i);
                debug(cdist);
                mxdist = max(mxdist,cdist);
                // mxdist = max(mxdist, find_dists(i));
                if (mxdist > maxdist) return mxdist;
            }
            return mxdist;
        };
        int act = 0;
        for(int close = 0; close <= n; ++close){
            fill(keep.begin(), keep.begin() + close, 0);
            fill(keep.begin()+close, keep.end(), 1);
            if (close == 0) debug(keep);
            do{
                act++;
                int cdist = find_max();
                if (close == 0) debug(cdist);
                if (cdist <= maxdist){
                    ct++;
                    debug(close);
                    debug(keep);
                }
            }while(next_permutation(all(keep)));
        }
        debug(act);
        return ct;
    }
};


void solve(){
    Solution sol;
    int n, maxdist; cin >> n >> maxdist;
    int r; cin >> r;
    vector<vector<int>> roads(r);
    rep(i,r){
        int u,v,w; cin >> u >> v >> w;
        roads[i] = {u,v,w};
    }
    cout << sol.numberOfSets(n,maxdist,roads) << endl;
}

/*

3
5
3
0 1 2
1 2 10
0 2 10

3
5
4
0 1 20
0 1 10
1 2 2
0 2 2

1
10
0


*/