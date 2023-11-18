/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < (int)n; i++)

typedef long long int ll;


// bool check(vector<int> &arr, int n, int ind){
// 	int prev = arr[0];
// 	int cost = 0;
// 	for (int i = 1; i <= ind; ++i){
// 		if (arr[i] - prev >= arr[ind]){
// 			prev = arr[i];
// 			continue;
// 		}
// 		else{
// 			cost++;
// 		}
// 	}
// 	// if ()
// }


// int solve(vector<int> &arr, int n){

// 	if (check(arr, n, n - 1))
// 		return n;

// }


int main(){
	// fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		bool pos = true;
		int sm = -1;
		vector<int> neg;
		forn(i,n){
			cin >> arr[i];
			if (arr[i] > 0 && sm == -1)
				sm = arr[i];
			else if (arr[i] > 0 && sm > arr[i])
				sm = arr[i];
			else if (arr[i] <= 0)
				neg.push_back(arr[i]);
		}
		if (sm == -1){
			cout << n << bline;
			continue;
		}
		int ans = neg.size();
		if (ans == 0){
			cout << 1 << bline;
			continue;
		}
		sort(neg.begin(), neg.end());
		int cost = 0;
		int prev = neg[0];
		bool viable = true;
		for(int i = 1; i < ans; ++i){
			if (neg[i] - prev >= sm){
				prev = neg[i];
			}
			else
				cost++;
			if (cost >= 1){
				viable = false;
				break;
			}
		}
		if (!viable){
			cout << ans << bline;
			continue;
		}
		else{
			cout << ans + 1 << bline;
			// cout << "here?\n";
			continue;
		}

	}
	return 0;
}