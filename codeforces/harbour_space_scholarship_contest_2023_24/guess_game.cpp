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
* Nick : vrangr
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
#define debug
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
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
#define mod ((ll)998244353)
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

class trie{
public:
    int val;
    bool end;
    ll count, depth;
    vector<trie*> children;
    trie(int val, int depth) : children(2,nullptr){
        this->val = val;
        this->end = false;
        this->count = 0ll;
        this->depth = depth;
        // assert(this->val >= 0 && this->val <= 1); // TODO: Remove this eventually;
    }
};

void insert(string number, trie *node){
    int n = number.size(), num;
    for (int i = 0; i < n; ++i){
        node->count++;
        num = (int)(number[i]-'0');
        if (node->children[num] == nullptr)
            node->children[num] = new trie(num, node->depth + 1);
        node = node->children[num];
    }
    node->count++;
    node->end = true;
}

inline ll nc2(ll n){
    if (n&1) return (n * ((n-1ll)/2ll)) % mod;
    return ((n/2ll) * (n-1ll)) % mod;
}

void inverse_recursion(ll a, ll b, ll &x, ll &y){
    ll x1, y1;
    if (a == 0ll){
        x = 0;
        y = 1;
        return;
    }
    inverse_recursion(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
}

ll get_inverse(ll q, ll b){
    ll x, y;
    inverse_recursion(q, b, x, y);
    if (x < 0) return (x+b)%b;
    return x;
}

ll compute(ll zero_count, ll one_count, ll index, const string &path){
    ll ans = 0;
    ll pairs = (one_count * zero_count)%mod;
    ans = (pairs*(index+1 - (index%2)))%mod;
    ans += ((pairs * (index + (index%2)))%mod);
    debug(path, index, zero_count, one_count, ans);
    debug(endl);
    return ans;
}

ll compute(ll count, ll index, const string &path){
    ll ans, pairs = (count*count)%mod;
    ans = (pairs*(index+1))%mod;
    debug(path, index, count, ans);
    debug(endl);
    return ans;
}

void dfs(trie *node, ll &ans, ll last_index, string &path){
    if (node == nullptr) return;
    path.push_back((char)(node->val + '0'));
    if (node->val) last_index = max(last_index, node->depth);
    if (node->children[0] && node->children[1])
        ans += compute(node->children[0]->count, node->children[1]->count, node->children[0]->depth, path);
    if (node->end)
        ans += compute(node->count, last_index, path);
    ans %= mod;
    dfs(node->children[0], ans, last_index, path);
    dfs(node->children[1], ans, last_index, path);
    path.pop_back();
}

void solve(){
    ll n; cin >> n;
    vector<int> s(n);
    trie *root = new trie(' '-'0', 0);
    string number;
    ll ans = 0ll;
    string path = "";
    forn(i, n){
        cin >> s[i];
        number = bitset<32>(s[i]).to_string();
        number = number.substr(__builtin_clz(s[i]));
        debug(number);
        insert(number, root);
    }
    ll last_index = 0;
    dfs(root, ans, last_index, path);
    ll inv = get_inverse(n*n, mod) % mod;
    debug(ans, inv);
    ans = (ans * inv)%mod;
    cout << ans << endl;
}

// kth set bit different
// if a > b: k + 1 - (k&1)
// if a < b: k + (k%2)
// if a == b: k+1

// 1
// 2
// 2 3