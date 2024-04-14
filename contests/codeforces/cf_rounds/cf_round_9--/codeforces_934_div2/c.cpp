/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 20:28:32 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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

void solve1(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    for (int v : a) mp[v]++;
    int turn = 0, sol = 0, bob = 1;
    bool fail = false, found = false;
    while(true){
        if (turn%2){
            if (fail){
                turn++;
                continue;
            }
            if (found){
                if (mp[bob] == 0){
                    turn++;
                    continue;
                }
                mp[bob]--;
                turn++;
                continue;
            }
            assert(bob>=sol);
            while(mp.find(bob) != mp.end() && mp[bob] > 0 && bob-sol+1 < mp[bob]){
                ++bob;
            }
            if (mp.find(bob) == mp.end()){
                fail = true;
                turn++;
                continue;
            }
            assert(mp[bob] > 0);
            assert(mp[bob] <= bob-sol+1);
            found = true;
            mp[bob]--;
        }
        else{
            if (mp.find(sol) != mp.end() && mp[sol] > 0){
                mp[sol]--;
                sol++;
            }
            else return void(cout << sol << endl);
        }
        turn++;
    }
    cout << sol << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> mp(n,0);
    rep(i,n) mp[a[i]]++;
    int sol = 0;
    bool one = false;
    for(;sol<n;++sol){
        if (mp[sol]>1)
            continue;
        if (mp[sol] == 0) return void(cout << sol << endl);
        assert(mp[sol]==1);
        if (one) return void(cout << sol << endl);
        one = true;
        continue;
    }
    cout << sol << endl;
}