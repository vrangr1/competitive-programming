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
#define pb(a) push_back(a)
#define pass (void)0
typedef long long int ll;
void print(vector<vector<int>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}
void print(vector<int> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}



inline int val(int cursum, int lim, int cur){
	if (cursum + cur > lim)
		return cursum;
	return cursum+cur;
}


int main(){
	fastIO;
	int n;
	cin >> n;
	vector<int> tm(n);
	int sm = 0;
	forn(i, n){
		cin >> tm[i];
		sm += tm[i];
	}
	int orig = sm;
	sm /= 2;
	vector<vector<int>> dp(n + 1, vector<int> (sm + 1, 0));
	forn(i, n + 1){
		forn(j, sm + 1){
			if (i == 0 || j == 0)
				continue;
			if (tm[i - 1] <= j){
				dp[i][j] = max(tm[i - 1] + dp[i - 1][j - tm[i - 1]], dp[i - 1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];

		}
	}
	// cout << "dp: " << dp[n][sm] << bline;
	cout << max(dp[n][sm], orig - dp[n][sm]);
	return 0;
}