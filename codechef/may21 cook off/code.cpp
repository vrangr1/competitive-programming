/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long ll;


inline ll get_val(ll x, ll y){
	return (((y * (y - 1))/2) + ((x - 1) * (y - 1)) + x + ((x * (x - 1)) / 2));
}




int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin >> T;
	ll x1, y1, x2, y2;
	int x, y;
	ll ans;
	while (T--){
		cin >> x1 >> y1 >> x2 >> y2;
		ans = get_val(x1, y1);
		x = 1;
		y = 1;
		if (x1 < x2)
			x = -1;
		if (y1 < y2)
			y = -1;
		// ll temp;
		while(y2 != y1){
			// cout << "cur: "<< x2 << " " << y2 << bline;
			// temp = get_val(x2, y2);
			// cout << "val: " << temp << bline;
			ans += get_val(x2, y2);
			// ans += temp;
			y2 += y;
		}
		while (x2 != x1){
			// cout << "cur: "<< x2 << " " << y2 << bline;
			// temp = get_val(x2, y2);
			// cout << "val: " << temp << bline;
			ans += get_val(x2, y2);
			// ans += temp;

			x2 += x;
		}
		
		cout << ans << bline;
	}	
	return 0;
}