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
#define pass (void)0
typedef long long int ll;


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		ll D, d, p, q;
		cin >> D >> d >> p >> q;
		ll n = D/d;
		ll ans = (n * ((2 * p) + ((n - 1) * q)) ) / 2;
		ans *= d;
		ans += (p + (n) * q) * (D % d);
		cout << ans << bline;
	}
	return 0;
}