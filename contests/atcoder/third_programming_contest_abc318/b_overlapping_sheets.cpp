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


void solve(){
    int n; cin >> n;
    vector<vector<int>> sheets(n, vector<int>(4));
    forn(i, n)
        cin >> sheets[i][0] >> sheets[i][1] >> sheets[i][2] >> sheets[i][3];
    vector<vector<pair<int,int>>> intervals(101);
    forn(i, n){
        forsn(j, sheets[i][2], sheets[i][3]-1){
            intervals[j].push_back(make_pair(sheets[i][0], sheets[i][1]));
        }
    }
    // return;
    forn(i,101){
        if(intervals[i].size() <= 1) continue;
        sort(intervals[i].begin(), intervals[i].end(), [](const pair<int,int> &a, const pair<int,int> &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
    }
    int area = 0, count = 0, index = 0;
    #if debug
        cout << "intervals:\n";
        forn(i, 101){
            if (intervals[i].size() == 0) continue;
            print_var(i);
            print_arr(intervals[i]);
        }
        cout << "intervals ends\n\n";
    #endif
    forn(i, 101){
        priority_queue<int, vector<int>, greater<int>> pq;
        index = 0;
        count = 0;
        if (intervals[i].size() == 0) continue;
        if (intervals[i].size() == 1){
            area += intervals[i][0].second - intervals[i][0].first;
            continue;
        }
        forn(j, 101){
            while(index < intervals[i].size() && intervals[i][index].first <= j){
                count++;
                pq.push(intervals[i][index].second);
                index++;
            }
            while(!pq.empty() && pq.top() <= j){
                pq.pop();
                count--;
            }
            if (count > 0){
                #if debug
                    print_var(i);
                    print_var(j);
                    print_var(count);
                #endif
                area++;
                #if debug
                    print_var(area);
                    cout << endl;
                #endif
            }
        }
    }
    cout << area << endl;
}