/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May  8 20:16:26 IST 2024
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

void solve1(){
    int n; cin >> n;
    string s; cin >> s;
    {
        s = s.substr((int)(find(all(s),'a')-s.begin()));
        while(!s.empty()){
            if (s.back() == 'c') break;
            s.pop_back();
        }
        n = sz(s);
    }
    auto it = find(all(s),'b');
    if (it == s.end()) return void(cout << "0\n");
    int ind = (int)(it-s.begin());
    auto it2 = find(rall(s),'b');
    int ind2 = (int)(it2-s.rbegin());
    int a = (int)count(s.begin(),s.begin()+n-ind2-1,'a');
    int c = (int)count(s.rbegin(),s.rbegin()+n-ind-1,'c');
    int sol = min(a,c);
    cout << sol << endl;
}

void solve2() {
    int n; cin >> n;
    string s; cin >> s;
    int sol = INT_MAX;
    vector<int> act(n), cct(n);
    act[0] = s[0]=='a';
    cct[0] = s[0]=='c';
    rep(i,1,n-1,1){
        act[i] = act[i-1] + (s[i]=='a');
        cct[i] = cct[i-1] + (s[i]=='c');
    }
    auto geta = [&](int i, int j) -> int {
        if (i > j) swap(i,j);
        if (!i) return act[j];
        return act[j]-act[i-1];
    };
    auto getc = [&](int i, int j) -> int {
        if (i > j) swap(i,j);
        if (!i) return cct[j];
        return cct[j]-cct[i-1];
    };
    int last = 0, cur = 0;
    rep(i,n) {
        if (s[i] != 'b') continue;
        int a = geta(last,i), c = getc(i,n-1);
        if (c <= a) {
            cur += c;
            break;
        }
        cur += a;
        last = i;
    }
    sol = cur;
    last = n-1;
    cur = 0;
    rep(i,n-1,0,-1){
        if (s[i] != 'b') continue;
        int a = geta(0,i), c = getc(i,last);
        if (a <= c){
            cur += a;
            break;
        }
        cur += c;
        last = i;
    }
    sol = min(sol,cur);
    cout << sol << endl;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int sol = 0;
    vector<int> act(n), cct(n);
    act[0] = s[0]=='a';
    cct[0] = s[0]=='c';
    rep(i,1,n-1,1){
        act[i] = act[i-1] + (s[i]=='a');
        cct[i] = cct[i-1] + (s[i]=='c');
    }
    auto geta = [&](int i, int j) -> int {
        if (i > j) swap(i,j);
        if (!i) return act[j];
        return act[j]-act[i-1];
    };
    auto getc = [&](int i, int j) -> int {
        if (i > j) swap(i,j);
        if (!i) return cct[j];
        return cct[j]-cct[i-1];
    };
    rep(i,n) {
        if (s[i] != 'b') continue;
        sol = max(sol,min(geta(0,i),getc(i,n-1)));
    }
    cout << sol << endl;
}