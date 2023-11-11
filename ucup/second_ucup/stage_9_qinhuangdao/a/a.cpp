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
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

inline ll get_hash(ll x, ll y){
    return x*1e6+y;
}

inline bool check_bound(ll x, ll y, ll n){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

void solve(){
    ll n, k; cin >> n >> k;
    ll x = 1, y = 0;
    bool right = true;
    int i;
    unordered_set<ll> uset;

    for(i = 1; i <= k; ++i){
        if (right)
            y++;
        else x++;
        if (!check_bound(x, y, n)) break;
        right = !right;
        cout << x << space << y << endl;
        uset.insert(get_hash(x,y));
    }
    // debug(x,y,right);
    if (right){
        cout << n << space << 1 << endl;
        uset.insert(get_hash(n,1));
    }
    else{
        cout << 1 << space << n << endl;
        uset.insert(get_hash(1,n));
    }
    if (i == k) return;
    rep(j,1,n,1){
        rep(l,1,n,1){
            if (uset.find(get_hash(j,l)) != uset.end())
                continue;
            cout << j << space << l << endl;
            i++;
            if (i == k) return;
        }
    }
}