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
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve(int T);

int main(){
	fastIO;
	int T;cin>>T;for(int t = 1; t <= T; ++t)solve(t);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}




// vector<ll> get_prime_factorization(ll num){
//     vector<ll> pfac;
//     ll fac = 2ll;
//     while(num%fac == 0ll){
//         num/=fac;
//         pfac.push_back(fac);
//     }
//     for (fac = 3ll; fac <= sqrt(num) && num > 1ll; fac+=2ll){
//         while(num%fac == 0ll){
//             num/=fac;
//             pfac.push_back(fac);
//         }
//     }
//     if (num > 1ll) pfac.push_back(num);
//     return pfac;
// }


vector<set<vector<int>>> dp(42);
vector<vector<int>> allvecs;

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    rep(n,1,41,1){
        dp[n].insert({n});
        rep(p, 1, n-1, 1){
            for(auto vec : dp[p]){
                vec.push_back(n-p);
                sort(all(vec));
                dp[n].insert(vec);
            }
        }
    }
    allvecs = vector<vector<int>> (dp[41].begin(), dp[41].end());
    sort(all(allvecs), [](const vector<int> &a, const vector<int> &b){
        return a.size() < b.size();
    });
}

void solve(int T){
    cout << "Case #" << T << ": ";
    ll p; cin >> p;
    init();
    ll prod = 1ll;
    for (auto &vec : allvecs){
        prod = 1ll;
        for (auto num : vec){
            prod *= num;
            if (prod > p) break;
        }
        if (prod == p){
            cout << vec.size() << " ";
            rep(i,(int)vec.size())
                cout << vec[i] << " \n"[i==(int)vec.size()-1];
            return;
        }
    }
    cout << "-1\n";
}