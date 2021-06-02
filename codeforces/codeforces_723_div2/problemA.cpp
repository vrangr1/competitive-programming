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
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(2 * n);
		forn(i, 2 * n)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		int a = 0, b = 2 * n - 1;
		bool st = true;
		while(a <= b){
			if (st){
				cout << arr[a] << " ";
				a++;
				st = !st;
			}
			else{
				cout << arr[b] << " ";
				b--;
				st = !st;	
			}
		}
		cout << bline;
	}

	return 0;
}