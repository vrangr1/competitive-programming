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
#define pb(a) push_back(a)
#define pass (void)0
typedef long long int ll;
void print(vector<vector<int>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}
void print(vector<int> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}
#define mod 998244353


vector<vector<int>> (int h, vector<vector<int>> &mat, vector<int> &arr){
	if (h == 6){
		mat[0][0] = 13;
		mat[0][1] = 378;
		mat[1][0] = 1;
		arr[0] = 547;
		arr[1] = 13;
		return;
	}
	else if (h == 5){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
	//not done from here on:
	else if (h == 4){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
	else if (h == 3){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
	else if (h == 2){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
	else if (h == 1){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
}


int main(){
	fastIO;
	int h, w;
	cin >> h >> w;
	vector<vector<int>> mat(2, vector<int> (2, 0));
	vector<int> arr(2, 0);
	init(h, mat, arr);
	return 0;
}