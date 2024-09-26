/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 25 20:00:15 IST 2024
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

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1() {
    int n; cin >> n;
    vector<int> p(n+1);
    rep(i,n) cin >> p[i+1];
    if (is_sorted(all(p))) return void(cout << "0\n");
    vector<int> ind(n+1);
    rep(i,1,n,1)
        ind[p[i]] = i;
    int k = 0;
    rep(v,n,1,-1) {
        if (ind[v] == v) continue;
        k = max(k, p[v]+v);
        swap(ind[v],ind[p[v]]);
        swap(p[ind[v]],p[ind[p[v]]]);
    }
    debug(p);
    cout << k << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n+1);
    int k = 0;
    rep(i,1,n,1) {
        cin >> p[i];
        if (i != p[i]) k = max(k,p[i]+1);
    }
    cout << k << endl;
}