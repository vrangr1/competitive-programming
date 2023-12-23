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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // sort(all(a));
    set<int> mexs;
    multiset<int> vals(all(a));
    int mex = 0;
    auto iter = vals.begin();
    while(iter != vals.end()){
        if ((int)mexs.size() > q+5) break;
        if (*iter == mex){
            mex++;
            ++iter;
            continue;
        }
        if (*iter < mex){
            ++iter;
            continue;
        }
        mexs.insert(mex);
        mex++;
    }
    while((int)mexs.size() < q+5){
        if (vals.find(mex) != vals.end()){
            mex++;
            continue;
        }
        mexs.insert(mex++);
    }
    // debug(mexs);
    int ind, x, cur;
    while(q--){
        cin >> ind >> x; --ind;
        // debug(ind,x);
        cur = a[ind];
        vals.erase(vals.find(cur));
        if (vals.find(cur) != vals.end() && vals.find(x) != vals.end()){
            a[ind] = x;
            assert(!mexs.empty());
            cout << *mexs.begin() << endl;
            vals.insert(x);
            continue;
        }
        if (vals.find(cur) != vals.end()){
            a[ind] = x;
            vals.insert(x);
            if (mexs.find(x) != mexs.end()) mexs.erase(x);
            assert(!mexs.empty());
            cout << *mexs.begin() << endl;
            continue;
        }
        if (vals.find(x) != vals.end()){
            mexs.insert(cur);
            a[ind] = x;
            vals.insert(x);
            cout << *mexs.begin() << endl;
            continue;
        }
        mexs.insert(cur);
        if (mexs.find(x) != mexs.end()) mexs.erase(x);
        vals.insert(x);
        a[ind] = x;
        cout << *mexs.begin() << endl;
    }
}

/*
5 1
1 5 3 2 10
4 0

*/