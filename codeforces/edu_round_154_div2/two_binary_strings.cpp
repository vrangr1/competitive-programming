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
#define debug true

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

bool find_this(string &a, int left, int right, int n, char ch){
    bool foundleft = false, foundright = false;
    for (int i = 0; i < left; ++i){
        if (a[i] == ch){
            foundleft = true;
            break;
        }
    }
    for (int i = right+1; i < n; ++i){
        if (a[i] == ch){
            foundright = true;
            break;
        }
    }
    return foundleft && foundright;
}

int find_left(const string &a, const string &b, int index, char ch){
    for (;index >= 0; index--)
        if (a[index] == ch && b[index] == ch) return index;
    return -1;
}

int find_right(const string &a, const string &b, int index, char ch){
    for (;index < a.size(); index++)
        if (a[index] == ch && b[index] == ch) return index;
    return -1;
}

void solve1(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), i = 1, index;
    if (a == b) return void(cout << yes);
    int left = 0, right = n-1, l2, r2;
    while(left <= right){
        if (a[left] == b[left]) left++;
        else if (a[right] == b[right]) right--;
        else break;
    }
    if (find_this(a, left, right, n, '1') || find_this(a, left, right, n, '0'))
        return void(cout << yes);
    i = 1;
    while (i < n){
        if (a[i] == b[i]){
            i++;
            continue;
        }
        left = find_left(a, b, i, '1');
        right = find_right(a, b, i, '1');
        l2 = find_left(a, b, i, '0');
        r2 = find_right(a, b, i, '0');
        if (left != -1 && right != -1 && l2 != -1 && r2 != -1){
            if (r2 < right){
                fill(a.begin() + l2, a.begin() + r2, a[l2]);
                fill(b.begin() + l2, b.begin() + r2, b[r2]);
                i = r2 + 1;
                continue;
            }
            fill(a.begin() + left, a.begin() + right, a[right]);
            fill(b.begin() + left, b.begin() + right, b[right]);
            i = right+1;
            continue;
        }
        if ((left == -1 || right == -1) && (l2 == -1 || r2 == -1)){
            cout << no;
            return;
        }
        if (left == -1 || right == -1){
            fill(a.begin() + l2, a.begin() + r2, a[l2]);
            fill(b.begin() + l2, b.begin() + r2, b[r2]);
            i = r2 + 1;
            continue;
        }
        fill(a.begin() + left, a.begin() + right, a[right]);
        fill(b.begin() + left, b.begin() + right, b[right]);
        i = right+1;
        continue;
    }
    cout << yes;
}

void solve(){
    string a, b; cin >> a >> b;
    if (a==b) return void(cout << yes);
    int n = a.size(), j;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int len = 1; len <= n; ++len){
        for (int i = 0; i < n - len + 1; ++i){
            j = i+len-1;
            if (len == 1){
                dp[i][j] = a[i] == b[i];
                continue;
            }
            if (len == 2){
                dp[i][j] = (a[i] == b[i]) && (a[j] == b[j]);
                continue;
            }
            if (a[i] == b[i] && a[j] == b[j] && a[i] == a[j])
                dp[i][j] = true;
            dp[i][j] = dp[i][j] || (dp[i][j-1] && a[j] == b[j]) || (dp[i+1][j] && a[i] == b[i]);
        }
    }
    if (dp[0][n-1]) cout << yes;
    else cout << no;
}
