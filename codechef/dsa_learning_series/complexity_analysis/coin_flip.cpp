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
	int g, n, i, q;
	while(T--){
		cin >> g;
		while(g--){
			cin >> i >> n >> q;
			if (i == q)
				cout << n/2 << bline;
			else
				cout << n - (n/2) << bline;
		}
	}

	return 0;
}