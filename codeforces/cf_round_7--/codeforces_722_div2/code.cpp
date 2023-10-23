/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < (int)n; i++)

typedef long long int ll;


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		forn(i, n)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ct = 1;
		int val = arr[0];
		for (int i = 1; i < n; ++i){
			if (arr[i] != val)
				break;
			else
				ct++;
		}
		cout << n - ct << bline;
	}
	return 0;
}