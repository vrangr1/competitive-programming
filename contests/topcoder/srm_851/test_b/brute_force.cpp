/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
// #define debug(...)
// #ifdef LOCAL
//     #undef debug
//     #include <algo/debug.hpp>
//     const bool DEBUG = true;
// #endif

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
// using namespace __gnu_pbds;


class ANewFence {
public:
    int build(vector <int> wood) {
        vector<int> candidates;
        unordered_map<int, int> planks;

        for (auto w: wood) {
        	candidates.push_back(w);
            planks[w]++;
        }
        
        for (int i = 0; i < wood.size(); i++) {
            for (int j = 0; j < wood.size(); ++j) {
            	candidates.push_back(wood[i] + wood[j]);
            }
        }
        
        sort(candidates.begin(), candidates.end());
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        planks[0] = 200;
        int result = 0;
        for(auto c: candidates) {
        	int now = 0;
            for (auto const& [k, v]: planks) {
                if (planks.find(k) != planks.end() && planks.find(c - k) != planks.end()) {
            		now += min(planks[k], planks[c - k]);
                }
            }
            result = max(result, now / 2);
        }
    	return result;
    }
};

void solve();

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}


void solve(){
    int n; cin >> n;
    vector<int> wood(n);
    rep(i,n) cin >> wood[i];
    ANewFence sol;
    cout << sol.build(wood) << endl;
}