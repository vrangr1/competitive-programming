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
    const bool DEBUG = false;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define qwe(r,t,y)
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass (void)0
template<typename type>inline void print_vec(const vector<type>&v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

int find_lis(const vector<int> &a){
    int n = a.size();
    vector<int> d;
    rep(i,n){
        if (d.empty()){
            d.push_back(a[i]);
            continue;
        }
        if (d.back() < a[i]){
            d.push_back(a[i]);
            continue;
        }
        int ind = lower_bound(all(d),a[i])-d.begin();
        d[ind] = a[i];
    }
    return d.size();
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<int> r, p;
    vector<int> d;
    rep(i,n){
        if (d.empty()){
            d.push_back(a[i]);
            r.push_back(i);
            p.push_back(-1);
            continue;
        }
        if (d.back() < a[i]){
            d.push_back(a[i]);
            p.push_back(r.back());
            r.push_back(i);
            continue;
        }
        int ind = lower_bound(all(d),a[i]) - d.begin();
        d[ind] = a[i];
        r[ind] = i;
    }
    int ind = p.back(), low,high;
    debug(find_lis(a));
    // debug(n,m,a,d,r,p);
    if (ind == -1){
        vector<int> c(all(b));
        c.insert(c.end(), all(a));
        sort(all(c),greater<int>());
        print_vec(c);
        return;
    }
    else{
        high = a[r.back()];
        int len = d.size(), cur = r.back();
        rep(i,len-1,0,-1){
            if (i < len-1) cur = p[i+1];
            assert(p[i] < cur);
            rep(j,p[i]+1,cur,1){
                if (a[j] >= a[cur] && (i == len-1 || a[r[i+1]] > a[j]))
                    cur = j;
            }
            r[i] = cur;
        }
        low = a[r[0]];
    }
    // assert(low < high);
    // int val = a[ind];
    // debug(val);
    if (low <= high){
        sort(all(b));
        int ilow = lower_bound(all(b),low) - b.begin();
        // int ihigh = upper_bound(all(b),high) - b.begin();
        if (ilow == 0){
            sort(all(b),greater<int>());
            vector<int> c(all(b));
            c.insert(c.end(),all(a));
            debug(find_lis(c));
            print_vec(c);
            return;
        }
        sort(b.begin()+ilow, b.end(), greater<int>());
        vector<int> c(b.begin()+ilow,b.end());
        c.insert(c.end(), all(a));
        sort(b.begin(), b.begin()+ilow, greater<int>());
        c.insert(c.end(), b.begin(), b.begin()+ilow);
        debug(find_lis(c));
        print_vec(c);
        return;
    }
    swap(low,high);
    sort(all(b));
    int ilow = lower_bound(all(b),low) - b.begin();
    int ihigh = lower_bound(all(b),high) - b.begin();
    if (ilow == 0){
        sort(all(b),greater<int>());
        vector<int> c(all(b));
        c.insert(c.end(),all(a));
        debug(find_lis(c));
        print_vec(c);
        return;
    }
    sort(b.begin()+ihigh, b.end(), greater<int>());
    vector<int> c(b.begin()+ihigh,b.end());
    c.insert(c.end(), a.begin(), a.begin() + n/2);
    sort(b.begin()+ilow, b.begin()+ihigh, greater<int>());
    c.insert(c.end(), b.begin() + ilow, b.begin()+ ihigh);
    c.insert(c.end(), a.begin()+n/2, a.end());
    c.insert(c.end(),b.begin(), b.begin()+ilow);
    debug(find_lis(c));
    print_vec(c);
    return;
    // debug(b,i2);
    // if (i2 == m){
    //     vector<int> c(all(a));
    //     sort(all(b),greater<int>());
    //     c.insert(c.end(),all(b));
    //     print_vec(c);
    //     return;
    // }
    // if (i2 == 0){
    //     sort(all(b),greater<int>());
    //     vector<int> c(all(b));
    //     c.insert(c.end(),all(a));
    //     print_vec(c);
    //     return;
    // }
    // sort(b.begin()+i2, b.end(),greater<int>());
    // vector<int> c(b.begin()+i2, b.end());
    // c.insert(c.end(),all(a));
    // sort(b.begin(), b.begin()+i2, greater<int>());
    // c.insert(c.end(),b.begin(), b.begin()+i2);
    // print_vec(c);
}


/*

7

1
2 1
6 4
5

1
5 5
1 7 2 4 5
5 4 1 2 7

1
1 9
7
1 2 3 4 5 6 7 8 9

1
3 2
1 3 5
2 4

1
10 5
1 9 2 3 8 1 4 7 2 9
7 8 5 4 6

1
2 1
2 2
1

1
6 1
1 1 1 1 1 1
777




*/