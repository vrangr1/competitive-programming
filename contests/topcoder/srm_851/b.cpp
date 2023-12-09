/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec  7 22:51:42 IST 2023
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


// IMPORT SNIPPETS HERE

// END OF SNIPPETS
class ANewFence{
public:
    int build(vector<int> wood){
        int n = wood.size();
        auto get_len = [&](const int ps) -> int {
            int len = 0;
            map<int,int> mp;
            rep(i,n){
                mp[wood[i]]++;
            }
            rep(i,n){
                if (wood[i] > ps) continue;
                else if (wood[i] == ps){
                    len++;
                    continue;
                }
                else{
                    if (mp[wood[i]] == 0 || mp.find(ps-wood[i]) == mp.end() || mp[ps-wood[i]] == 0) continue;
                    if (ps-wood[i] == wood[i] && mp[wood[i]] == 1) continue;
                    len++;
                    mp[wood[i]]--;
                    mp[ps-wood[i]]--;
                }
            }
            return len;
        };
        set<int> vis;
        int maxlen = 0;
        rep(i,n){
            if (vis.find(wood[i]) != vis.end()) continue;
            vis.insert(wood[i]);
            debug(wood[i]);
            int temp = get_len(wood[i]);
            debug(temp);
            debug(maxlen);
			maxlen = max(maxlen,temp);
        }
        rep(i,n){
            rep(j,i+1,n-1,1){
                if (vis.find(wood[i]+wood[j]) != vis.end()) continue;
                debug(i);
                debug(j);
                debug(wood[i]+wood[j]);
                int temp = get_len(wood[i]+wood[j]);
                debug(temp);
                vis.insert(wood[i]+wood[j]);
                maxlen = max(maxlen, temp);
            }
        }
        return maxlen;
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