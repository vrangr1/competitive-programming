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
		cin>>n;
		int temp;
		forn(i, n)
			cin >> temp;
		cout << n * 3 << bline;
		forsn(i, 1, n/2){
			cout << "1 " << i * 2 - 1 << " " << 2 * i << bline;
			cout << "2 " << 2 * i - 1 << " " << 2 * i << bline;
			cout << "1 " << i * 2 - 1 << " " << 2 * i << bline;
			cout << "1 " << 2 * i - 1 << " " << 2 * i << bline;
			cout << "2 " << i * 2 - 1 << " " << 2 * i << bline;
			cout << "1 " << i * 2 - 1 << " " << 2 * i << bline;
		}
	}
	return 0;
}