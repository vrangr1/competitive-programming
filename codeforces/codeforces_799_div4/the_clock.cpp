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

const int twentyfour = 1440;

int gcd(int a, int b){
    if (a < b){
        int temp = b;
        b = a;
        a = temp;
    }
    if (b == 0) return a;
    return gcd(b, a%b);
}

inline int lcm(int a, int b){
    return ((a * b) / gcd(a,b));
}

int get_time(string ct){
    assert(ct.size() == 5 && ct[2] == ':');
    int hr = stoi(ct.substr(0,2));
    int ans = hr * 60 + stoi(ct.substr(3));
    return ans;
}

int reverse_num(int num){
    int ans = 0;
    while(num != 0){
        ans = ans * 10 + (num % 10);
        num /= 10;
    }
    return ans;
}


bool check_palindrome(int ctime, vector<bool> &visited){
    if (visited[ctime]) return false;
    int hr = ctime / 60;
    if (hr < 0 || hr >= 24){
        print_var(ctime);
        print_var(hr);
        exit(0);
    }
    assert(hr >= 0 && hr < 24);
    int mn = ctime % 60;
    string hour, minutes;
    hour = to_string(hr);
    if (hr < 10) hour = "0" + hour;
    minutes = to_string(mn);
    if (mn < 10) minutes = "0" + minutes;
    reverse(hour.begin(), hour.end());
    bool ans = (hour == minutes);
    if (ans)
        visited[ctime] = true;
    return ans;
}

void solve(){
    string giventime;
    int x;
    cin >> giventime >> x;
    int cycle = lcm(twentyfour, x);
    int curtime = get_time(giventime);
    assert(curtime >= 0 && curtime < 1440);
    int otime = curtime, ans = 0, add = 0;
    vector<bool> visited(1440, false);
    while(add < cycle){
        if (check_palindrome(curtime, visited)) ans++;
        add += x;
        curtime = otime + add;
        while(curtime >= 1440) curtime -= 1440;
    }
    cout << ans << endl;
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
