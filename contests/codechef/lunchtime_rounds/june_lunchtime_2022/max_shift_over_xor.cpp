/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
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
#define space " "

#define debug_mode true

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(2*n), xors(2*n);
    forn(i, n) cin >> arr[i];
    forn(i, n) arr[i+n] = arr[i];
    xors[0] = arr[0];
    forsn(i, 1, 2*n-1) xors[i] = xors[i-1]^arr[i];
    map<ll, int> counts;
    forn(i, 2*n) counts[xors[i]] = 0;
    int maxval = INT_MIN;
    int curct = 0;
    forn(i, n){
        counts[xors[i]]++;
        if (counts[xors[i]] == 1) curct++;
    }
    maxval = curct;
    forsn(i, 1, n-1){
        counts[xors[i-1]]--;
        if (counts[xors[i-1]] == 0) curct--;
        counts[xors[i+n-1]]++;
        if(counts[xors[i+n-1]] == 1) curct++;
        maxval = max(curct, maxval);
    }
    cout << maxval << endl;
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
