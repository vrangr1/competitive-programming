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
    vector<int> a(n), ob(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> ob[i];
    int cur = 0;
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&a](const int &i, const int &j){
        return a[i] < a[j];
    });
    // vector<int> b = ob;
    // sort(rall(b));
    multiset<int> b(all(ob));
    // int j = 0;
    rep(i,n-1,0,-1){
        if (cur < x){
            auto iter = b.lower_bound(a[order[i]]);
            if (iter == b.begin()){
                ob[order[i]] = *b.begin();
                b.erase(b.begin());
            }
            else{
                iter = prev(iter);
                ob[order[i]] = *iter;
                b.erase(iter);
            }
            // ob[order[i]] = b.back();
            // b.pop_back();
            cur += (a[order[i]] > ob[order[i]]);
            continue;
        }
        ob[order[i]] = *b.begin();
        b.erase(b.begin());
        // ob[order[i]] = b[j++];
        cur += (a[order[i]] > ob[order[i]]);
    }
    if (cur != x) return void(cout << no);
    cout << yes;
    // rep(i,n)
    //     cout << ob[i] << " \n"[i==n-1];
}

/*

1
3 1
2 4 3
4 1 2

2 3 4
4 1 2
1 4

1
2 2
4 2
3 1

*/