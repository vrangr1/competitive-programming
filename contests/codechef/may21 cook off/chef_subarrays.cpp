/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long ll;



int find_ans(vector<ll> &arr, int n, int k){
	int ans = 0;
	for (int i = 0; i < k; ++i){
		map<int,int> mp;
		int count = 0;
		for (int j = i; j < n; j += k){
			mp[arr[j]]++;
			count = max(count, mp[arr[j]]);
		}
		ans += count;
	}
	return (n - ans);
}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin >> T;
	int n, k;
	while(T--){
		cin >> n >> k;
		vector<ll> arr(n);
		for(int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << find_ans(arr, n, k) << bline;
	}
	return 0;
}