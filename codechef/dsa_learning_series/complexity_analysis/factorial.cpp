/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long ll;

inline int power(int a, int b){
	return (int)(pow(a, b) + 0.2);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	while(T--){
		cin >> n;
		int i = 1, ct = 0;
		while(n / (power(5, i)) > 0){
			ct += (n / power(5, i));
			++i;
		}
		cout << ct << bline;
	}

	return 0;
}