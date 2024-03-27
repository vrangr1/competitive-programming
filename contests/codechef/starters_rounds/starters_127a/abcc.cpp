/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar 27 20:27:05 IST 2024
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
#define debug(...) 42
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
#define mt make_tuple
#define space " "
#define yes "Yes\n"
#define no "No\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << yes);
    {
        string c = a, d = b;
        sort(all(c));
        sort(all(d));
        if (c!=d) return void(cout << no);
    }
    if (count(all(a),'b') == 0) return void(cout << no);
    vector<int> act(n,0), cct(n,0);
    rep(i,n){
        if (i){
            act[i] = act[i-1];
            cct[i] = cct[i-1];
        }
        if (a[i] == b[i]) continue;
        if (a[i] == 'b' || b[i] == 'b') return void(cout << no);
        if (a[i] == 'a') act[i]++;
        else cct[i]++;
    }
    auto get = [&](int i, int j) -> pair<int,int> {
        assert(j >= i);
        assert(j >= 0 && j < n);
        assert(i >= 0 && i < n);
        int ma = act[j], mc = cct[j];
        if (i){
            ma-=act[i-1];
            mc-=cct[i-1];
        }
        return {ma,mc};
    };
    vector<int> inds = {0};
    for (int i = 0; i < n; ++i){
        if (a[i] == 'b') inds.push_back(i);
    }
    inds.push_back(n-1);
    debug(inds);
    debug(act,cct);
    auto [lla,llc] = get(inds[0],inds[1]);
    for (int i = 1; i < sz(inds)-1; ++i){
        int nxt = inds[i+1], cur = inds[i];
        int la = lla, lc = llc; 
        auto [ra,rc] = get(cur,nxt);
        debug(i,cur,nxt,la,lc,ra,rc,lla,llc,endl);
        int t1 = min(la,rc), t2 = min(lc,ra);
        la -= t1;
        rc -= t1;
        lla = la+ra;
        llc = lc+rc;
    }
    if (lla == 0 && llc == 0) return void(cout << yes);
    else cout << no;
}

void solve1(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << yes);
    {
        string c = a, d = b;
        sort(all(c));
        sort(all(d));
        if (c!=d) return void(cout << no);
    }
    if (count(all(a),'b') == 0) return void(cout << no);
    int c = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] == b[i]) continue;
        if (a[i] == 'b' || b[i] == 'b') return void(cout << no);
        if (a[i] == 'a') c++;
        else c--;
        if (c < 0) return void(cout << no);
    }
}