/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 20 20:12:39 IST 2023
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

void solve2(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll target = a.back(), inc, ind = m, ct = 0ll;
    stack<pair<ll,ll>> stk;
    rep(i,m) stk.push(make_pair(a[i],0ll));
    while(!stk.empty()){
        inc = target - stk.top().first - stk.top().second;
        ct += inc;
        assert(stk.empty() || stk.top().first + inc + stk.top().second <= target);
        while(!stk.empty() && stk.top().first + inc + stk.top().second == target){
            inc += stk.top().second;
            stk.pop();
            assert(stk.empty() || stk.top().first + inc + stk.top().second <= target);
        }
        if (!stk.empty()) stk.top().second += inc;
        inc = 0ll;
        while(sz(stk) < m && ind < n){
            stk.push(make_pair(a[ind++],inc));
        }
    }
    cout << ct << endl;
}

void solve3(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    priority_queue<ll> pq;
    ll inc = 0ll, ct = 0, target = a.back();
    debug(a,target,endl);
    rep(i,n){
        if (sz(pq) < m){
            assert(i<m);
            assert(a[i]-inc <= target);
            pq.push(a[i]-inc);
            continue;
        }
        debug(i,pq,inc,ct);
        assert((target-(pq.top()+inc)) >= 0ll);
        ct += (target - (pq.top()+inc));
        inc += target-pq.top()-inc;
        pq.pop();
        pq.push(a[i]-inc);
        debug(a[i],a[i]-inc,endl);
    }
    debug('f',pq,inc,ct);
    while(!pq.empty()){
        assert((target-(pq.top()+inc)) >= 0ll);
        ct += (target-(pq.top()+inc));
        inc += target-pq.top()-inc;
        pq.pop();
    }
    cout << ct << endl;
}

void solve1(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    priority_queue<ll> pq;
    ll inc = 0ll, ct = 0, target = a.front();
    rep(i,n){
        if (sz(pq) < m){
            pq.push(a[i]-inc);
            continue;
        }
        assert((target-(pq.top()+inc)) >= 0ll);
        ct += (target - (pq.top()+inc));
        inc += target-pq.top()-inc;
        pq.pop();
        pq.push(a[i]-inc);
    }
    while(!pq.empty()){
        assert((target-(pq.top()+inc)) >= 0ll);
        ct += (target-(pq.top()+inc));
        inc += target-pq.top()-inc;
        pq.pop();
    }
    cout << ct << endl;
}


void solve4(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    if (m == 1){
        ll target = a.back();
        ll sum = 0ll;
        rep(i,n) sum += target-a[i];
        cout << sum << endl;
        return;
    }
    priority_queue<ll> pq;
    auto comp = [](const ll &a, const ll &b){
        return a > b;
    };
    priority_queue<ll,vector<ll>,decltype(comp)>rest(comp);
    rep(i,m) pq.push(a[i]);
    ll target = a.back();
    rep(i,m,n-1ll,1ll){
        if (a[i] == target) break;
        rest.push(a[i]);
    }
    ll inc = 0ll, ct = 0;
    while(!pq.empty()){
        debug(inc,ct,pq,rest);
        while(!pq.empty() && pq.top()+inc == target){
            pq.pop();
        }
        while(!rest.empty() && sz(pq) < m){
            pq.push(rest.top()-inc);
            rest.pop();
        }
        assert(rest.empty() || sz(pq) == m);
        while(!pq.empty() && !rest.empty() && pq.top()+inc > rest.top()){
            ll val = pq.top()+inc;
            pq.pop();
            pq.push(rest.top()-inc);
            rest.pop();
            rest.push(val);
        }
        if (pq.empty()){
            assert(rest.empty());
            break;
        }
        assert(pq.top()+inc < target);
        ll val = target-pq.top()-inc;
        if (!rest.empty()){
            assert(pq.top()+inc <= rest.top());
            val = min(val, rest.top()-pq.top()-inc);
        }
        val = max(val,1ll);
        ct += val;
        inc += val;
    }
    cout << ct << endl;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll target = *max_element(all(a));
    ll req = 0ll;
    rep(i,n) req += target-a[i];
    cout << max((req+m-1ll)/m,target-*min_element(all(a))) << endl;
}


/*

10x9 10


4

1
3 2
1 2 3

1
4 1
1 1 2 2

1
4 2
1 1 2 2

1
5 1
3 3 3 3 3


*/