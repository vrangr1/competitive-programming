#if 0
    me=`basename $0 .cpp`
    rm -f $me
    rm -f $me.out
    g++ -std=c++20 $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
    	rm $me
        echo "\noutput begins now:"
        cat $me.out
        rm $me.out
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <list>
#include <forward_list>
#include <assert.h>
#include "debug.hpp"
const bool DEBUG = true;

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
#define print_var(x) cout << #x << ": " << x << "\n";
#define print_iter(x) cout << "*" << #x << ": " << *x << endl;
#define print_arr(arr) cout << #arr << ": ";print(arr);
#define print_pair(pr) cout << #pr << ": ";print(pr);
#define space " "
#define yes "YES\n"
#define no "NO\n"

typedef long long int ll;
typedef unsigned long long int ull;

void solve();

int main(){
	fastIO;
	TEST1;
	return 0;
}

void var_func(int arg...){
    va_list args;
    va_start(args, arg);
    int i;
    for (i = 0; i < arg; i++){
        cout << static_cast<char>(va_arg(args, int)) << endl;
    }
    va_end(args);
}

void solve(){
    int a = 1;
    vector<int> vec={1,2,3,4,5};
    vector<vector<int>> vec2d={{1,2,3},{4,5,6},{7,8,9}};
    vector<pair<char,int>> vec_pair={{'a',1},{'b',2},{'c',3}};
    vector<vector<pair<char,int>>> vec_pair2d={{{'a',1},{'b',2},{'c',3}},{{'d',4},{'e',5},{'f',6}},{{'g',7},{'h',8},{'i',9}}};
    unordered_set<int> uset={1,2,3,4,5};
    set<int> st={1,2,3,4,5};
    unordered_map<char,int> umap={{'a',1},{'b',2},{'c',3}};
    map<char,int> mp={{'a',1},{'b',2},{'c',3}};
    map<vector<pair<int,char>>,int> mp2={{{{1,'a'},{2,'b'},{3,'c'}},1},{{{4,'d'},{5,'e'},{6,'f'}},2},{{{7,'g'},{8,'h'},{9,'i'}},3}};
    stack<int> stck;
    stack<pair<int,char>> stck_pair;
    stck_pair.push({1,'a'});
    stck_pair.push({2,'b'});
    stck_pair.push({3,'c'});
    stck.push(3);
    stck.push(2);
    stck.push(1);
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    forward_list<int> flst;
    flst.push_front(1);
    flst.push_front(2);
    flst.push_front(3);
    deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deque<pair<int,char>> deq_pair;
    deq_pair.push_back({1,'a'});
    deq_pair.push_back({2,'b'});
    deq_pair.push_back({3,'c'});

    int *ptr = &a;
    debug(vec_pair,vec_pair2d,vec2d,vec, uset, st,umap,mp,mp2,stck,stck_pair,que,lst,flst,deq,deq_pair, ptr);
    cout << "double\n";
    debug(vec_pair2d);
    debug(vec_pair);
    debug(vec2d);
    debug(vec);
    debug(uset);
    debug(st);
    debug(umap);
    debug(mp);
    debug(mp2);
    debug(stck);
    debug(stck_pair);
    debug(que);
    debug(stck);
    debug(stck_pair);
    debug(que);
    debug(lst);
    debug(flst);
    debug(deq);
    debug(deq_pair);
    debug(ptr);
}