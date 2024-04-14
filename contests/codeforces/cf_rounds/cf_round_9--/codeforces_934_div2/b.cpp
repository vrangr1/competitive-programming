/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 20:10:05 IST 2024
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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    set<int> as(all(a)), bs(all(b));
    vector<int> l, r;
    int k2 = k<<1;
    set<int>::iterator it = as.begin();
    while(it != as.end()){
        int v = *it;
        if (bs.find(v) != bs.end()){
            if (sz(l) < k2){
                l.push_back(v);
                r.push_back(v);
            }
            it = as.erase(it);
            bs.erase(v);
        }
        else ++it;
    }
    if (sz(l) == k2){
        print_vec(l);
        print_vec(r);
        assert(sz(r) == k2);
        return;
    }
    assert(sz(l) == sz(r));
    assert(sz(l) < k2);
    if ((k2-sz(l))%2){
        l.pop_back();
        r.pop_back();
    }
    while(sz(l) < k2){
        assert(!as.empty());
        assert(!bs.empty());
        l.push_back(*as.begin());
        l.push_back(*as.begin());
        as.erase(as.begin());
        r.push_back(*bs.begin());
        r.push_back(*bs.begin());
        bs.erase(bs.begin());
    }
    print_vec(l);
    print_vec(r);
}