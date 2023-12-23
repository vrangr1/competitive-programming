/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main(){
	int T;
	cin >> T;
	int n;
	while(T--){
		cin >> n;
		int min, temp;
		cin >> temp;
		min = temp;
		for(int i = 1; i < n; ++i){
			cin >> temp;
			if (min > temp)
				min = temp;
		}
		if (n % min == 0){
			cout << n/min << endl;;
		}
		else{
			cout << (n/min) + 1 << endl;
		}

	}
	return 0;
}