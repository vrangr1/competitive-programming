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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k >= n-1){
        sort(all(s));
        cout << s << endl;
        return;
    }
    string t = s;
    sort(all(t));
    string res, fpor = t.substr(0,(k+1)/2), lpor = t.substr(n-(k/2)-1);
    unordered_multiset<char> st(all(fpor)), lt(all(lpor));
    vector<bool> mark(n,false);
    rep(i,n-1,0,-1){
        if (mark[i]) continue;
        if (st.find(s[i]) == st.end()) continue;
        mark[i] = true;
        st.erase(st.find(s[i]));
    }
    rep(i,0,n-1,1){
        if (mark[i] || lt.find(s[i]) == lt.end()) continue;
        mark[i] = true;
        lt.erase(lt.find(s[i]));
    }
    res += fpor;
    rep(i,n)
        if (mark[i]) continue;
        else res.push_back(s[i]);
    res += lpor;
    cout << res << endl;
}