#include<bits/stdc++.h>

using namespace std;

int main(){
	int T, x, tot;
	cin >> T;
	while(T--){
		cin >> x;
		tot = 100;
		while (x % 2 == 0 && tot % 2 == 0){
			x /= 2;
			tot /= 2;
		}
		while (x % 5 == 0 && tot % 5 == 0){
			x /= 5;
			tot /= 5;
		}
		cout << tot << endl;
	}

	return 0;
}

