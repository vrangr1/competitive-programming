#if 0
    me=`basename $0 .cpp`
    g++ -std=c++20 $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
    	rm $me
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
#include <set>
#include <unordered_set>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <bit>
#include <bitset>
#include <assert.h>

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
#define print_cont(arr) cout << #arr << ": ";print(arr);
#define print_pair(pr) cout << #pr << ": ";print(pr);
#define space " "

#define debug_mode false

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void print(const vector<unordered_set<type>> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename type> void print(const unordered_set<type> &uset);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

void solve(){
    int n, m;
    cin >> n >> m;
    string temp;
    vector<unordered_set<char>> sets(m);
    forn(i, n){
        cin >> temp;
        #if debug
            assert(temp.size() == m);
            print_var(temp);
        #endif
        forn(j, m){
            sets[j].insert(temp[j]);
        }
        #if debug
            print_cont(sets);
        #endif
        temp.clear();
    }
    temp = "vika";
    int index = 0;
    forn(i, m){
        if (index == temp.size()){
            cout << "YES\n";
            return;
        }
        #if debug
        print_cont(sets[i]);
        print_var(index);
        print_var(temp[index]);
        #endif
        if (sets[i].find(temp[index]) != sets[i].end()){
            #if debug
            cout << "found\n";
            #endif
            index++;
            continue;
        }
        #if debug
            cout << endl;
        #endif
    }
    if (index == temp.size()){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
	fastIO;
	TEST;
	return 0;
}


template <typename type> void print(const vector<vector<type> > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size() - 1)
			cout << arr[i][j] << ", ";
		cout << arr[i][arr[i].size() - 1] << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector\n";
}


template <typename type> void print(const vector<type> &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ", ";
	}
	cout << "], 1D Vector\n";
}

template <typename type> void print(const vector<unordered_set<type>> &arr){
    cout << "\n[";
    forn(i, arr.size()){
        cout << "{";
        for (auto it = arr[i].begin(); it != arr[i].end(); ++it)
            cout << *it << ", ";
        cout << "}";
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "], 1D Vector of Unordered Sets\n";
}

template <typename type> void off_print(const vector<type> &arr){
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << endl;
}


template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr){
	int n = arr.size();
	cout << "\n[";
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}], 1D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size()){
			cout << "{" << arr[i][j].first << "," << arr[i][j].second << "}";
			if (j != arr[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "\n{" << p.first << "," << p.second << "}, Pair\n";
}

template <typename type> void print(const unordered_set<type> &uset){
    cout << "\n{";
    for (auto it = uset.begin(); it != uset.end(); ++it)
        cout << *it << ", ";
    cout << "}, Unordered Set\n";
}