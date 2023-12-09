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

ll one_solve(vector<ll> &a){
    ll mn = *min_element(all(a));
    ll n = sz(a);
    rep(i,n){
        rep(j,i+1ll,n-1ll,1ll){
            mn = min(mn,llabs(a[i]-a[j]));
        }
    }
    return mn;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
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
    ll mn = *min_element(all(a));
    a.push_back(-1ll);
    rep(i,n){
        rep(j,i+1ll,n-1ll,1ll){
            a.pop_back();
            a.push_back(llabs(a[i]-a[j]));
            mn = min(mn,llabs(a[i]-a[j]));
            mn = min(mn,one_solve(a));
        }
    }
    cout << mn << endl;
}