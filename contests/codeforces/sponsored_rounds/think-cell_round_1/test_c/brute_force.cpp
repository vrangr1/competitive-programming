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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] += i+1ll;
    }
    set<ll> st;
    while(n--){
        assert(sz(a) == n+1ll);
        ll cur = LLONG_MIN, last = n-1ll, ind = n+1ll;
        rep(i,n,0ll,-1ll){
            if (a[i] > cur && st.find(a[i]) == st.end()){
                cur = a[i];
                last = i;
                ind = i;
                continue;
            }
            if (a[i] > cur) continue;
            if (a[i] < cur) continue;
            assert(a[i] == cur);
            bool wrong = false;
            rep(j,i+1ll,last-1ll,1){
                if (st.find(a[j]) == st.end()){
                    wrong = true;
                    break;
                }
            }
            if (wrong) continue;
            ind = i;
        }
        debug(a,n,st,cur,last,ind);
        if (ind == n+1ll){
            assert(st.find(a.front()) != st.end());
            a.erase(a.begin());
            continue;
        }
        rep(i,ind+1ll,n,1)
            a[i]--;
        assert(st.find(a[ind]) == st.end());
        st.insert(a[ind]);
        a.erase(a.begin()+ind);
    }
    vector<ll> sol(rall(st));
    print_vec(sol);
}


/*
3

1
2
2 1

1
5
1 100 1000 1000000 1000000000

1
3
6 4 8


*/