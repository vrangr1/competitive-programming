/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Mar 25 03:20:59 IST 2024
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

const ll mod = (ll)1e9 + 7ll;

class Solution {
public:

    #define ll long long

    int n;
    vector<int>a;
    ll mod=1e9+7;

    ll dp[5001][7][16];

    ll f(int i, int last, int cnt){
        if(i==n)return 1;

        if(dp[i][last][cnt]!=-1) return dp[i][last][cnt];

        ll ans=0;

        for(int x=1;x<=6;x++){
            if(x==last){
                if(cnt+1<=a[x-1]) // we can still include last
                    ans+=f(i+1,last,cnt+1);
            }
            else{
                ans+=f(i+1,x,1);
            }
        }

        return dp[i][last][cnt]=ans%mod;
    }

    int dieSimulator(int _n, vector<int>& _a) {
        a=_a; n=_n;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0);
    }
};

void solve(){
    Solution sol;
    int n; cin >> n;
    vector<int> rm(6);
    rep(i,6) cin >> rm[i];
    cout << sol.dieSimulator(n,rm) << endl;
}