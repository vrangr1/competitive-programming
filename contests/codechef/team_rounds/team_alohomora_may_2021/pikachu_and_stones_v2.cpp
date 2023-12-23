/***************************************************
* AUTHOR : Anav Prasad
* Nick : graworth
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
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
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
template <typename t1, typename t2> void print(vector<pair<t1,t2>> &arr);
ull ans = 0;


void solve(vector<int> &arr, int st, int end){
	if (st > end)
		return;
	else if (st == end){
		if (arr[st] > arr[st-1] || arr[st] > arr[st + 1])
			return;
		if (arr[st-1] == arr[end+1]){
			ans += (arr[st - 1] + 1 - arr[st]);
			return;
		}
		int mn = min(arr[st -1], arr[end+1]) + 1;
		if (mn != arr[st-1] && mn != arr[end +1]){
			ans += mn - arr[st];
			return;
		}
		ans += max(arr[st-1], arr[end+1]) + 1 - arr[st];
		// ans += min(arr[st - 1], arr[end + 1]) + 1 - arr[st];
		return;
	}
	while(st <= end && arr[st] > arr[st - 1]){
		st++;
	}
	while(end >= st && arr[end] > arr[end + 1])
		end--;
	if (st > end){
		if (st == arr.size() - 1)
			ans += arr[st] + 1 - arr[st - 1];
		else if (end == 0)
			ans += arr[0] + 1 - arr[1];
		return;
	}
	if (st == end){
		if (arr[st] > arr[st-1] || arr[st] > arr[st + 1]){
			// if (st == 1 || end == arr.size() - 2){
			// 	ans += max(arr[st-1], arr[end + 1]) + 1 - arr[st];
			// }
			return;
		}
		if (arr[st-1] == arr[end+1]){
			ans += (arr[st -1] + 1 - arr[st]);
			return;
		}
		int mn = min(arr[st -1], arr[end+1]) + 1;
		// cout << "mn: " << mn << endl;
		if (mn != arr[st-1] && mn != arr[end +1]){
			ans += mn - arr[st];
			return;
		}
		ans += max(arr[st-1], arr[end+1]) + 1 - arr[st];
		return;
	}
	int d1 = arr[st-1] + 1 - arr[st], d2 = arr[end + 1] + 1 - arr[end];
	if (d1 < d2){
		ans += (arr[st - 1] + 1 - arr[st]);
		arr[st] = arr[st - 1] + 1;
		solve(arr, st + 1, end);
		return;
	}
	ans += (arr[end + 1] + 1 - arr[end]);
	arr[end] = arr[end + 1] + 1;
	solve(arr, st, end - 1);
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n; cin >> n;
		vector<int> arr(n);
		forn(i, n)
			cin >> arr[i];
		if (n == 3){
			cout << max(arr[0], arr[2]) + 1 - arr[1] << endl;
			continue;
		}
		ans = 0;
		solve(arr, 1, n - 2);
		cout << ans << endl;
	}
	return 0;
}


template <typename type> void print(vector<vector<type>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << endl;
	}
}


template <typename type> void print(vector<type> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << endl;
}


template <typename t1, typename t2> void print(vector<pair<t1,t2>> &arr){
	cout << "1d vector with pairs: \n";
	int n = arr.size();
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}\n";
}