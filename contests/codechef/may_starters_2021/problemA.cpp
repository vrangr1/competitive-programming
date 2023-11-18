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
		int m, x, d;
		cin >> x >> m >> d;
		int ans = (m * x <= x + d) ? m * x : x + d;
		cout << ans << bline;
	}
	return 0;
}