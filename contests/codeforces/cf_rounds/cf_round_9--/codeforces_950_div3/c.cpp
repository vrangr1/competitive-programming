/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jun  3 20:16:07 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

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
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int m; cin >> m;
    vector<int> d(m);
    rep(i,m) cin >> d[i];
    multiset<int> mod, same;
    rep(i,n) {
        if (a[i] == b[i])
            same.insert(a[i]);
        else mod.insert(b[i]);
    }
    bool fd = false;
    rep(i,m-1,0,-1) {
        auto itm = mod.find(d[i]);
        auto its = same.find(d[i]);
        if (!fd && itm == mod.end() && its == same.end()) {
            return void(cout << no);
        }
        if (!fd && itm == mod.end()) {
            fd = true;
            continue;
        }
        if (!fd) {
            fd = true;
            same.insert(d[i]);
            mod.erase(itm);
            continue;
        }
        if (itm == mod.end()) continue;
        mod.erase(itm);
        same.insert(d[i]);
    }
    if (mod.empty()) cout << yes;
    else cout << no;
}