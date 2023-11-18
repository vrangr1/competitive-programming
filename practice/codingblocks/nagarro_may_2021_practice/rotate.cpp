#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	vector<vector<int>> b(n, vector<int> (n, 0));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
			
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			b[i][j] = a[j][n - i - 1];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
}