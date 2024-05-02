/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  1 20:38:31 IST 2024
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
    vector<int> f(n);
    rep(i,n) cin >> f[i];
    int mex = (int)(find(all(f),0) - f.begin());
    vector<int> sol(n+1);
    rep(i,mex)
        sol[i] = f[i];
    sol[mex] = 0;
    auto proc = [&](auto &&self, int v) -> int {
        if (v == 0) return -1;
        int t = v/2;
        if (f[t] == 1) {
            int s = self(self,t);
            if (s == -1) return -1;
            assert(f[t] >= 2);
            f[t]--;
            f[v]++;
            return s + 1;
        }
        f[t]--;
        f[v]++;
        return 1;
    };
    int cur = 0;
    rep(i,mex+1,n,1) {
        assert(i);
        if (sol[i-1] == -1){
            sol[i] = -1;
            continue;
        }
        sol[i] = cur;
        if (f[i-1] == 0){
            int temp = proc(proc,i-1);
            if (temp == -1){
                sol[i] = -1;
                continue;
            }
            cur += temp;
            sol[i] = cur;
        }
        if (i < n && f[i] > 0)
            sol[i] += f[i];
    }
    print_vec(sol);
}