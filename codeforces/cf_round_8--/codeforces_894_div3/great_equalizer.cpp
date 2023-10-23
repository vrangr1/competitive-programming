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
#include <assert.h>
#define debug false

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
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

void solve();

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

multiset<int> elements, differences;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    forn(i,n) cin >> a[i];
    int q; cin >> q;
    int index, num, pnum;
    if (n == 1){
        forn(i,q){
            cin >> index >> num;
            cout << num << endl;
        }
        return;
    }
    elements.clear();
    differences.clear();
    elements.insert(a.begin(), a.end());
    vector<int> order(n);
    multiset<int>::iterator iter;
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int &i, const int &j){
        return a[i] < a[j];
    });
    forsn(i,1,n-1)
        differences.insert(a[order[i]] - a[order[i-1]]);
    forn(i, q){
        cin >> index >> num;
        pnum = a[--index];
        if (pnum == num){
            cout << *elements.rbegin() + *differences.rbegin() << " \n"[i == q-1];
            continue;
        }
        a[index] = num;
        iter = elements.lower_bound(pnum);
        if (next(iter) == elements.end() || *next(iter) != *iter){
            if (iter != elements.begin())
                differences.erase(differences.find(*iter - *prev(iter)));
            if (next(iter) != elements.end())
                differences.erase(differences.find(*next(iter) - *iter));
            if (next(iter) != elements.end() && iter != elements.begin())
                differences.insert(*next(iter) - *prev(iter));
            elements.erase(pnum);
        }
        else elements.erase(elements.find(pnum));
        if (elements.find(num) != elements.end())
            differences.insert(0);
        else{
            iter = elements.lower_bound(num);
            if (iter == elements.end())
                differences.insert(num - *elements.rbegin());
            else if (iter == elements.begin())
                differences.insert(*elements.begin() - num);
            else{
                differences.erase(differences.find(*iter - *prev(iter)));
                differences.insert(*iter - num);
                differences.insert(num - *prev(iter));
            }
        }
        elements.insert(num);
        cout << *elements.rbegin() + *differences.rbegin() << " \n"[i == q-1];
    }
}