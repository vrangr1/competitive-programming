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

#define inf 1000000000

int main(){
	fastIO;
	int n;
	cin >> n;
	int k = 0;
	vector<int> chairs(n), loc;
	forn(i, n){
		cin >> chairs[i];
		if (chairs[i] == 1)
			loc.push_back(i);

	}
	k = loc.size();
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, inf));
	dp[0][0] = 0;
	forn(i, n){
		forn(j, k +1){
			if (dp[i][j] == inf) continue;
			dp[i + 1][j] = min(dp[i][j], dp[i+1][j]);
			if (j < k && chairs[i] == 0){
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(loc[j] - i));
			}
		}
	}
	cout << dp[n][k];
	return 0;
}