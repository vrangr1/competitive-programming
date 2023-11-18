/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

int main(){
	int T;
	cin >> T;
	int N, temp, count;
	vector<int> a;
	while(T--){
		cin >> N;
		count = 0;
		for(int i = 0; i < N; ++i){
			cin >> temp;
			a.push_back(temp);
		}
		for(int i = 0; i < N; ++i){
			for (int j = i+1; j < N; ++j){
				if ((a[i]^a[j]) > max(a[i],a[j])){
					// cout << "nums " << a[i] << " " << a[j] << " xor: " << (a[i]^a[j]) << " max: " << max(a[i],a[j]) << endl;  
					count++;
				}
			}
		}
		cout << count << endl;
		a.clear();
	}
	
	return 0;
}