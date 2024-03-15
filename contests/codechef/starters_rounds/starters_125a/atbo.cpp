/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar 13 20:18:22 IST 2024
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

void solve(){
    ll n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    auto compxor = [](ll n) -> ll {
        assert(n>=0ll);
        switch(n%4){
            case 0: return n;
            case 1: return 1;
            case 2: return n+1;
            case 3: return 0;
        }
        assert(false);
        return 0;
    };
    auto range_xor = [&compxor](ll low, ll high) -> ll {
        assert(low <= high);
        assert(low>=0ll);
        if (low <= 1) return compxor(high);
        return compxor(high)^compxor(low-1);
    };
    auto compoddxor = [&compxor](ll n) -> ll {
        assert(n>=0ll);
        if (n%2ll) n++;
        ll sol = compxor(n/2ll)*2ll;
        return sol^compxor(n);
    };
    auto odd_xor = [&compoddxor](ll low, ll high) -> ll {
        assert(low <= high);
        assert(low>=0ll);
        if (low <= 1ll) return compoddxor(high);
        return compoddxor(high)^compoddxor(low-1ll);
    };
    auto compevenxor = [&compxor](ll n) -> ll {
        assert(n>=0ll);
        if (n%2ll) n++;
        return compxor(n/2ll)*2ll;
    };
    auto even_xor = [&compevenxor](ll low, ll high) -> ll {
        assert(low <= high);
        assert(low>=0ll);
        if (low <= 2ll) return compevenxor(high);
        return compevenxor(high)^compevenxor(low-1ll);
    };
    vector<ll> dists = {llabs(x-n), llabs(x-1), llabs(y-m),llabs(y-1)};
    vector<ll> corners = {llabs(x-1)+llabs(y-1), llabs(x-n)+llabs(y-1), llabs(x-1)+llabs(y-n), llabs(x-n)+llabs(y-n)};
    sort(all(dists));
    sort(all(corners));
    vector<pair<ll,ll>> vals;
    for(auto d : dists) vals.emplace_back(d,0);
    for(auto d : corners) vals.emplace_back(d,1);
    sort(all(vals));
    ll st = 0, ct = 0ll;
    ll lastd = -1ll, lastt = -1ll;
    ll sol = 0ll;
    debug(vals);
    for (auto [d, t] : vals){
        if (lastd == -1){
            assert(t==0);
            lastd=d;
            lastt=t;
            if (t == 0) st++;
            else ct++;
            continue;
        }
        if (ct == 0ll){
            if (t == 0ll){
                if (st%2ll){
                    assert(lastd <= d);
                    if (lastd != d) sol^=range_xor(lastd+1ll,d);
                }
                st++;
                lastd=d;
                lastt=t;
                continue;
            }
            assert(t==1ll);
            if (st%2ll){
                if (d > lastd) sol^=range_xor(lastd+1ll,d);
            }
            ct++;
            lastd=d;
            lastt=t;
            continue;
        }
        if (ct == 1ll){
            assert(st>=2ll);
            assert(st<=4ll);
            if (t == 0){
                assert(st==2);
                assert(lastt==1ll);
                if (lastd%2ll){
                    if (lastd < d) sol ^= even_xor(lastd+1,d);
                }
                else if (lastd < d) sol^=odd_xor(lastd+1,d);
                lastd=d;
                lastt=t;
                st++;
                continue;
            }
            assert(lastt==1ll);
            assert(st>=3ll);
            if (lastd%2ll){
                if (lastd < d) sol ^= even_xor(lastd+1,d);
            }
            else if (lastd < d) sol^=odd_xor(lastd+1,d);
            lastd=d;
            lastt=t;
            ct++;
            continue;
        }
        if (ct==2ll){
            assert(st>=3ll && st<=4ll);
            if (t == 0){
                assert(st==3ll);
                assert(lastt==1ll);
                ll par = (corners[0] + corners[1])%2ll;
                if (lastd < d){
                    if (par) sol ^=odd_xor(lastd+1ll,d);
                    else sol ^= even_xor(lastd+1ll,d);
                }
                lastd=d;
                lastt=t;
                st++;
                continue;
            }
            assert(st==4ll);
            // assert(lastt==0ll);
            ll par = (corners[0] + corners[1] + 1ll)%2ll;
            if (lastd < d){
                if (par) sol ^=odd_xor(lastd+1ll,d);
                else sol ^= even_xor(lastd+1ll,d);
            }
            lastd=d;
            lastt=t;
            ct++;
            continue;
        }
        if (ct==3ll){
            cout << "something\n";
        }
    }
    cout << sol << endl;
}