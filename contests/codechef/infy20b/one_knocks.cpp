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
	int X, Y, a, b, diff, ans;
	while(T--){
		cin >> X >> Y;
		diff = Y - X;
		if (diff == 0){
			ans = 0;
		}
		else if (diff > 0){
			if (diff % 2){
				ans = 1;
			}
			else{
				if ( (diff/2) % 2 == 0){
					ans = 3;
				} 
				else
					ans = 2;
			}
		}
		else{
			diff *= -1;
			if (diff % 2){
				ans = 2;
			}
			else{
				ans = 1;
			}
		}
		cout << ans << endl;
	}


	return 0;
}