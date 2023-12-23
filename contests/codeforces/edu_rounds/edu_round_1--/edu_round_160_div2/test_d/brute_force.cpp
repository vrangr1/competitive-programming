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
#else
    [[maybe_unused]] const bool DEBUG = false;
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
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<ll> dp((1<<n),0ll);
    auto process = [&] (auto &&self, ll vis) -> void {
        if (dp[vis]) return;
        dp[vis] = 1ll;
        ll last = -1;
        vector<ll> nxt(n,n);
        rep(i,n-1ll,0ll,-1ll){
            ll cur = 1ll<<i;
            if (cur&vis) continue;
            if (last == -1){
                last = i;
                continue;
            }
            nxt[i] = last;
            last = i;
        }
        debug(vis);
        debug(bitset<64>(vis).to_string().substr(64-n));
        // debug(p,nxt);
        if (DEBUG){
            cout << "p: [";
            rep(i,n){
                if (vis&(1ll<<i)) continue;
                cout << space << p[i];
            }
            cout << " ]\n";
        }
        debug(nxt);
        last = -1ll;
        rep(i,n){
            ll cur = 1ll<<i;
            if ((cur&vis)) continue;
            if (last != -1 && p[last] < p[i]) self(self,vis|cur);
            else if (nxt[i] != n && p[nxt[i]] < p[i]) self(self,vis|cur);
            last = i;
        }
    };
    process(process,0ll);
    cout << accumulate(all(dp),0ll) << endl;
}