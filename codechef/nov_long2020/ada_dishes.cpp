/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;

int power(int a, int b){
	// float temp;
	if (b == 0)
		return 1;
	else if (b % 2 == 0){
		return power(a, b/2) * power(a, b/2);
	}
	else
		return a * power(a, b/2) * power (a, b/2);
}

int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

void plusone(vector<int> &bin, int n){
	bool carry = true;
	for(int i = 0; i < n; ++i){
		if (carry){
			if (bin[i])
				bin[i] = 0;
			else{
				bin[i] = 1;
				carry = false;
				break;
			}
		}
	}
}

int main(){
	int T;
	cin >> T;
	int n, temp, time, t1, t2;
	vector<int> cook;
	while(T--){
		cin >> n;
		cook.clear();
		time = 0;
		for(int i = 0; i < n; ++i){
			cin >> temp;
			time += temp;
			cook.push_back(temp);
		}
		vector<int> bin(n,0);
		bin[0] = 1;
		int ct = power(2, n);
		for(int i = 0; i < ct; ++i){
			t1 = 0;
			t2 = 0;
			for(int j = 0; j < n; ++j){
				(bin[j] == 0)? t1 += cook[j]: t2 += cook[j];
			}
			temp = max(t1, t2);
			if (temp < time)
				time = temp;
			plusone(bin, n);
		}
		bin.clear();
		cout << time << endl;

	}
	
	return 0;
}