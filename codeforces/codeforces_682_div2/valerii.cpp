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
	int n, temp;
	bool check;
	vector<int> ar;
	// vector<bool> two(32, false);
	while(T--){
		cin >> n;
		// for(int i = 0; i < 32; ++i){
		// 	two[i] = false;
		// }
		check = true;
		ar.clear();
		for(int i = 0; i < n; ++i){
			cin >> temp;
			ar.push_back(temp);
			// temp = log2(temp);
			// if(two[temp]){
			// 	check = false;
			// 	break;
			// }
			// else
			// 	two[i] = true;
		}
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				if (ar[i] == ar[j]){
					check = false;
					break;
				}
			}
		}
		if(!check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}