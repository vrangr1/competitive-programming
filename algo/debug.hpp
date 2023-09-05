#ifndef DEBUG_HPP
#define DEBUG_HPP
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
extern const bool DEBUG;

using namespace std;

#define debug(...) if (DEBUG) debug_encapsulate(#__VA_ARGS__, __VA_ARGS__);
#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0

typedef long long int ll;
typedef unsigned long long int ull;
template<typename type> void print(const type &var);
template<typename type> void print(type *var);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);
template <typename t1, typename t2> void print(pair<t1,t2> *p);
template <typename type> void print(const vector<type> &vec);
template<typename type> void print(const unordered_set<type> &uset);
template<typename type> void print(const set<type> &uset);
template <typename t1, typename t2> void print(const unordered_map<t1,t2> &umap);
template <typename t1, typename t2> void print(const map<t1,t2> &mp);
template <typename type> void print(stack<type> stck);
template <typename type> void print(queue<type> que);
template <typename type> void print(const list<type> &lst);
template <typename type> void print(const forward_list<type> &flst);

template<typename type> void print(const type &var){
    cout << var;
}

template<typename type> void print(type *var){
    cout << *var;
}

template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "(" << p.first << "," << p.second << ")";
}

template <typename t1, typename t2> void print(pair<t1,t2> *p){
    cout << "(" << p->first << "," << p->second << ")";
}

template <typename type> void print(const vector<type> &vec){
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i){
        print(vec[i]);
        cout << " \0"[i + 1 == vec.size()];
    }
    cout << " ]";
}

template<typename type> void print(const unordered_set<type> &uset){
    cout << "{ ";
    for (auto i = uset.begin(); i != uset.end(); ++i){
        cout << " \0"[i == uset.begin()];
        print(*i);
    }
    cout << " }";
}

template<typename type> void print(const set<type> &st){
    cout << "{ ";
    for (auto i = st.begin(); i != st.end(); ++i){
        cout << " \0"[i == st.begin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const unordered_map<t1,t2> &umap){
    cout << "{ ";
    for (auto i = umap.begin(); i != umap.end(); ++i){
        cout << " \0"[i == umap.begin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const map<t1,t2> &mp){
    cout << "{ ";
    for (auto i = mp.begin(); i != mp.end(); ++i){
        cout << " \0"[i == mp.begin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename type> void print(stack<type> stck){
    cout << "[ ";
    while (!stck.empty()){
        print(stck.top());
        cout << " \0"[stck.size() == 1];
        stck.pop();
    }
    cout << " ]";
}

template <typename type> void print(queue<type> que){
    cout << "[ ";
    while (!que.empty()){
        print(que.front());
        cout << " \0"[que.size() == 1];
        que.pop();
    }
    cout << " ]";
}

template <typename type> void print(const list<type> &lst){
    cout << "[ ";
    for (auto i = lst.begin(); i != lst.end(); ++i){
        cout << " \0"[i == lst.begin()];
        print(*i);
    }
    cout << " ]";
}

template <typename type> void print(const forward_list<type> &flst){
    cout << "[";
    for (auto i = flst.begin(); i != flst.end(); ++i){
        cout << " \0"[i == flst.begin()];
        print(*i);
    }
    cout << "]";
}

template <typename type> void print(const deque<type> &deq){
    cout << "[ ";
    for (auto i = deq.begin(); i != deq.end(); ++i){
        cout << " \0"[i == deq.begin()];
        print(*i);
    }
    cout << " ]";
}

template <typename Arg1> void debug_encapsulate(const char* name, Arg1&& arg1){
    if (!DEBUG) return;
    cout << name << ": ";
    print(arg1);
    cout << endl;
}

template <typename Arg1, typename... Args> void debug_encapsulate(const char* names, Arg1&& arg1, Args&&... args){
    if (!DEBUG) return;
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << ": ";
    print(arg1);
    cout << endl;
    debug_encapsulate(comma+1, args...);
}
#endif