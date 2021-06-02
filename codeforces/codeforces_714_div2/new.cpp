#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , k, T;
	cin >> T;
	while (T--){
		cin >> n >> k;
		if (n < 3){
			cout << -1 << endl;
			continue;
		}
		if ((n % 2 == 1 && ((n - 1)/2) < k ) || ( n % 2 == 0 && n/2  < k + 1)){
			cout << -1 << endl;
			continue;
		}
		int i = n - 1, c = 0;
		cout << i << " " << i + 1 << " " << i - 2 << " ";
		c += 3;
		k--;
		i = i - 2;
		bool chk = false;
		int rem = i;
		while(c < n){
			if (k > 0){
				if (c == n - 2){
					cout << i + 1 << " " << i - 1 << " ";
					i = i - 1;
					rem = i;
					c += 2;
					k--;
					continue;
				}
				cout << i + 1 << " " << i - 2 << " ";
				i = i - 2;
				rem = i;
				c += 2;
				k--;
				
			}
			else{
				if (!chk){
					chk = true;
					i = 1;
				}
				if (i != rem){
					cout << i << " ";
					i++;
					c++;
				}
				else{
					i++;
					cout << i << " ";
					c++;
					i++;
				}
				
			}
			
		}
		cout << endl;
	}

	return 0;
}