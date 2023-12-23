#include<bits/stdc++.h>

using namespace std;

int main(){
	int T, n;
	cin >> T;
	string s;
	while(T--){
		cin >> n;
		cin >> s;
		bool all = true;
		int ct = 0;
		for (int i = 0; i < n; ++i){
			if (s[i] == '0'){
				all = false;
				ct++;
			}
			if (!all && ct > 1)
				break;
		}
		if (all){
			cout << "DRAW\n";
			continue;
		}
		if (n % 2 == 1 && s[n/2] == '0' && ct > 1)
			cout << "ALICE\n";
		else
			cout << "BOB\n";
		// if (n == 3 && s[1] == '0')
		// 	cout << "BOB\n";
		// else if (n == 1)
		// 	cout << "BOB\n";
		// else if (n % 2 == 1 && s[n/2] == '0' && ct > 1){
		// 	cout << "ALICE\n";
		// }
		// else if (n % 2 == 1 && s[n/2] == '1')
		// 	cout << "BOB\n";
		// else
		// 	cout << "BOB\n";
	}

	return 0;
}

