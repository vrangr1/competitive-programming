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
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define qwe(r,t,y)
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
    int n; cin >> n;
    if (n == 1) return void(cout << "1\n");
    if (n == 2){
        cout << "1 2\n";
        cout << "4 3\n";
        return;
    }
    vector<int> odd, even;
    int n2 = n*n;
    rep(i,1,n2,1)
        if (i%2) odd.push_back(i);
        else even.push_back(i);

    vector<vector<int>> mat(n,vector<int>(n,-1));
    rep(i,n){
        if (mat[i][0] == -1){
            assert(sz(odd));
            mat[i][0] = odd.back();
            odd.pop_back();
        }
    }
    rep(i,n){
        if (mat[0][i] == -1){
            assert(sz(odd));
            mat[0][i] = odd.back();
            odd.pop_back();
        }
    }
    rep(i,n){
        rep(j,n){
            if (mat[i][j] != -1) continue;
            if (j == n){
                assert(sz(even));
                mat[i][j] = even.back();
                even.pop_back();
                continue;
            }
            if (sz(odd)){
                assert(i < n);
                
            }
        }
    }
}