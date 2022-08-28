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
#include <queue>

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

inline int getMax(deque<pair<int, int> > &prev, int curInd, int maxLength){
    if (curInd - prev.front().second > maxLength){
        prev.pop_front();
        // return prev.front().first;
    }
    return prev.front().first;
}

void update_deque(deque<pair<int, int> > &prev, int newVal, int ind){
    while(prev.size() > 0 && prev.back().first <= newVal){
        prev.pop_back();
    }
    prev.push_back(make_pair(newVal, ind));
}

template<typename type> void print_deque(deque<type> &deq){
    for (auto iter = deq.rbegin(); iter != deq.rend(); ++iter)
        print(*iter);
}

int max_sum(vector<int> &arr, int maxLength){
    int n = arr.size();
    // int sum = arr[0], maxsum = arr[0];
    deque<pair<int, int> > prevValues;
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    prevValues.push_back(make_pair(arr[0], 0));
    for (int i = 1; i < n; ++i){
        dp[i] = max(getMax(prevValues, i, maxLength) + arr[i], arr[i]);
        print_var(dp[i]);
        print_var(i);
        cout << "before\n";
        print_deque(prevValues);
        update_deque(prevValues, dp[i], i);
        cout << "after\n";
        print_deque(prevValues);
        cout << "\n\n\n";
    }
    print(dp);
    return *max_element(dp.begin(), dp.end());
    // for (int i = 1; i < n; ++i){
    //     sum += arr[i];
    //     maxsum = max(sum, maxsum);
    //     if (sum <= 0) sum = 0;
    // }
    return 0;
}


void solve(){
    // vector<int> arr{100, -70, -90, -80, 100};
    vector<int> arr;
    // arr.push_back(100);
    // arr.push_back(-70);
    // arr.push_back(-90);
    // arr.push_back(-80);
    // arr.push_back(100);
    arr.push_back(3);
    arr.push_back(-4);
    arr.push_back(-3);
    arr.push_back(-5);
    arr.push_back(0);
    cout << "ans: " << max_sum(arr, 2) << endl;
}

int main(){
	fastIO;
	TEST1;
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