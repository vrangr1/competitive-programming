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
typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

inline bool compare_func(const pair<int, int> &a, const pair<int,int> &b){
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

// void process(vector<pair<int,int>> &arr, const int start, const int end, int &maxval, int &a, int &l, int &r){
//     int curval = 1, curl = start, curr = start, cura = arr[start].first;
//     forsn(j, start + 1, end){
        
//     }
// }

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];
    int start = 0, end = 1, maxval = 1, a = arr[0], l = 1, u = 1, cura = arr[0], curl = 1, curu = 1, maxfreq = 1, curval = 1;
    map<int, int> freq;
    forn(i, n) freq[arr[i]] = 0;
    freq[arr[0]]++;
    while(start <= end && end < n && start < n){
        freq[arr[end]]++;
        if (freq[arr[end]] > maxfreq){
            maxfreq = freq[arr[end]];
        }
        curval = 2*maxfreq - end + start - 1;
        while(curval < 1 && start < end){
            freq[arr[start]]--;
            
        }
        
    }
}

void solve_v2(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    forn(i, n){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), compare_func);
    int start = 0, curval = arr[0].first, end = -1;
    int a, l, r;
    double maxval = 1, curval;
    int curl, curr, cura;
    forn(i, n){
        if (arr[i].first != cura){
            // end = i - 1;
            // assert(end >= 0);
            // curval = 1;
            // curl = start;
            // curr = start;
            // forsn(j, start + 1, end){
            //     if (curval == 1 && arr[j].second > arr[j-1].second + 1){
            //         curval = 1;
            //         curl = j;
            //         curr = j;
            //     }
            //     else if ()
            // }
        }
    }
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
