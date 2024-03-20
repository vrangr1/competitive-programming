/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Mar 19 10:48:33 IST 2024
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

void solve(){
    int n; cin >> n;
    map<int,vector<int>> mp;
    rep(i,n){
        int a; cin >> a;
        mp[a].push_back(i);
    }
    auto shifts = [n](int i, int j, int dir) -> int {
        assert(i!=j);
        if (dir){
            if (i < j) return j-i-1;
            else return n-1-j+i;
        }
        else{
            if (j < i) return i-j-1;
            else return i + n-1-j;
        }
    };
    auto process = [n,&shifts](vector<int> &inds) -> int {
        int m = sz(inds);
        if (m == 1) return n-1+n;
        int lshift = 0, rshift = 0;
        rep(i,m){
            int nxt = (i+1)%m;
            rshift = max(rshift, shifts(inds[i],inds[nxt],1));
            nxt = i-1;
            if (nxt < 0) nxt = m-1;
            lshift = max(lshift, shifts(inds[i],inds[nxt],0));
        }
        return min(lshift,rshift)+n;
    };
    int mn = INT_MAX;
    for (auto it : mp){
        mn = min(mn,process(it.second));
    }
    assert(mn != INT_MAX);
    cout << mn << endl;
}