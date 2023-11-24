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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class trie{
public:
    int ct = 0;
    vector<trie*> children;
    trie(): children(2,nullptr), ct(0) {}
};

void insert(trie *node, const int val){
    string bval = bitset<20>(val).to_string();
    assert(bval.size() == 20);
    for (int i = 0; i < 20; ++i){
        int ind = (int)(bval[i]-'0');
        if (node->children[ind] == nullptr)
            node->children[ind] = new trie();
        node->ct++;
        node = node->children[ind];
    }
    node->ct++;
}

int find(trie *node){
    int val = 0;
    for (int i = 0; i < 20; ++i){
        int bit = (1<<(19-i));
        if (node->children[1] && node->children[1]->ct%2){
            node = node->children[1];
            val |= bit;
            continue;
        }
        if (node->children[0]){
            node = node->children[0];
            continue;
        }
        assert(node->children[1]);
        node = node->children[1];
        val |= bit;
    }
    return val;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int axor = 0;
    trie *root = new trie();
    rep(i,n){
        cin >> a[i];
        axor ^= a[i];
        insert(root, a[i]);
    }
    int og = axor;
    rep(i,n){
        axor = min(axor,og^a[i]);
    }
    cout << axor << endl;
    // int val = find(root);
    // cout << min(axor^val,axor) << endl;
}