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
void print(vector<vector<int>> &arr);
void print(vector<int> &arr);


int main(){
	fastIO;
	char a = 'a';
	bool fin = false;
	forn(i, 26)
		cout << (char)(a + i);
	forn(i, 26){
		char b = 'a';
		forn(j, 26){
			// if (i == 5 && j == 7){
			// 	fin = true;
			// 	// continue;
			// 	break;
			// }
			cout << (char)(a + i) << (char)(b + j);
		}
		// if (i == 10 && fin)
		// 	break;
		// if (fin)
		// 	break;
	}
	cout << "aaa";
	return 0;
}


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