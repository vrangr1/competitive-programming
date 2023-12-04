/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Dec  3 20:41:37 IST 2023
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

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

// const int beg = 0, ed = 1;

class trie{
public:
    ll ct;
    map<char,trie*> children;
    trie():ct(0ll){}
};

// const int maxpool = 2300000;

// trie nodepool[maxpool];
// int nodect;
// trie* get_node(){
//     // assert(nodect < maxpool);
//     nodepool[nodect].ct = 0;
//     nodepool[nodect].children.clear();
//     return &nodepool[nodect++];
// }

inline int get_ind(const char &ch){
    return (int)(ch-'a');
}

void insert(trie *node, const string &word){
    rep(i,sz(word)){
        if (node->children.find(word[i]) == node->children.end())
            // node->children[word[i]] = get_node();
            node->children[word[i]] = new trie();
        node->ct++;
        node = node->children[word[i]];
    }
    node->ct++;
}

ll compute(trie *node, const string &word){
    ll len = 0ll, curlen = sz(word);
    rep(i,sz(word)){
        if (node->children.find(word[i]) == node->children.end()){
            len += curlen*(node->ct);
            break;
        }
        len += (curlen)*(node->ct - node->children[word[i]]->ct);
        curlen--;
        node = node->children[word[i]];
    }
    return len;
}

void solve(){
    ll n; cin >> n;
    vector<string> s(n);
    // nodect = 0;
    // trie *froot = get_node(), *broot = get_node();
    trie *froot = new trie(), *broot = new trie();
    string temp;
    rep(i,n){
        cin >> s[i];
        insert(froot, s[i]);
        temp = s[i];
        reverse(all(temp));
        insert(broot, temp);
    }
    ll len = 0ll;
    debug(n,endl);
    rep(i,n){
        debug(i,s[i],len);
        len += compute(broot, s[i]);
        debug(len);
        temp = s[i];
        reverse(all(temp));
        len += compute(froot, temp);
        debug(len,endl);
        // ll right = cts[get_ind(s[i].front())][ed];
        // ll left = cts[get_ind(s[i].back())][beg];
        // debug(i,sz(s[i]),s[i].front(),s[i].back(),left,right,endl);
        // len += right*((ll)sz(s[i]) - 1ll) + (n-right)*((ll)sz(s[i]));
        // len += left*((ll)sz(s[i])-1ll) + (n-left)*((ll)sz(s[i]));
    }
    cout << len << endl;
}