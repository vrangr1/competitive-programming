/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#define debug(...)
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
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    ll target = a.front();
    ll ct = 0ll;
    debug(a,target);
    // ll iters = 0ll;
    while(!a.empty()){
        sort(rall(a));
        debug(ct,a);
        // iters++;
        // if (iters > 10ll) break;
        while(!a.empty() && a.back() == target)
            a.pop_back();
        if (a.empty()) break;
        assert(a.back() < target);
        ct++;
        ll end = max(sz(a)-m,0ll);
        rep(i,sz(a)-1ll,end,-1ll){
            if (a[i] == target) break;
            a[i]++;
        }
    }
    cout << ct << endl;
}

/*
4

1
3 2
1 2 3

4 1
1 1 2 2
4 2
1 1 2 2
5 1
3 3 3 3 3


*/