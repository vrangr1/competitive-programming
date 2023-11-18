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
	int n;
	while(T--){
		cin >> n;
		int rev = 0;
		while(n){
			rev = rev*10 + n%10;
			n /= 10;
		}
		cout << rev << bline;
	}
	
	return 0;
}