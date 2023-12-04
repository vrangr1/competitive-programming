#include<bits/stdc++.h>

using namespace std;
// #define tot 100

int main(){
	int T, n, mn, mx, ele;
	bool sort = true;
	cin >> T;
	while(T--){
		cin >> n;
		sort = true;
		for (int i = 0; i < n; ++i){
			cin >> ele;
			if (ele == 1)
				mn = i;
			if (ele == n)
				mx = i;
			if (ele != i + 1)
				sort = false;
		}
		if (sort)
			cout << "0\n";
		else if (mn == 0 || mx == n - 1)
			cout << "1\n";
		else if (mn != n - 1 || mx != 0)
			cout << "2\n";
		else
			cout << "3\n";
	}

	return 0;
}

