/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main(){
	int T;
	cin >> T;
	int n, temp;
	vector<int> a;
	vector<pair<int,int>> b;
	while(T--){
		cin >> n;
		a.clear();
		vector<int> ans(n);
		b.clear();
		for(int i = 0; i < n; ++i){
			cin >> temp;
			a.push_back(temp);
			b.push_back(make_pair(temp, i));
		}
		sort(b.begin(), b.end());
		if (n == 1){
			ans[0] = a[0];
		}
		for(int i = 0; i < n; ++i){
			ans[b[i].second] = b[i].first;
			if (b[i].second != 0 && a[b[i].second - 1] > b[i].first){
				ans[b[i].second - 1] = b[i].first + 1;
			}
			if(b[i].second != n-1 && a[b[i].second + 1] > b[i].first){
				ans[b[i].second + 1] = b[i].first + 1; 
			}
		}

	}
	
	return 0;
}