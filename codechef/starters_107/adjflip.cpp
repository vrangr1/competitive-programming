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
#define yes "Yes\n"
#define no "No\n"
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
    string s; cin >> s;
    int ct = count(all(s),'1');
    if (ct == n || ct == 0) return void(cout << yes);
    if (n%2 == 0 && ct%2) return void(cout << no);
    vector<pair<int,char>> cts;
    cts.push_back(make_pair(0,s[0]));
    rep(i,n){
        if(s[i] == cts.back().second)
            cts.back().first++;
        else{
            cts.push_back(make_pair(1,s[i]));
        }
    }
    int k = cts.size();
    debug(cts);
    vector<pair<int,char>> f = {cts[0]};
    for (int i = 1; i < k; ++i){
        if (f.back().first%2 == 0 && cts[i].first%2 == 0)
            continue;
        else if (f.back().first%2 != cts[i].first%2){
            f.back().first += cts[i].first;
            if (cts[i].first%2) f.back().second = cts[i].second;
            pair<int,char> cur = f[f.size()-1];
            f.pop_back();
            while(!f.empty() && (f.back().first%2 != cur.first%2 || cur.first%2 == 0)){
                f.back().first += cur.first;
                if (cur.first%2) f.back().second = cur.second;
                cur = f[f.size()-1];
                f.pop_back();
            }
            f.push_back(cur);
        }
        else if (f.back().second == cts[i].second){
            f.back().first += cts[i].first;
            pair<int,char> cur = f.back();
            f.pop_back();
            while(!f.empty() && (f.back().first%2 != cur.first%2 || cur.first%2 == 0)){
                f.back().first += cur.first;
                if (cur.first%2) f.back().second = cur.second;
                cur = f[f.size()-1];
                f.pop_back();
            }
            f.push_back(cur);
        }
        else f.push_back(cts[i]);
    }
    debug(f);
    if (n%2){
        if (f.size() > 1) cout << no;
        else cout << yes;
        return;
    }
    if (f.size() == 1) cout << yes;
    else cout << no;
}