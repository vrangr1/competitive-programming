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

vector<ll> ftree;
ll fn;

ll get_sum(ll ind){
    ll sum = 0;
    ind++;
    while (ind > 0){
        sum += ftree[ind];
        ind -= (ind &(-ind));
    }
    return sum;
}

void update_ftree(ll ind, ll val){
    ind++;
    while (ind <= fn){
        ftree[ind] += val;
        ind += (ind&(-ind));
    }
}

void construct_ftree(const vector<ll> &a){
    fn = sz(a);
    ftree.assign(fn+1,0);
    rep(i,fn) update_ftree(i,a[i]);
}

void construct_ftree(ll n){
    fn = n;
    ftree.assign(fn+1,0);
}

ll binary_search(ll low, ll high, ll val, bool highest = true){
    assert(low <= high);
    if (low == high) return low;
    ll mid;
    if (highest) mid = (low+high+1ll)/2ll;
    else mid = (low+high)/2ll;
    ll s = get_sum(mid);
    if (highest){
        assert(s>=val);
        if (s > val) return binary_search(low, mid-1ll, highest);
        return binary_search(mid,high,highest);
    }
    assert(s<=val);
    if (s < val) return binary_search(mid+1,high,highest);
    return binary_search(low,mid,highest);
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    priority_queue<pair<int,int>> pq;
    rep(i,n){
        cin >> a[i];
        pq.push({a[i],i});
    }
    construct_ftree(n);
    unordered_map<string,ll> ump;
    string key = "0;" + to_string(n-1ll);
    ump[key] = 0ll;
    ll last = -1;
    while(pq.size() > 0){
        while(!pq.empty()){
            
        }
    }
}