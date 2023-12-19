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
    ll n; cin >> n;
    assert(n<60);
    vector<vector<ll>> edges(n);
    vector<ll> parent(n,-1);
    rep(i,1,n-1ll,1){
        ll u = i, v;
        cin >> v; --v;
        edges[v].push_back(u);
        parent[u] = v;
    }
    auto valid = [&](const ll a, const ll b) -> bool {
        ll temp = a;
        while(temp != -1){
            if (b == temp) return false;
            temp = parent[temp];
        }
        temp = b;
        while(temp != -1){
            if (a == temp) return false;
            temp = parent[temp];
        }
        return true;
    };
    auto bf = [&] (auto &&self, ll vis) -> ll {
        ll ct = 0ll;
        rep(bit,n){
            ll cur = (1ll<<bit);
            if (vis&cur) continue;
            rep(b2,bit+1ll,n-1ll,1ll){
                ll c2 = (1ll<<b2);
                if (vis&c2) continue;
                if (!valid(bit,b2)) continue;
                ct = max(ct, 1ll + self(self,(vis|cur|c2)));
            }
        }
        return ct;
    };
    cout << bf(bf,0ll) << endl;
}