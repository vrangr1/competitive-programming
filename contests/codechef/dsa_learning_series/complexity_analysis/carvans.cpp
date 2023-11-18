/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long ll;


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	int ct = 1, spd, car;
	while (T--){
		cin >> n;
		cin >> spd;
		ct = 1;
		for (int i = 1; i < n; ++i){
			cin >> car;
			if (car <= spd){
				ct++;
				spd = car;
			}
		}
		cout << ct << bline;
	}

	return 0;
}