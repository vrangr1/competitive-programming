#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

// ld compute(int ind, const int cur, const vector<ld> &p, vector<pair<ld,int>> &dp){
//     vector<ld> vals = {p[cur],p[ind]};
//     while(dp[ind].second != -1){
//         ind = dp[ind].second;
//         vals.push_back(p[ind]);
//     }
//     ld k = vals.size();
//     ld nom = 0, coeff = 1.0;
//     const ld mult = 0.9;
//     rep(i,k){
//         nom += (coeff*vals[i]);
//         coeff *= mult;
//     }
//     nom /= (((ld)10)*((ld)1-powl(0.9,k)));
//     nom -= (((ld)1200)/(sqrtl(k)));
//     return nom;
// }

ld compute(int ind, const int cur, const vector<ld> &p, vector<pair<ld,int>> &dp){
    ld last = dp[ind].first, len = dp[ind].second;
    last += (((ld)1200)/sqrtl(len));
    last *= (((ld)10)*((ld)1-powl(0.9,len)));
    last *= ((ld)0.9);
    last += (p[cur]);
    len++;
    last /= (((ld)10)*((ld)1-powl(0.9,len)));
    last -= (((ld)1200)/(sqrtl(len)));
    return last;
}

ld compute(vector<ld> &vals){
    ld k = vals.size();
    ld coeff = 1ll;
    const ld mult = 0.9;
    ld rating = 0ll;
    rep(i,k){
        rating += (coeff*vals[i]);
        coeff *= mult;
    }
    rating /= (((ld)10)*((ld)1-powl(mult,k)));
    rating -= (((ld)1200)/(sqrtl(k)));
    return rating;
}

void solve1(){
    ld n; cin >> n;
    vector<ld> p(n);
    rep(i,n) cin >> p[i];
    vector<pair<ld,int>> dp(n, make_pair(LLONG_MIN,-1));
    dp[0] = make_pair(p[0]-1200,1);
    ld maxval = dp[0].first;
    rep(i,n){
        if (i == 0) continue;
        rep(j,i){
            ld cur = compute(j, i, p, dp);
            if (dp[i].second == -1 || cur > dp[i].first){
                dp[i].first = cur;
                dp[i].second = dp[j].second+1.0;
            }
        }
        maxval = max(maxval, dp[i].first);
    }
    // debug(dp);
    cout << fixed << setprecision(8) << maxval << endl;
}

void solve(){
    ld n; cin >> n;
    vector<ld> p(n);
    rep(i,n) cin >> p[i];
    vector<ld> vals;
    rep(i,n-1,0,-1){
        while(!vals.empty() && vals.back() < p[i]){
            vals.pop_back();
        }
        vals.push_back(p[i]);
    }
    debug(vals);
    cout << fixed << setprecision(8) << compute(vals) << endl;
}