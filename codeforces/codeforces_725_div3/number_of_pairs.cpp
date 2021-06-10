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
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> arr(n);
		forn(i, n)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		// cout << "n, l, r: " << n << ", " << l << ", " << r << bline;
		// print(arr);
		ll ct = 0;
		forn(i, n - 1){
			if (r - arr[i] < arr[i])
				break;
			// if (arr[i] >= l){
			// 	continue;
			// }
			ll i1 = lower_bound(arr.begin() + i + 1, arr.end(), l - arr[i]) - arr.begin();
			ll i2 = upper_bound(arr.begin() + i + 1, arr.end(), r - arr[i]) - arr.begin();
			// cout << "for arr[" << i << "]: " << arr[i] << ": " << i1 << ", " << i2 << bline;
			ct += (i2 - i1);
		}
		cout << ct << bline;
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