/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

vector<ll> segtree;

inline ll get_mid(ll st, ll end){
    return st + (end-st)/2ll;
}

ll get_max_util(ll st, ll end, ll left, ll right, ll ind){
    if (left <= st && right >= end)
        return segtree[ind];
    if (end < left || st > right)
        return -1ll;
    ll mid = get_mid(st,end);
    return max(get_max_util(st, mid, left, right, 2ll*ind + 1ll), get_max_util(mid+1ll, end, left, right, 2ll*ind + 2ll));
}

ll get_max(ll n, ll st, ll end){
    assert(!(st < 0ll || end > n-1ll || st > end));
    return get_max_util(0, n-1ll, st, end, 0ll);
}

ll construct_segtree_util(vector<pair<ll,ll>> &arr, ll st, ll end, ll ind){
    if (st == end){
        segtree[ind] = 2ll*arr[st].first + llabs(arr[st].second - arr[st].first);
        return segtree[ind];
    }
    ll mid = get_mid(st,end);

    segtree[ind] = max(construct_segtree_util(arr, st, mid, ind*2ll + 1ll), construct_segtree_util(arr, mid+1ll, end, ind*2ll + 2ll)); 
    return segtree[ind];
}

void construct_segtree(vector<pair<ll,ll>> &arr){
    ll n = sz(arr);
    ll x = (ll)(ceill(log2l(n)));
    ll max_size = 2ll * (1ll << x) - 1;
    segtree.assign(max_size,0ll);
    construct_segtree_util(arr, 0, n-1ll, 0ll);
}

ll compute(vector<pair<ll,ll>> &alessb, vector<pair<ll,ll>> &agreaterb, ll cursum){
    sort(all(alessb), [](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return a.first < b.first;
    });
    ll mxsum = cursum;
    // construct_segtree(alessb);
    sort(all(agreaterb), [](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return a.second < b.second;
    });
    if (alessb.empty()) return cursum;
    rep(i,(ll)sz(agreaterb)){
        if (alessb.back().first <= agreaterb[i].second) continue;
        mxsum = max(mxsum, cursum + 2ll*(alessb.back().first - agreaterb[i].second));
        // auto iter = lower_bound(all(alessb), make_pair(agreaterb[i].second,-1), [](const pair<ll,ll> &a, const pair<ll,ll> val){
        //     return a.first < val.first;
        // });
        // if (iter == alessb.end()) continue;
        // ll curind = iter - alessb.begin();
        // ll mx = get_max(sz(alessb), curind, sz(alessb)-1ll);
        // mxsum = max(mxsum, cursum - )
    }
    return mxsum;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    ll mxsum = 0ll;
    vector<pair<ll,ll>> alessb, agreaterb;
    rep(i,n){
        cin >> b[i];
        mxsum += llabs(a[i]-b[i]);
        if (a[i] <= b[i])
            alessb.push_back({a[i],b[i]});
        else
            agreaterb.push_back({b[i],a[i]});
    }
    ll ogsum = mxsum;
    mxsum = max(mxsum, compute(alessb, agreaterb, ogsum));
    mxsum = max(mxsum, compute(agreaterb, alessb, ogsum));
    cout << mxsum << endl;
}