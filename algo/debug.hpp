#ifndef DEBUG_HPP
#define DEBUG_HPP
/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
****************************************************/
#include <bits/stdc++.h>
extern const bool DEBUG;

using namespace std;

#define debug(...) if (DEBUG) debug_encapsulate(#__VA_ARGS__, __VA_ARGS__);
#define endl "\n"

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const type &var);
template <typename type> void print(type *var);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);
template <typename t1, typename t2> void print(pair<t1,t2> *p);
template <typename type> void print(const vector<type> &vec);
template <typename type> void print(const unordered_set<type> &uset);
template <typename t1, typename t2> void print(const unordered_set<t1,t2> &uset);
template <typename type> void print(const set<type> &uset);
template <typename t1, typename t2> void print(const set<t1,t2> &uset);
template <typename type> void print(const unordered_multiset<type> &umset);
template <typename t1, typename t2> void print(const unordered_multiset<t1,t2> &umset);
template <typename type> void print(const multiset<type> &mset);
template <typename t1, typename t2> void print(const multiset<t1,t2> &st);
template <typename t1, typename t2> void print(const unordered_map<t1,t2> &umap);
template <typename t1, typename t2, typename t3> void print(const unordered_map<t1,t2,t3> &umap);
template <typename t1, typename t2> void print(const map<t1,t2> &mp);
template <typename t1, typename t2, typename t3> void print(const map<t1,t2,t3> &mp);
template <typename t1, typename t2> void print(const unordered_multimap<t1,t2> &ummp);
template <typename t1, typename t2, typename t3> void print(const unordered_multimap<t1,t2,t3> &ummp);
template <typename t1, typename t2> void print(const multimap<t1,t2> &mmp);
template <typename t1, typename t2, typename t3> void print(const multimap<t1,t2,t3> &mmp);
template <typename type> void print(stack<type> stck);
template <typename type> void print(queue<type> que);
template <typename type> void print(const list<type> &lst);
template <typename type> void print(const forward_list<type> &flst);
template <typename type> void print(const deque<type> &deq);
template <typename type> void print(priority_queue<type> pq);
template <typename t1, typename t2> void print(priority_queue<t1,vector<t1>,t2> pq);
template <class type, size_t... I> void print(const type& tup, index_sequence<I...>);
template <class... type> void print(const tuple<type...> &tup);
template <typename type, size_t N> void print(const array<type,N> &arr);
template <typename Arg1> void debug_encapsulate(const char* names, Arg1&& arg1);
template <typename Arg1, typename... Args> void debug_encapsulate(const char* names, Arg1&& arg1, Args&&... args);

template <typename type> void print(const type &var){
    if (is_integral<type>::value && !std::is_same<type, bool>::value) {
        if (var == numeric_limits<type>::max())
            return void(cout << "inf");
        else if (is_signed_v<type> && var == numeric_limits<type>::min())
            return void(cout << "-inf");
    }
    else if (std::is_same<type,bool>::value)
        return void(cout << boolalpha << var << noboolalpha);
    cout << var;
}

template <typename type> void print(type *var){
    print(*var);
}

template <typename t1, typename t2> void print(const pair<t1, t2> &p){
    cout << "(";
    print(p.first);
    cout << ",";
    print(p.second);
    cout << ")";
}

template <typename t1, typename t2> void print(pair<t1,t2> *p){
    cout << "(";
    print(p->first);
    cout << ",";
    print(p->second);
    cout << ")";
}

template <typename type> void print(const vector<type> &vec){
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i){
        print(vec[i]);
        cout << " \0"[i + 1 == vec.size()];
    }
    cout << " ]";
}

