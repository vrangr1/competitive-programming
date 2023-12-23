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


ll ret(ll a){
	if (a < 0)
		return -a;
	return a;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		ll a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		ll n = ret(a-c) +ret(b - d);
		if (n > k){
			cout << "NO\n";
			continue;
		}
		if (ret(n - k) % 2 == 0){
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}