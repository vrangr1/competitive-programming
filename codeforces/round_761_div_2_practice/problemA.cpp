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


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		if (t != "abc"){
			cout << s << endl;
			continue;
		}
		string ans;
		bool athere = false;
		int st = -1, end = -1;
		bool cend = false;
		forn(i, s.size()){
			if (s[i] == 'a'){
				athere = true;
				ans.push_back('a');
				continue;
			}
			if (s[i]!= 'a' && !athere){
				ans.push_back(s[i]);
				continue;
			}
			if (s[i] != 'b' && s[i] != 'c'){
				if (!cend && end != -1){
					cend = true;
					forsn(j, st, end){
						ans.push_back('b');
					}
				}
				ans.push_back(s[i]);
				continue;
			}
			if (s[i] == 'b' && st == -1){
				st = i;
				continue;
			}
			if (s[i] == 'c' && end == -1){
				end = i-1;
				ans.push_back('c');
				continue;
			}
			if (s[i] == 'c'){
				ans.push_back('c');
			}

		}
		if (athere && st != -1 && !cend){
			forsn(j, st, end)
				ans.push_back('b');
		}
		cout << ans << endl;
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