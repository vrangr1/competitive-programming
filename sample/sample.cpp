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
		forn(j, arr[i].size()){
			cout << arr[i][j] << " ";
		}
		cout << bline;
	}
}


void print(vector<int> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size()){
		cout << arr[i] << " ";
	}
	cout << bline;
}


int main(){
	fastIO;
	int T;
	vector<int> arr{1, 2, 3};
	print(arr);
	vector<vector<int>> ar2;
	ar2.pb(arr);
	print(ar2);
	arr[1] = 4;
	print(arr);
	ar2.pb(arr);
	print(ar2);
	return 0;
}