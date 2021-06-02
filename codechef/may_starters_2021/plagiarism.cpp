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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> atmpt(k), cts(n, 0), ppl;
		forn(i, k){
			cin >> atmpt[i];
			if (atmpt[i] <= n)
				cts[atmpt[i] - 1]++;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i){
			if (cts[i] > 1){
				ppl.push_back(i + 1);
				ans++;
			}
		}
		cout << ans << " ";
		for (int i = 0; i < ans; ++i){
			cout << ppl[i] << " ";
		}
		// if (ans > 0)
		cout << bline;
	}
	return 0;
}