/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Feb 21 20:22:50 IST 2024
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
#define mt make_tuple
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

const ll mod = (ll)(1e9)+7ll, factmax = 250'000;
vector<ll> fact(factmax+1ll);

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    fact[0] = fact[1] = 1ll;
    rep(i,2ll,(ll)factmax,1ll)
        fact[i] = (fact[i-1]*i)%mod;
}

void solve(){
    init();
    ll n; cin >> n;
    ll n2 = n*n;
    ll m = [&]() -> ll {
        // if (n%2ll == 0ll)
        return min(n2,n2-((n2-n)/2ll));
    }();
    debug(m);
    vector<vector<ll>> grid(n,vector<ll>(n));
    set<ll> seen;
    bool wrong = false;
    ll dlow = (n2-n)/2ll + 1ll, dhigh = m, d = 0ll;
    rep(i,n) rep(j,n){
        cin >> grid[i][j];
        if (grid[i][j] != 0 && i != j){
            if (seen.find(grid[i][j]) != seen.end() || (grid[i][j] >= dlow && grid[i][j] <= dhigh)) wrong = true;
            seen.insert(grid[i][j]);
        }
    }
    if (wrong) return void(cout << "0\n");
    rep(i,n) {
        ll j = i;
        if (grid[i][j] == 0){
            d++;
            continue;
        }
        if (grid[i][j] > dhigh || grid[i][j] < dlow || seen.find(grid[i][j]) != seen.end()) return void(cout << "0\n");
        seen.insert(grid[i][j]);
    }
    debug(d);
    auto get = [&](ll val){
        ll sol;
        if (val > m) sol = val-m;
        else sol = m+val;
        assert(sol >= 1 && sol <= n2);
        return sol;
    };
    ll sol = fact[d];
    debug(sol);
    d = 0ll;
    rep(i,n){
        rep(j,i+1ll,n-1ll,1){
            if (grid[i][j] == 0){
                if (grid[j][i] == 0){
                    d++;
                    continue;
                }
                ll ctr = get(grid[j][i]);
                if (seen.find(ctr) != seen.end()) return void(cout << "0\n");
                seen.insert(ctr);
                continue;
            }
            if (grid[j][i] == 0){
                ll ctr = get(grid[i][j]);
                if (seen.find(ctr) != seen.end()) return void(cout << "0\n");
                seen.insert(ctr);
                continue;
            }
            if (grid[i][j]%m != grid[j][i]%m) return void(cout << "0\n");
        }
    }
    sol *= fact[d];
    sol%=mod;
    auto pr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0ll) return 1ll;
        ll a2 = (a*a)%mod;
        if (n%2ll) return (a*self(self,a2,n/2ll))%mod;
        return self(self,a2,n/2ll);
    };
    sol *= pr(pr,2ll,d);
    sol%=mod;
    cout << sol << endl;
}

/*

3

1
1
0

1
2
1 2
0 0

1
3
0 0 0
0 0 0
1 0 0


*/