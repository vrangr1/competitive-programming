/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar  9 17:59:04 IST 2024
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

class llist{
public:
    int val;
    llist *prev, *next;
    llist():val(-1),prev(nullptr),next(nullptr){}
    llist(int v){
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

const int maxnodes = (int)(4e5+1);
int nodeind = 0;
vector<llist> nodepool(maxnodes);
llist* get_node(){
    assert(nodeind < maxnodes);
    llist *node = &nodepool[nodeind++];
    node->val = -1;
    node->prev = node->next = nullptr;
    return node;
}

llist* get_node(int v){
    assert(nodeind < maxnodes);
    llist *node = &nodepool[nodeind++];
    node->val = v;
    node->prev = node->next = nullptr;
    return node;
}

void solve(){
    map<int,llist*> mp;
    nodeind = 0;

    int n; cin >> n;
    llist *head = nullptr, *node, *tail = nullptr, *temp;
    rep(i,n){
        int a; cin >> a;
        node = get_node(a);
        if (!head) head = tail = node;
        else{
            assert(!tail->next);
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        mp[a] = node;
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if (t == 1){
            int x, y; cin >> x >> y;
            node = mp[x];
            assert(node!=nullptr);
            if (!node->next){
                node->next = get_node(y);
                node->next->prev = node;
            }
            else {
                temp = get_node(y);
                temp->next = node->next;
                temp->prev = node;
                node->next->prev = temp;
                node->next = temp;
            }
            mp[y] = node->next;
        }
        else{
            int x; cin >> x;
            node = mp[x];
            assert(node!=nullptr);
            if (x == head->val)
                head = head->next;
            if (node->prev) node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
            mp[x] = nullptr;
        }
    }
    node = head;
    while(node){
        cout << node->val;
        if (node->next) cout << " ";
        else cout << endl;
        node = node->next;
    }
}