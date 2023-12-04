#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int> (3, 0));
	vector<vector<int>> ar2(n, vector<int> (3,0));
	cin >> arr[0][0];
	cin >> arr[0][1];
	cin >> arr[0][2];
	ar2[0][0] = arr[0][0];
	ar2[0][1] = arr[0][1];
	ar2[0][2] = arr[0][2];
	for(int i = 1; i < n; ++i){
		cin >> arr[i][0];
		cin >> arr[i][1];
		cin >> arr[i][2];
		ar2[i][0] = std::min(ar2[i - 1][1], ar2[i - 1][2]) + arr[i][0];
		ar2[i][1] = std::min(ar2[i - 1][0], ar2[i - 1][2]) + arr[i][1];
		ar2[i][2] = std::min(ar2[i - 1][1], ar2[i - 1][0]) + arr[i][2];
	}
	int ans = std::min(ar2[n-1][0], ar2[n-1][1]);
	ans = std::min(ar2[n-1][2], ans);
	cout << ans;
	return 0;
}