template <typename type> void print(const unordered_set<type> &uset){
    cout << "{ ";
    for (auto i = uset.cbegin(); i != uset.cend(); ++i){
        cout << " \0"[i == uset.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const unordered_set<t1,t2> &uset){
    cout << "{ ";
    for (auto i = uset.cbegin(); i != uset.cend(); ++i){
        cout << " \0"[i == uset.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename type> void print(const set<type> &st){
    cout << "{ ";
    for (auto i = st.cbegin(); i != st.cend(); ++i){
        cout << " \0"[i == st.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const set<t1,t2> &st){
    cout << "{ ";
    for (auto i = st.cbegin(); i != st.cend(); ++i){
        cout << " \0"[i == st.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename type> void print(const unordered_multiset<type> &umset){
    cout << "{ ";
    for (auto i = umset.cbegin(); i != umset.cend(); ++i){
        cout << " \0"[i == umset.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const unordered_multiset<t1,t2> &umset){
    cout << "{ ";
    for (auto i = umset.cbegin(); i != umset.cend(); ++i){
        cout << " \0"[i == umset.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename type> void print(const multiset<type> &st){
    cout << "{ ";
    for (auto i = st.cbegin(); i != st.cend(); ++i){
        cout << " \0"[i == st.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const multiset<t1,t2> &st){
    cout << "{ ";
    for (auto i = st.cbegin(); i != st.cend(); ++i){
        cout << " \0"[i == st.cbegin()];
        print(*i);
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const unordered_map<t1,t2> &umap){
    cout << "{ ";
    for (auto i = umap.cbegin(); i != umap.cend(); ++i){
        cout << " \0"[i == umap.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2, typename t3> void print(const unordered_map<t1,t2,t3> &umap){
    cout << "{ ";
    for (auto i = umap.cbegin(); i != umap.cend(); ++i){
        cout << " \0"[i == umap.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const map<t1,t2> &mp){
    cout << "{ ";
    for (auto i = mp.cbegin(); i != mp.cend(); ++i){
        cout << " \0"[i == mp.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2, typename t3> void print(const map<t1,t2,t3> &mp){
    cout << "{ ";
    for (auto i = mp.cbegin(); i != mp.cend(); ++i){
        cout << " \0"[i == mp.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const unordered_multimap<t1,t2> &ummp){
    cout << "{ ";
    for (auto i = ummp.cbegin(); i != ummp.cend(); ++i){
        cout << " \0"[i == ummp.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2, typename t3> void print(const unordered_multimap<t1,t2,t3> &ummp){
    cout << "{ ";
    for (auto i = ummp.cbegin(); i != ummp.cend(); ++i){
        cout << " \0"[i == ummp.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2> void print(const multimap<t1,t2> &mmp){
    cout << "{ ";
    for (auto i = mmp.cbegin(); i != mmp.cend(); ++i){
        cout << " \0"[i == mmp.cbegin()] << "(";
        print(i->first);
        cout << ":";
        print(i->second);
        cout << ")";
    }
    cout << " }";
}

template <typename t1, typename t2, typename t3> void print(const multimap<t1,t2,t3> &mmp){
    cout << "{ ";
    for (auto i = mmp.cbegin(); i != mmp.cend(); ++i){
        cout << " \0"[i == mmp.cbegin()] << "(";
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
    for (auto i = lst.cbegin(); i != lst.cend(); ++i){
        cout << " \0"[i == lst.cbegin()];
        print(*i);
    }
    cout << " ]";
}

template <typename type> void print(const forward_list<type> &flst){
    cout << "[";
    for (auto i = flst.cbegin(); i != flst.cend(); ++i){
        cout << " \0"[i == flst.cbegin()];
        print(*i);
    }
    cout << "]";
}

template <typename type> void print(const deque<type> &deq){
    cout << "[ ";
    for (auto i = deq.cbegin(); i != deq.cend(); ++i){
        cout << " \0"[i == deq.cbegin()];
        print(*i);
    }
    cout << " ]";
}

template <typename type> void print(priority_queue<type> pq){
    cout << "{ ";
    while(!pq.empty()){
        print(pq.top());
        pq.pop();
        cout << " \0"[pq.empty()];
    }
    cout << " }";
}

template <typename t1, typename t2> void print(priority_queue<t1,vector<t1>,t2> pq){
    cout << "{ ";
    while(!pq.empty()){
        print(pq.top());
        pq.pop();
        cout << " \0"[pq.empty()];
    }
    cout << " }";
}

template <class type, size_t... I> void print(const type& tup, index_sequence<I...>){
    cout << "(";
    (..., (cout << (I==0?"":", ") << get<I>(tup)));
    cout << ")";
}

template <class... type> void print(const tuple<type...> &tup){
    print(tup, make_index_sequence<sizeof...(type)>());
}

template <typename type, size_t N> void print(const array<type,N> &arr) {
    cout << "{";
    for (int i = 0; i < N; ++i) {
        print(arr[i]);
        cout << ",\0"[i==N-1];
    }
    cout << "}";
}

template <typename Arg1> void debug_encapsulate(const char* names, Arg1&& arg1){
    if (!DEBUG) return;
    char *name = (char*)names;
    while(isspace(*name)) name++;
    string comp(name);
    if (comp != "endl")
        cout << name << ": ";
    print(arg1);
    if (comp != "endl")
        cout << endl;
}

char* get_name(char *names){
    while (isspace(*names)) names++;
    int n = strlen(names);
    int count = 0;
    for (int i = 0; i < n; ++i){
        if (count == 0 && names[i] == ',') return names+i;
        if (names[i] == '(') count++;
        else if (names[i] == ')') count--;
    }
    assert(false);
    return names;
}

template <typename Arg1, typename... Args> void debug_encapsulate(const char* names, Arg1&& arg1, Args&&... args){
    if (!DEBUG) return;
    char *comma = get_name((char*)names);
    char *name = (char*)names;
    while (isspace(*name)) name++;
    string comp(name, comma-name);
    if (comp != "endl")
        cout.write(name, comma - name) << ": ";
    print(arg1);
    if (comp!="endl")
        cout << endl;
    debug_encapsulate(comma+1, args...);
}
#endif




/*
TODO: Could be useful. Take a look at later on.

// === Debug macro starts here ===

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cout<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

// === Debug macro ends here ===

*/