/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Sep 27 19:54:25 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    rep(i,n) {
        ll ind = order[i];
        if (a[ind] < i+1ll) return void(cout << "0\n");
    }
    ll ct = ll(count(all(a),a[order[0]]));
    if (ct == a[order[0]]) {
        cout << ct << endl;
        return;
    }
    cout << n << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> lmn(n), rmn(n);
    rep(i,n) {
        cin >> a[i];
        if (!i) lmn[i] = {a[i]-(n-i-1),0};
        else {
            lmn[i] = lmn[i-1];
            if (lmn[i].first >= a[i]-(n-i-1))
                lmn[i] = {a[i]-(n-i-1),i};
        }
    }
    rep(i,n-1,0,-1)
        if (i == n-1) rmn[i] = {a[i]-i,n-1};
        else {
            rmn[i] = rmn[i+1];
            if (rmn[i].first >= a[i] + i)
                rmn[i] = {a[i]+i,i};
        }
    debug(a,lmn,rmn);
    int sol = 0;
    rep(i,n) {
        // int l = lmn[i]+(n-i-1), r = rmn[i]+i;
        // debug(endl,i,l,r);
        int l = lmn[i].second, r = rmn[i].second;
        while(true) {
            
        }
    }
    cout << sol << endl;
}