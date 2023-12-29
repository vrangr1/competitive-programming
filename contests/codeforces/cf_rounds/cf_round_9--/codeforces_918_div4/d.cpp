/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec 28 20:16:49 IST 2023
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<".\n"[i==sz(v)-1];}
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

const char v = 'V', c = 'C';

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<string> sol;
    int i = n-1;
    auto ch = [](char ch){
        switch(ch){
            case 'a':
            case 'e': return v;
            default: return c;
        }
    };
    while(i>=0){
        if (ch(s[i]) == v){
            assert(i > 0);
            sol.push_back(string(1,s[i-1]) + s[i]);
            i-=2;
            continue;
        }
        else{
            assert(i>1);
            sol.push_back((string(1,s[i-2]) + s[i-1])+s[i]);
            i-=3;
            continue;
        }
    }
    reverse(all(sol));
    print_vec(sol);
}


/*


6

1
8
bacedbab

4
baba
13
daddecabeddad
3
dac
6
dacdac
22
dababbabababbabbababba




*/