#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
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
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

const int maxlen = 2e5+1;
const ll mod = 998244353;
 
vector<ll> fact_inverse(maxlen + 1);
vector<ll> num_inverse(maxlen+1);
vector<ll> fact(maxlen+1);
 
void inverse_num(){
    num_inverse[0] = num_inverse[1] = 1;
    rep(i,2,maxlen,1)
        num_inverse[i] = num_inverse[mod%(ll)i]*(mod-mod/(ll)i)%mod;
}

void inverse_fact(){
    fact_inverse[0] = fact_inverse[1] = 1;
    rep(i,2,maxlen,1)
        fact_inverse[i] = (num_inverse[i]*fact_inverse[i-1])%mod;
}

void factorial(){
    fact[0] = 1;
    rep(i,1,maxlen,1)
        fact[i] = (fact[i-1]*(ll)i)%mod;
}
 
inline ll ncr(ll n, ll r){
    if (r == 0ll) return 1ll;
    if (r == 1ll) return n;
    return (((fact[n]*fact_inverse[r]) % mod) * ((fact_inverse[n-r])%mod))%mod;
}

void init(){
    static bool init_done = false;
    if(init_done) return;
    init_done = true;
    inverse_num();
    inverse_fact();
    factorial();
}

void solve(){
    init();
    string s; cin >> s;
    int n = s.size();
    vector<int> counts;
    char last = s[0];
    counts.push_back(1);
    rep(i,1,n-1,1){
        if (s[i] == last){
            counts[counts.size()-1]++;
            continue;
        }
        last = s[i];
        counts.push_back(1);
    }
    ll ans = 1, len = 0;
    rep(i,counts.size()){
        len += counts[i]-1;
        ans = (ans * ncr(counts[i],counts[i]-1ll))%mod;
    }
    assert(len < fact.size());
    ans = (ans * fact[len])%mod;
    cout << len << " " << ans << endl;
}