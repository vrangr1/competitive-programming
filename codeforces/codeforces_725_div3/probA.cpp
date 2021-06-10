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
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
//#define print_var(x) printf("%s=%s\n", #x, STR(x))
//#define print_var(x) cout << #x << ": " << STR(x) << "\n";


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		cin >>arr[0];
		int mx = 0, mn = 0;
		forsn(i, 1, n - 1){
			cin >> arr[i];
			if (arr[mx] < arr[i])
				mx = i;
			if (arr[mn] > arr[i])
				mn = i;
		}
		// if (n == 2){
		// 	cout << 2 << bline;
		// 	continue;
		// }
		// if (mn < n/2 && mx < n/2){
		// 	cout << max(mn + 1,mx + 1) << bline;
		// 	continue;
		// }
		// if (mn >= n/2 && mx >= n/2){
		// 	cout << max(n - mx, n - mn); << bline;
		// 	continue;
		// }
		if (mn > mx)
			swap(mn, mx);
		cout << min(mn + 1 + n - mx, min(mx + 1, n - mn)) << bline;
		continue;
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