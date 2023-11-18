/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)

typedef long long int ll;


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		assert(k == 1);
		vector<ll> arr;
		int ct = 1;
		cin >> arr[0];
		// if (arr[0] < 0){

		// 	continue;
		// }
		forsn(i, 1, n){
			cin >> arr[ct];
			if (arr[ct] > 0 && arr[ct - 1] > 0){
				arr[ct - 1] += arr[ct];
				arr.erase(arr.begin() + ct);
			}
			else{
				ct++;
			}
		}
		n = ct;
		while(n > 0 && arr[0] < 0){
			arr.erase(arr.begin());
			n--;
		}
		while(n > 0 && arr[n - 1] < 0){
			arr.erase(arr.begin() + n - 1);
			n--;
		}
		int mx = 0;
		vector<ll> prsum(n, 0);
		prsum[0] = arr[0];
		ll neg = 0;
		int last = 0;
		forn(i, n){
			if (arr[i] < 0){
				neg += arr[i];
				continue;
			}
			
		}

	}
	return 0;
}