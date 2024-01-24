/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jan 21 01:42:28 IST 2024
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class trie{
public:
    int bit, enc, mxind;
    vector<trie*> children;
    trie *parent;

    trie(int val, trie *p):children(2,nullptr){
        bit = val;
        enc = 0;
        mxind = INT_MIN;
        parent = p;
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    trie *root = new trie('-1',nullptr);
    auto insert = [&](int ind){
        int val = a[ind];
        string s = bitset<30>(val).to_string();
        int sn = sz(s);
        trie *node = root;
        rep(i,sn){
            int bit = s[i]-'0';
            if (node->children[bit] == nullptr)
                node->children[bit] = new trie(bit,node);
            node->enc++;
            node->mxind = max(node->mxind,ind);
            node = node->children[bit];
        }
        node->enc++;
        node->mxind = max(node->mxind,ind);
    };
    auto match = [&](int ind){
        int val = a[ind];
        int t = val^k;
        string s = bitset<30>(t).to_string();
        int sn = sz(s);
        trie *node = root;
        rep(i,sn){
            int bit = s[i]-'0';
            if (node->children[bit] == nullptr) return INT_MIN;
            node = node->children[bit];
        }
        return node->mxind;
    };
    auto reset = [](trie *node){
        if (node->enc == 0) node->mxind = INT_MIN;
        node = node->parent;
        while(node != nullptr){
            node->mxind = INT_MIN;
            if (node->children[0] && node->children[0]->enc > 0)
                node->mxind = max(node->mxind, node->children[0]->mxind);
            if (node->children[1] && node->children[1]->enc > 0)
                node->mxind = max(node->mxind, node->children[1]->mxind);
            node = node->parent;
        }
    };
    auto remove = [&](int ind){
        int val = a[ind];
        string s = bitset<30>(val).to_string();
        int sn = sz(s);
        trie *node = root;
        rep(i,sn){
            int bit = s[i]-'0';
            assert(node->children[bit] != nullptr);
            assert(node->enc > 0);
            node->enc--;
            node = node->children[bit];
        }
        assert(node->enc > 0);
        node->enc--;
        
        // Resetting node->mnind
        reset(node);
    };
    auto error_ind = [&](int val) -> int {
        string s = bitset<30>(val).to_string();
        int sn = sz(s);
        trie *node = root;
        rep(i,sn){
            int bit = s[i]-'0';
            if (val < k){
                if (bit == 1) return node->mxind;
                if (val + (1<<(sn-i-1)) < k) return node->mxind;
            }
            if (node->children[bit] == nullptr) return INT_MIN;
            node = node->children[bit];
            if (bit == 1) val ^= (1<<(sn-i-1));
        }
        return INT_MIN;
    };
    int left = 0, right = 1, last = INT_MIN;
    insert(0);
    int sol = 0;
    while(right < n){
        int eind;
        while(right < n){
            eind = error_ind(a[right]);
            assert(eind == INT_MIN || eind >= left);
            if (eind >= left) break;
            int mxind = match(right);
            right++;
            if (mxind == INT_MIN) continue;
            assert(mxind >= left);
            assert(mxind < right);
            sol += (mxind-left+1);
        }
        assert(right == n || eind >= left);
        if (right == n){
            
        }
    }
}