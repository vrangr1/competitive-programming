/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar 27 21:17:24 IST 2024
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int kc = 0;
    rep(i,n){
        cin >> a[i];
        while(a[i]%k == 0){
            a[i]/=k;
            kc++;
        }
    }
    if (n == 1) return void(cout << "1\n");
    sort(rall(a));
    int sol = 0;
    auto get = [](ll v, ll k, ll t) -> pair<ll,ll> {
        int sol = 0;
        while(v < t){
            v*=k;
            sol++;
        }
        return {sol,v};
    };
    multiset<ll> st, rem;
    rep(i,n){
        if (a[i] >= i+1){
            st.insert(a[i]);
        }
        else rem.insert(a[i]);
        debug(i+1,st,rem);
        while(sz(st) < i+1 && !rem.empty()){
            auto [cur,v] = get(*rem.rbegin(),k,i+1);
            if (kc < cur) return void(cout << sol << endl);
            rem.erase(prev(rem.end()));
            kc-=cur;
            st.insert(v);
        }
        assert(sz(st) == i+1);
        while(*st.begin() < i+1){
            auto [cur,v] = get(*st.begin(),k,i+1);
            if (kc < cur) return void(cout << sol << endl);
            st.erase(st.begin());
            kc -=cur;
            st.insert(v);
        }
        sol = i+1;
    }
    cout << sol << endl;
}

/*

3

1
5 2
3 5 4 1 10

1
2 3
9 1

1
3 2
2 16 2


*/