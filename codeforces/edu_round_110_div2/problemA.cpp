/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define push_back(a) pb(a)
typedef long long int ll;


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		vector<int> arr(4);
		forn(i, 4){
			cin >> arr[i];
		}
		int mx = *max_element(arr.begin(), arr.end());
		int a, mx2 = (arr[0] == mx? 1: 0), c;
		a = arr[mx2];
		forn(i, 4){
			if (arr[i] == mx)
				c = i;
			else if(arr[i] > a){
				a = arr[i];
				mx2 = i;
			}
		}
		if ((mx2 < 2 && c >= 2) || (mx2 >= 2 && c < 2)){
			cout << "YES\n";
		}
		else
			cout << "NO\n";

	}
	return 0;
}