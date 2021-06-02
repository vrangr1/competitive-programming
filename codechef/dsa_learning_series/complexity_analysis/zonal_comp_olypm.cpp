/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;


int main(){
	int n, temp;
	lli ans, ar;
	cin >> n;
	vector<int> budgets;
	for(int i = 0; i < n; ++i){
		cin >> temp;
		budgets.push_back(temp);
	}
	sort(budgets.begin(), budgets.end());
	ans = 0;
	for(int i = 0; i < n; ++i){
		ar = (lli)budgets[i]*(lli)(n-i);
		if (ar > ans)
			ans = ar;
	}
	cout << ans;
	return 0;
}