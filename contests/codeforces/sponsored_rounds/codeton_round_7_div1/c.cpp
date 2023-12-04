/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
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

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j){
        return a[i] < a[j];
    });
    multiset<int> bs(all(b));
    int mn = 0;
    bool trip = false;
    rep(i,n){
        int ind = order[i];
        if (trip){
            assert(!bs.empty());
            b[ind] = *bs.rbegin();
            assert(a[ind] > b[ind]);
            bs.erase(prev(bs.end()));
            mn++;
            continue;
        }
        auto iter = bs.lower_bound(a[ind]);
        if (iter == bs.end()){
            assert(!bs.empty());
            trip = true;
            b[ind] = *bs.rbegin();
            assert(a[ind] > b[ind]);
            bs.erase(prev(bs.end()));
            mn++;
            continue;
        }
        b[ind] = *iter;
        bs.erase(iter);
    }
    if (mn > x) return void(cout << no);
    if (mn == x){
        cout << yes;
        rep(i,n)
            cout << b[order[i]] << " \n"[i==n-1];
        return;
    }
    int j = n-1;
    assert(bs.empty());
    bs.insert(all(b));
    rep(i,n){
        int ind = order[i];
        if (a[ind] > b[ind]) break;
        assert(!bs.empty());
        if (*bs.begin() >= a[ind]){
            assert(b[ind] == *bs.begin());
            bs.erase(bs.begin());
            continue;
        }
        
        while(j > i && a[order[j]] <= b[ind]){
            j--;
        }
        if (j == i) break;
        mn++;
        // swap(b[ind], b[order[j]]);
        if (mn == x) break;
    }
    if (mn < x) return void(cout << no);
    assert(mn == x);
    cout << yes;
    rep(i,n)
        cout << b[order[i]] << " \n"[i==n-1];
}

/*

2 3 4 5 6
1 2 3 4 5

2 3 4 5 6
2 3 4 5 1
*/