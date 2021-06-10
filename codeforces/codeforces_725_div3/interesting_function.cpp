/***************************************************
* AUTHOR : Anav Prasad
* Nick : graworth
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define pb(a) push_back(a)
#define pass (void)0
typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
//#define print_var(x) printf("%s=%s\n", #x, STR(x))
//#define print_var(x) cout << #x << ": " << STR(x) << "\n";


inline ull ret_num(char ch){
	return (ll)(ch - '0');
}



ull calc(string num){
	int n = num.length();
	int i = 1;
	ull ans = ret_num(num[0]);
	ull last = ans;
	while(i < n){
		ans = ans + ((last+1) * ((ull)(10))) - (10 - ret_num(num[i]));
		last = ((last + 1) * ((ull)(10))) - (10 - ret_num(num[i]));
		++i;
	}
	// cout << "num: " << num << "; ans: " << ans << bline;
	return ans;
}



int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		string l, r;
		cin >> l >> r;
		// int m = l.length(), n = r.length();
		cout << calc(r) - calc(l) << bline;
	}
	return 0;
}


template <typename type> void print(vector<vector<type>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}


template <typename type> void print(vector<type> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}