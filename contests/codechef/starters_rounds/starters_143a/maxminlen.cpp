/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 17 20:17:09 IST 2024
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
// source: https://codeforces.com/blog/entry/88193
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

bool exist(ordered_set &s, ll x) {
    if((s.upper_bound(x))==s.end()) return 0;
    return ((*s.upper_bound(x))==x);
}

void erase(ordered_set &s,int x) {
    if(exist(s,x)) s.erase(s.upper_bound(x));
}

ll first_idx(ordered_set &s, ll x){
    if(!exist(s,x)) return -1;
    return s.order_of_key(x);
}

ll value(ordered_set &s, ll idx) { 
   return (*s.find_by_order(idx));
}

ll last_idx(ordered_set &s, ll x) {
    if (!exist(s,x)) return -1;
    if (value(s,sz(s)-1)==x) return (int)(s.size())-1;
    return first_idx(s,*s.lower_bound(x))-1;
}

ll count(ordered_set &s, ll x) {
    if(!exist(s,x)) return 0;
    return last_idx(s,x)-first_idx(s,x)+1;
}
// END OF SNIPPETS

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
    sort(all(a));
    ordered_set ost;
    map<ll,ll> mp;
    ost.insert(a[0]);
    mp[a[0]]++;
    ll sol = 0ll;
    rep(i,1,n-1,1) {
        ll diff = a[i]-i, m = sz(ost);
        ll cur = m-ost.order_of_key(diff-1ll);
        debug(endl,i,diff,cur,m);
        cur -= mp[a[i]-1ll] + mp[a[i]];
        debug(mp[a[i]-1ll],mp[a[i]],cur);
        assert(cur >= 0ll);
        sol += cur;
        ost.insert(diff);
        mp[a[i]]++;
    }
    cout << sol << endl;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    map<ll,ll> left,right;
    right[a.back()] = 1ll;
    rep(i,n-2ll,0ll,-1ll)
        right[a[i]] = right[a[i]+1ll]+1ll;
    left[a[0]] = 1ll;
    rep(i,1,n-1ll,1) 
        left[a[i]] = left[a[i]-1ll]+1ll;
    ll sol = 0ll;
    rep(i,n) {
        sol += (left[a[i]]*right[a[i]+2ll]);
    }
    cout << sol << endl;
}