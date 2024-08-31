/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Aug 30 19:57:28 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
#endif
// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int l, r; cin >> l >> r;
    vector<int> cts;
    vector<bool> seen(r+1,false);
    rep(f,2,r,1) {
        if (seen[f]) continue;
        int ct = (f>=l);
        // rep(v,max(2*f,l),r,f) {
        for (int v = f*f; v <= r; v*=f) {
            if (v < l) continue;
            if (seen[v]) continue;
            ct++;
            seen[v] = true;
        }
        if (ct > 0)
        cts.push_back(ct);
    }
    if (l == 1) cts.push_back(1);
    debug(cts);
    multiset<int> mst(all(cts));
    int sol = 0;
    while(sz(mst) >= 3) {
        int v1 = *mst.rbegin();
        mst.erase(prev(mst.end()));
        int v2 = *mst.rbegin();
        mst.erase(prev(mst.end()));
        int v3 = *mst.rbegin();
        mst.erase(prev(mst.end()));
        // int cur = min({v1,v2,v3});
        assert(v3 >= 1);
        int cur = 1;
        sol += cur;
        if (v1-cur) mst.insert(v1-cur);
        if (v2-cur) mst.insert(v2-cur);
        if (v3-cur) mst.insert(v3-cur);
    }
    cout << sol << endl;
}

const int maxn = 1005;
vector<int> prime(maxn,true);

void init() {
    rep(v,4,maxn-1,2)
        prime[v] = false;
    rep(f,3,maxn-1,2) {
        if (!prime[f]) continue;
        rep(v,f*2,maxn-1,f)
            prime[v] = false;
    }
}

void solve1() {
    init();
    int l, r; cin >> l >> r;
    int sol = 0;
    rep(i,l,r,1) sol += prime[i];
    cout << sol/3 << endl;
}