/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, j, n) for (int i = j; j < n; ++i)

typedef long long int ll;

class SudokuTypo{
	public: 
	int fix(vector <int> digits){
	 	int n = 9;
		int row, col;
		for (int i = 0; i < n; ++i){
			int sum = 0;
			forn(j, n){
				sum += digits[i*n + j];
			}
			if (sum != 45){
				row = i;
				break;
			}
		}
		for (int i = 0; i <n; ++i){
			int sum = 0;
			forn(j, n){
				sum += digits[j*n + i];
			}
			if (sum != 45){
				col = i;
				break;
			}
		}
		return digits[row * n + col];
	}
};
