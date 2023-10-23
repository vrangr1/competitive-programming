/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;


int main(){
	int T;
	cin >> T;
	int n, m, temp;
	// vector<vector<int>> mat;
	while(T--){
		cin >> n >> m;
		vector<vector<int>> mat(n);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> temp;
				mat[i].push_back(temp);
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(i != n-1 && j != m-1){
					if(mat[i][j] == mat[i][j+1]){
						mat[i][j+1] += 1;
					}
					if (mat[i][j] == mat[i+1][j])
						mat[i+1][j] += 1;
				}
				else if(i != n-1){
					if(mat[i][j] == mat[i+1][j])
						mat[i+1][j] += 1;
				}
				else
					if (mat[i][j+1] == mat[i][j])
						mat[i][j+1] += 1;
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << mat[i][j] << " ";
			}
			cout << bline;
		}
		mat.clear();
	}
	
	return 0;
}