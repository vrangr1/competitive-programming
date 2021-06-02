/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;


int main(){
	int n, k, t1, t2;
	vector<pair<int, int>> xy, lr;
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> t1 >> t2;
		xy.push_back(make_pair(t1, t2));
		cin >> t1 >> t2;
		lr.push_back(make_pair(t1, t2));
	}
	
	
	return 0;
}