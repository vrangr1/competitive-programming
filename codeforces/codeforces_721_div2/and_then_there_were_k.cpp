#include<bits/stdc++.h>

using namespace std;

inline int power(int n, int p){
	return (int)(pow(n,p));
}


bool check(int n, int len){

	int num = n / power(2, len);
	// cout << "num: " << num;
	if (num % 2 == 1)
		return true;
	return false;
}


// inline int leftmost(int n){

// 	int len = log2(n);
// 	int cpy = len - 1;
// 	// cout << "n: " << n << endl;
// 	// cout << "cpy1: " << cpy << endl;
// 	while(cpy > 0 && !check(n, cpy))
// 		cpy--;
// 	// cout << "cpy2: " << cpy << endl;
// 	int ans = power(2, len) + power(2, cpy) - 1;
// 	// cout << "ans: " << ans << endl;
// 	if (cpy == 0)
// 		ans--;
// 	return ans;
// }

inline int leftmost(int n){
	int len = log2(n);
	return power(2, len) - 1;
}


int main(){
	int T, n;
	cin >> T;
	int k;
	while(T--){
		cin >> n;
		if (n == 0){
			cout << 0 << endl;
			continue;
		}
		k = leftmost(n);
		cout << k << endl;
	}

	return 0;
}

