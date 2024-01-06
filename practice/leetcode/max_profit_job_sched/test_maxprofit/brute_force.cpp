/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> sts(n), edts(n), profit(n);
    rep(i,n) cin >> sts[i];
    rep(i,n) cin >> edts[i];
    rep(i,n) cin >> profit[i];
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j){
        return edts[i] < edts[j];
    });
    {
        vector<int> csts(n),cedts(n),cpt(n);
        rep(i,n){
            int ind = order[i];
            csts[i] = sts[ind];
            cedts[i] = edts[ind];
            cpt[i] = profit[ind];
        }
        swap(sts,csts);
        swap(edts,cedts);
        swap(profit,cpt);
    }
    debug(sts,edts,profit);
    int mxct = 1, last = edts[0];
    rep(i,1,n-1,1){
        if (sts[i] < last) continue;
        mxct++;
        last = edts[i];
    }
    vector<int> sel(n);
    auto valid = [&]() -> int {
        int last = -1, cur = 0;
        rep(i,n){
            if (!sel[i]) continue;
            if (sts[i] < last) return false;
            last = edts[i];
            cur += profit[i];
        }
        return cur;
    };
    int mx = 0;
    rep(ct,mxct+1){
        fill(sel.begin(),sel.begin()+(n-ct),0);
        fill(sel.begin()+(n-ct),sel.end(),1);
        do{
            int cur = valid();
            mx = max(mx,cur);
        }while(next_permutation(all(sel)));
    }
    cout << mx << endl;
}