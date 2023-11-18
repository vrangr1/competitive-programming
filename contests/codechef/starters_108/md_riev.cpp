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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

vector<ll> primes = {2,3,5,7};
vector<vector<ll>> dp = {{0,1}, {0,2}, {0,3}, {0,4}};

inline bool is_palindrome(ll num){
    string a = to_string(num);
    // if (sz(a)%2){
    int len = sz(a)/2;
    rep(i,len){
        if (a[i]!=a[sz(a)-i-1]) return false;
    }
    return true;
    // }
    // int len = sz(a)/2;

}

inline bool is_palindrome(const string &a){
    int len = sz(a)/2;
    rep(i,len){
        if (a[i]!=a[sz(a)-i-1]) return false;
    }
    return true;
}

bool checkprime(ll n){
    if (n%2 == 0) return false;
    ll srt = sqrt(n);
    for (ll fac = 3ll; fac <= srt; fac+=2ll){
        if (n%fac == 0) return false;
    }
    return true;
}

const ll maxct = 15000;

void iterate(string &a){
    int len = sz(a);
    rep(i,len/2,len-1,1){
        if (a[i] < '9'){
            // debug('p',i,len,a);
            a[i]++;
            // debug(a);
            a[len-i-1] = a[i];
            rep(j,len/2,i-1,1){
                a[j] = '0';
                a[len-j-1] = '0';
            }
            // debug(a);
            // debug('p',a);
            // if (!is_palindrome(a)){
            //     debug(a); exit(0);
            // }
            // assert(is_palindrome(a));
            // return stoll(a);
            return;
        }
    }
    // a.insert()
    for(char &ch:a) ch = '0';
    a.push_back('1');
    a[0] = '1';
    // a = string(len+1,'0');
    // a[0] = a[len] = '1';
    // if (!is_palindrome(a)){
    //     debug(a); exit(0);
    // }
    // debug('n',a);
    // return stoll(a);
}

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    ll i = 11;
    string a = to_string(i);
    while(sz(primes) < maxct){
        // debug(a);
        // if (stoll(a) > 101) break;
        i = stoll(a);
        if (checkprime(i)){
            primes.push_back(i);
            dp.push_back(dp.back());
            dp.back().at(sz(a)%2)++;
        }
        iterate(a);
    }
    cout << primes.back() << endl;
    // debug(primes);
}

void solve(){
    init();
    // ll n; cin >> n; n--;
    // assert(n < sz(dp));
    // print_vec(dp[n]);
}