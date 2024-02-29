/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Feb 29 20:24:15 IST 2024
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

#define less '<'
#define equal '='
#define greater '>'

void solve(){
    int n; cin >> n;
    if (n == 2){
        cout << "! 0 1\n";
        cout.flush();
        return;
    }
    auto ask = [](int a, int b, int c, int d) -> char {
        cout << "? " << a << " " << b << " " << c << " " << d << endl;
        cout.flush();
        char ans; cin >> ans;
        return ans;
    };
    int mx = 0;
    rep(test,1,n-1,1){
        char rel = ask(mx,mx,test,test);
        assert(rel != equal);
        if (rel == less)
            mx = test;
    }
    vector<int> inds = {0};
    int s = 0;
    rep(test,1,n-1,1){
        char rel = ask(mx,s,mx,test);
        if (rel == equal)
            inds.push_back(test);
        else if (rel == less){
            inds = {test};
            s = test;
        }
    }
    if (sz(inds) == 1){
        cout << "! " << inds[0] << " " << mx << endl;
        cout.flush();
        return;
    }
    s = inds[0];
    rep(i,1,sz(inds)-1,1){
        char rel = ask(s,s,inds[i],inds[i]);
        assert(rel != equal);
        if (rel == greater)
            s = inds[i];
    }
    cout << "! " << s << " " << mx << endl;
    cout.flush();
}