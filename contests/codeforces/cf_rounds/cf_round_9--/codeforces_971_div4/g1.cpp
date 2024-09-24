/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep  3 21:07:45 IST 2024
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

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    debug(a);
    rep(i,n) a[i]-=i;
    debug(a);
    vector<int> sol(n);
    map<int,int> freq;
    set<pair<int,int>> mxf;
    rep(i,k) {
        freq[a[i]]++;
        mxf.emplace(freq[a[i]],a[i]);
        if (freq[a[i]] > 1) mxf.erase({freq[a[i]]-1,a[i]});
    }
    assert(!mxf.empty());
    sol[0] = k-mxf.rbegin()->first;
    debug(endl,0,freq,mxf);
    rep(i,k,n-1,1) {
        freq[a[i]]++;
        mxf.emplace(freq[a[i]],a[i]);
        if (freq[a[i]] > 1) mxf.erase({freq[a[i]]-1,a[i]});
        mxf.erase({freq[a[i-k]],a[i-k]});
        freq[a[i-k]]--;
        if (freq[a[i-k]] > 0) mxf.emplace(freq[a[i-k]],a[i-k]);
        debug(endl,i-k+1,freq,mxf);
        sol[i-k+1] = k-mxf.rbegin()->first;
    }
    debug(sol);
    while(q--) {
        int l, r; cin >> l >> r;
        --l;--r;
        cout << sol[l] << endl;
    }
}