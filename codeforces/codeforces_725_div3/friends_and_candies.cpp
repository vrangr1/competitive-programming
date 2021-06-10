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
		vector<ll> arr(n);
		ll sum = 0;
		forn(i, n){
			cin >> arr[i];
			sum += arr[i];
		}
		// cout << "sum: " << sum << bline;
		// cout << "n: " << n << bline;
		if ((sum % n) > 0){
			cout << "-1\n";
			continue;
		}
		sum /= n;
		int ans = 0;
		forn(i, n){
			if (arr[i] <= sum)
				pass;
			else{
				ans++;
				// over.pb(arr[i] - sum);
			}
		}
		cout << ans << bline;

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