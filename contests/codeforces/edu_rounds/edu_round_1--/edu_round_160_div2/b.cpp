/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Dec 18 20:10:35 IST 2023
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

void solve(){
    string s; cin >> s;
    int z = (int)count(all(s),'0'), o = (int)count(all(s),'1'), n = sz(s);
    int oz = z, oo = o;
    int ct = 0;
    rep(i,n-1,0,-1){
        if (z == o) return void(cout << ct << endl);
        if (oz >= o && oo >= z) return void(cout << ct << endl);
        if (s[i] == '0') z--;
        else o--;
        ct++;
    }
    cout << ct << endl;
    // if (z == o) return void(cout << "0\n");
    // char more = ((z<o)?'1':'0');
    // char less = (more == '0'?'1':'0');
    // int h = 0, ct = 0;
    // string t;
    // int ts = 0;
    // vector<int> freq = {z,o};
    // auto other = [&](int index) -> int {
    //     if (s[index] == '0') return 1;
    //     else return 0;
    // };
    // auto same = [&](int index) -> int {
    //     return (int)(s[index]-'0');
    // };
    // rep(i,n){
    //     if (s[ts] != s[i]){
    //         if (more == '1') o--;
    //         else z--;
    //         ts++;
    //         t.push_back(s[i]);
    //         continue;
    //     }
    //     if (freq[same(i)] <= freq[other(i)]){
    //         h++;
    //         t.push_back(other(i)+'0');
    //         freq[same(i)]--;
    //         continue;
    //     }
    //     if (s[i] == less){
    //         h++;
    //         t.push_back(more);
    //         ts++;
    //         continue;
    //     }
    //     if (h){
    //         ts++;
    //         h--;
    //         t.push_back(less);
    //         continue;
    //     }
    //     ct++;
    //     if (more == '1') o--;
    //     else z--;
    //     more = ((z<o)?'1':'0');
    //     less = (more == '0'?'1':'0');
    // }
    // cout << ct << endl;
}