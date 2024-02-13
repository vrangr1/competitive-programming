/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb 13 09:31:38 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
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
    vector<int> a(n), d(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> d[i];
    if (n == 1) return void(cout << "0\n");
    vector<int> inds;
    set<int> rem;
    vector<int> nxt(n), prev(n);
    rep(i,n){
        prev[i] = i-1;
        nxt[i] = i+1;
        rem.insert(i);
        if (i == 0 && d[i] < a[i+1]) inds.push_back(i);
        else if (i == n-1 && d[i] < a[i-1]) inds.push_back(i);
        else if (d[i] < a[i-1] + a[i+1]) inds.push_back(i);
    }
    auto upd = [&](int ind){
        if (nxt[ind] != n) prev[nxt[ind]] = prev[ind];
        if (prev[ind] != -1) nxt[prev[ind]] = nxt[ind];
    };
    auto valid_del = [&](int ind) -> bool {
        assert(ind >= 0 && ind < n);
        if (prev[ind] == -1 && nxt[ind] == n) return false;
        if (prev[ind] == -1)
            return d[ind] < a[nxt[ind]];
        if (nxt[ind] == n)
            return d[ind] < a[prev[ind]];
        return d[ind] < a[nxt[ind]] + a[prev[ind]];
    };
    rep(r,n){
        if (sz(rem) <= 1){
            cout << 0 << " \n"[r==n-1];
            continue;
        }
        int ct = 0;
        vector<int> ins, upds;
        while(!inds.empty()){
            int ind = inds.back();
            if (rem.find(ind) == rem.end()){
                inds.pop_back();
                continue;
            }
            if (valid_del(ind)){
                ct++;
                rem.erase(ind);
                upds.push_back(ind);
                if (prev[ind] != -1) ins.push_back(prev[ind]);
                if (nxt[ind] != n) ins.push_back(nxt[ind]);
            }
            inds.pop_back();
        }
        for (int ind : upds)
            upd(ind);
        swap(ins,inds);
        cout << ct << " \n"[r==n-1];
    }
}