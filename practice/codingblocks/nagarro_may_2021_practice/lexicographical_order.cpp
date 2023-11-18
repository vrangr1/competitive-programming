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

typedef long long int ll;


int main(){
	fastIO;
	int n;
	cin >> n;
	vector<string> arr(n + 1);
	forsn(i, 0, n){
		arr[i] = to_string(i);
	}
	sort(arr.begin(), arr.end());
	forn(i, n + 1){
		cout << arr[i] << " ";
	}
	// cout << s;
	return 0;
}	