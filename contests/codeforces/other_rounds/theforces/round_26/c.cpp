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

void print_answer(const string &w1, const string &w2, const char ch, const int k){
    int i1 = 0, i2 = 0;
    int enc = 0, target = k/10;
    while(i1 < k && i2 < k && enc < target){
        if (w1[i1] != ch){
            cout << w1[i1++];
            continue;
        }
        if (w2[i2] != ch){
            cout << w2[i2++];
            continue;
        }
        cout << ch;
        enc++;
        i1++;
        i2++;
    }
    cout << w1.substr(i1) << w2.substr(i2) << endl;
}

void solve(){
    int k; cin >> k;
    vector<string> words(20);
    rep(i,20) cin >> words[i];
    vector<vector<int>> cts(20,vector<int>(10,0));
    rep(i,20){
        for (char ch : words[i])
            cts[i][(int)(ch-'0')]++;
    }
    rep(i,20){
        unordered_set<char> uset;
        rep(j,10)
            if (cts[i][j] >= (k/10)) uset.insert((char)(j+'0'));
        rep(j,i+1,19,1){
            rep(l, 10){
                char curchar = (char)(l+'0');
                if (cts[j][l] < (k/10) || uset.find(curchar) == uset.end()) continue;
                print_answer(words[i],words[j], curchar, k);
                return;
            }
        }
    }
    cout << "-1\n";
}