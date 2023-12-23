/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  9 21:53:49 IST 2023
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // if (n == 1ll)
    if (k > 2ll) return void(cout << "0\n");
    if (k == 1ll){
        ll mn = *min_element(all(a));
        rep(i,n){
            rep(j,i+1ll,n-1ll,1ll){
                mn = min(mn,llabs(a[i]-a[j]));
            }
        }
        cout << mn << endl;
        return;
    }
    sort(all(a));
    vector<ll> diffs;
    rep(i,1ll,n-1ll,1ll){
        diffs.push_back(a[i]-a[0]);
    }
    debug(a,diffs);
    ll mn = min(a.front(),diffs.front());
    debug(mn);
    auto evaluate = [&](ll val){
        if (val <= a[0]){
            mn = min(mn,a[0]-val);
            return;
        }
        ll cur = llabs(val-a[0]);
        mn = min(cur,mn);
        ll ind = lower_bound(all(diffs),cur)-diffs.begin();
        if (ind == sz(diffs)){
            mn = min(mn,llabs(cur-diffs.back()));
            return;
        }
        mn = min(mn, llabs(cur-diffs[ind]));
        if (ind == 0ll)
            return;
        mn = min(mn, llabs(cur-diffs[ind-1ll]));
    };
    // rep(i,1ll,n-1ll,1ll){
    rep(i,n){
        rep(j,i+1ll,n-1ll,1ll){
            mn = min(mn,llabs(a[i]-a[j]));
            evaluate(llabs(a[i]-a[j]));
        }
    }
    cout << mn << endl;
}

/*

4

1
5 2
3 9 7 15 1

4 3
7 4 15 12

1
6 2
42 47 50 54 62 79

2 1
500000000000000000 1000000000000000000


*/