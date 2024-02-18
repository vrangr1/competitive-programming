/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Feb 18 18:00:32 IST 2024
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

#define np "IMPOSSIBLE\n"

void solve(){
    int n; cin >> n;
    string trump; cin >> trump;
    vector<string> cards(2*n);
    map<string,vector<int>> cds;
    rep(i,2*n){
        cin >> cards[i];
        cds[string(1,cards[i].back())].push_back(stoi(cards[i].substr(0,1)));
    }
    vector<string> rem;
    string res;
    debug(cds);
    for (auto cur : cds){
        string suit = cur.first;
        if (suit == trump) continue;
        int k = sz(cur.second);
        vector<int> &nums = cur.second;
        rep(i,0,k-2,2){
            int mn = min(nums[i],nums[i+1]),mx=max(nums[i],nums[i+1]);
            assert(mn != mx);
            res += to_string(mn) + suit + space + to_string(mx) + suit + "\n";
        }
        if (k%2) rem.push_back(to_string(nums.back()) + suit);
    }
    debug(rem);
    if (sz(cds[trump]) < sz(rem) || (sz(cds[trump]) - sz(rem))%2) return void(cout << np);
    rep(i,sz(rem)){
        res += rem[i] + space + to_string(cds[trump][i]) + trump + "\n";
    }
    rep(i,sz(rem),sz(cds[trump])-2,2){
        int mn = min(cds[trump][i],cds[trump][i+1]),mx=max(cds[trump][i],cds[trump][i+1]);
        assert(mn != mx);
        res += to_string(mn) + trump + space + to_string(mx) + trump + "\n";
    }
    cout << res;
}