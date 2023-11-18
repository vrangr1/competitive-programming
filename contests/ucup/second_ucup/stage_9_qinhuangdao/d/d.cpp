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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<vector<ll>> cps(m,vector<ll>(2));
    rep(i,n) cin >> a[i];
    rep(i,m){
        cin >> cps[i][0] >> cps[i][1];
        cps[i][0]--;
    }
    ll refund = 0ll, sum;
    rep(i,m) refund -= cps[i][1];
    sort(all(cps),[](const vector<ll> &a, const vector<ll> &b){
        return a[0] < b[0];
    });
    // debug(refund);
    ll mn = a[0], ind = 0, mnind = 0;
    assert(cps[ind][0] >= 0);
    sum = mn+refund;
    ll chosen = 0;
    rep(i,1,n-1,1){
        while(ind < m && cps[ind][0] < i){
            refund += cps[ind][1];
            ind++;
        }
        if (a[i] < mn) mnind = i;
        mn = min(a[i],mn);
        if (mn+refund < sum){
            chosen = mnind;
        }
        else if (mn+refund == sum && a[mnind] > a[chosen]){
            chosen = mnind;
        }
        sum = min(sum, mn+refund);
    }
    // debug(sum, chosen);
    assert(chosen >= 0 && chosen < sz(a));
    a.erase(a.begin() + chosen);
    sort(all(a));
    cout << sum << " \n"[n==1];
    rep(i,sz(a)){
        sum += a[i];
        cout << sum << " \n"[i==sz(a)-1];
    }
}

/*

1
5 2
1 2 3 4 5
3 1
4 2

1
7 3
4 3 1 10 3 8 6
4 9
3 8
4 5


*/