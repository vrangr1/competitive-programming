/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan 13 21:07:26 IST 2024
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
    ll n, q; cin >> n >> q;
    vector<i128> a, inds;
    vector<bool> c;
    bool limreached = false;
    while(n--){
        ll b, x; cin >> b >> x;
        if (limreached) continue;
        a.push_back(x);
        if (b == 1ll){
            c.push_back(false);
            if (inds.empty()) inds.push_back(1ll);
            else inds.push_back(inds.back()+1ll);
        }
        else{
            c.push_back(true);
            inds.push_back(inds.back()*(i128)(x+1ll));
        }
        if (inds.back() > (i128)1e18) limreached = true;
    }
    auto valid = [&](i128 i, i128 ind) -> bool {
        if (!c[i]) return inds[i] == ind;
        assert(i>0);
        return ind <= inds[i] && ind > inds[i-1];
    };
    auto find_val = [&](auto &&self, i128 low, i128 high, i128 ind) -> i128 {
        // debug(low,high);
        // assert(low < high);
        i128 mid = (low+high)/(i128)2ll;
        if (low+(i128)1 == high || valid(mid,ind)){
            assert(valid(mid,ind));
            if (!c[mid]) return a[mid];
            assert(inds[mid]%(a[mid]+(i128)1ll) == 0ll);
            i128 len = inds[mid]/(a[mid]+(i128)1ll);
            --ind;
            ind %= len;
            ++ind;
            assert(mid > 0ll);
            return self(self,0,mid,ind);
        }
        assert(mid < (i128)a.size());
        if (inds[mid] < ind) return self(self,mid+1ll,high,ind);
        return self(self,low,mid,ind);
    };
    // debug(a,c,inds);
    while(q--){
        ll k; cin >> k;
        // debug(k);
        cout << (ll)find_val(find_val,0,a.size(),k) << " \n"[q==0];
        // debug(endl);
    }
}

/*

4

1
5 10
1 1
1 2
2 1
1 3
2 3
1 2 3 4 5 6 14 15 16 20

1
10 10
1 3
1 8
2 15
1 6
1 9
1 1
2 6
1 1
2 12
2 10
32752 25178 3198 3199 2460 2461 31450 33260 9016 4996

1
12 5
1 6
1 11
2 392130334
1 4
2 744811750
1 10
1 5
2 209373780
2 178928984
1 3
2 658326464
2 1000000000
914576963034536490 640707385283752918 636773368365261971 584126563607944922 1000000000000000000

1
2 2
1 1
1 2
1 2



*/