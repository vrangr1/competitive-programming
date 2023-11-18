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
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);


bool winner(char a, char b){
	if (a == b)
		return true;
	if (a == 'R' && b == 'S')
		return true;
	if (a == 'S' && b == 'P')
		return true;
	if (a == 'P' && b == 'R')
		return true;
	return false;
}


int find_winner(string &s, int st, int end){
	if (st >= end)
		return st;
	int ans = st;
	char ch = s[st];
	forsn(i, st + 1, end){
		if (!winner(ch, s[i])){
			ch = s[i];
			ans = i;
		}
	}
	return ans;
}


int main(){
	fastIO;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		// vector<int> arr(n);
		// arr[0] = 0;
		// forsn(i, 1, n-1){
		// 	if (winner(s[arr[i-1]], s[i]))
		// 		arr[i] = arr[i-1];
		// 	else
		// 		arr[i] = i;
		// }
		
		// int cur = find_winner(s, 0, n-1);
		// forn(i, n){
		// 	if (i <= cur){
		// 		cout << s[cur];
		// 		continue;
		// 	}
		// 	cur = find_winner(s, i, n-1);
		// 	cout << s[cur];
		// }
		// cout << endl;
		vector<int> w(n);
		w[n-1] = n-1;
		forsr(i, n-2, 0){
			if (winner(s[i+1], s[i])){
				w[i] = w[i+1];
				continue;
			}
			int cur = i+1;
			while (cur < n && !winner(s[cur], s[i])){
				cur++;
			}
			if (cur == n){
				w[i] = i;
				continue;
			}
			w[i] = w[cur];
			// w[i] = find_winner(s, i, n-1);

		}
		// forsr(i, n-2, 0){
		// 	if ((!winner(s[i], s[i+1])) || s[i] == s[i+1]){
		// 		w[i] = w[i+1];
		// 		continue;
		// 	}
		// 	int temp = find_winner(s, i, w[i+1] - 1);
		// 	if ((!winner(s[temp], s[w[i+1]])) || s[temp] == s[w[i+1]]){
		// 		w[i] = w[i+1];
		// 		continue;
		// 	}
		// 	// if (winner(s[temp], s[w[w[i+1] + 1]]))
		// 	if (w[i+1] == n-1){
		// 		w[i] = temp;
		// 		continue;
		// 	}
		// 	char tmp = s[w[i+1]];
		// 	s[w[i+1]] = s[temp];
		// 	w[i] = find_winner(s, w[i+1], n-1);
		// 	s[w[i+1]] = tmp;
		// 	// if (winner(s[temp],))
		// }
		forn(i, n){
			cout << s[w[i]];
		}
		cout << endl;
	}
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