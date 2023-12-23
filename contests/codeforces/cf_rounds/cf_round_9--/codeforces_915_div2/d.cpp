/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 16 21:37:47 IST 2023
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

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    ll ans = 0;
    ll res = n;
    vector<int> s{-1};
    debug(p,ans,res,endl);
    for (int i = 0; i < 2 * n; i++) {
        debug(i,p,s);
        while (s.size() > 1 && p[i % n] < p[s.back() % n]) {
            int x = s.back();
            s.pop_back();
            res -= 1LL * p[x % n] * (x - s.back());
        }
        res += 1LL * p[i % n] * (i - s.back());
        s.push_back(i);
        if (i >= n) {
            ans = max(ans, res);
        }
        debug('p',res,s,ans,endl);
    }
    
    cout << ans << "\n";
}

void solve1(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<pair<ll,ll>> dq;
    ll s = 0ll, mex = 0ll;
    set<ll> st;
    rep(i,n){
        st.insert(a[i]);
        while(st.find(mex) != st.end())
            mex++;
        if (dq.empty() || dq.back().first < mex)
            dq.emplace_back(mex,1);
        else dq.back().second++;
        s += mex;
    }
    ll sol = s;
    rep(i,n){
        s -= dq.front().first;
        dq.front().second--;
        if (dq.front().second == 0) dq.pop_front();
        ll cur = 0ll;
        while(!dq.empty() && dq.back().first > a[i]){
            cur += dq.back().second;
            s -= dq.back().first * dq.back().second;
            dq.pop_back();
        }
        if (dq.empty() || dq.back().first < a[i])
            dq.emplace_back(a[i], cur);
        else dq.back().second += cur;
        s += dq.back().first * dq.back().second;
        s += n;
        dq.emplace_back(n,1);
        sol = max(sol, s);
    }
    cout << sol << endl;
}