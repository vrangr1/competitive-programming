/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Dec 28 20:27:13 IST 2023
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

class fentree{
private:
    int n;
    vector<int> tree;
public:
    fentree(int gn){
        n = gn;
        gn++;
        tree.assign(gn,0);
    }

    void update(int ind){
        for(ind++;ind<=n;ind+=(ind&(-ind)))
            tree[ind]++;
    }

    int query(int ind){
        int res = 0;
        for(ind++; ind > 0; ind-=(ind&(-ind)))
            res += tree[ind];
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> c;
    rep(i,n){
        int u, v; cin >> u >> v;
        c.push_back({u,0,i});
        c.push_back({v,1,i});
    }
    sort(all(c),[](const vector<int> &u, const vector<int> &v){
        return u[0] < v[0];
    });
    rep(i,2*n){
        if (c[i][1]) b[c[i][2]] = i;
        else a[c[i][2]] = i;
    }
    fentree ft(2*n);
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j){
        return b[i] < b[j];
    });
    ll sol = 0;
    rep(i,n){
        int ind = order[i];
        sol += (ll)(i - ft.query(a[ind]));
        ft.update(a[ind]);
    }
    cout << sol << endl;
}