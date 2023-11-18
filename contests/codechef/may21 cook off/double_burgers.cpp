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


ll power(ll a, ll b){
	return (ll)(pow(a, b) + (ll)0.1);
}


int main(){
	fastIO;
	int T;
	cin >> T;
	// cout << "T: " << T << bline;
	while(T--){
		ll x, y;
		cin >> x >> y;
		if (y % x != 0){
			cout << -1 << bline;
			continue;
		}
		y /= x;
		ll ans = 0, cur;
		vector<bool> used(65, false);
		bool cont = false;
		// cout << "hello?\n";
		int bk = 0;
		while(y != 0){
			bk++;
			if (bk > 1)
				ans += 1;
			cur = log2(y + 1);
			while(used[cur] && cur > 0)
				cur--;
			if (cur <= 0){
				cont = true;
				break;
			}
			
			used[cur] = true;
			ans += (cur);
			if (cur != 0)
				y -= (power(2, cur) - 1);
			else
				y = 0;
		}
		if (cont){
			cout << -1 << bline;
			continue;
		}
		cout << ans << bline;

	}

	return 0;
}