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
#define base 50
typedef long long int ll;
void print(vector<vector<int>> &arr);
void print(vector<int> &arr);
#define maxn 1000010
#define mod 1000000007
vector<bool> primes(maxn);
vector<int> parr;


void sieve(){
	
	forn(i, maxn)
		primes[i] = true;
	primes[0] = false;
	primes[1] = false;
	// cout << "come on\n";
	// return;
	for (ll p = 2; p < maxn; ++p){
		// cout << "hey\n";
		if (primes[p]){
			parr.push_back(p);
			for(ll i = p * p ; i < maxn; i = i + p)
				primes[i] = false;
		}
	}
	// cout << "finally\n";

}


int calc_pf(int n){
	int ct = 0;
	// cout << "n: "<< n << bline;
	// cout << "root n: " << sqrt(n) << bline;
	for(ll i = 0; /*assert(i < parr.size()),*/ parr[i] <= n; ++i){
		
		if (n % parr[i] == 0){
			ct++;
		}
	}
	// cout << "#pf: "<< ct << bline;
	return ct;
}


int findct(vector<int> &arr, int sm, vector<vector<int>> &dp){
	int i = arr.size() - 1;
	// for(; i >= 0; --i){
	// print(arr);
	// cout << "sm: " << sm << bline;
	// return 0;
	for(int j = 0; j <= sm; ++j){
		if (arr[i] == j)
			dp[i][j] = 1;
	}
	for(i = i - 1; i >=0; --i){
		forn(j, sm + 1){
			if (j == arr[i])
				dp[i][j] = 1;
			dp[i][j] += (dp[i + 1][j]) % mod;
			if (j >= arr[i]){
				dp[i][j] += dp[i + 1][j - arr[i]];
				dp[i][j] = dp[i][j] % mod;
			}

		}
	}
	return dp[0][sm];
	// }
}
// int findct(vector<int> &arr, int i, int required_sum, int n, vector<vector<int>> &dp, vector<vector<int>> &v)
// {
//     // Base case
//     if (i == n) {
//         if (required_sum == 0)
//             return 1;
//         else
//             return 0;
//     }
 
//     if (v[i][required_sum + base])
//         return dp[i][required_sum + base];
 
//     v[i][required_sum + base] = 1;
 
//     // Recurrence relation
//     dp[i][required_sum + base]
//         = findct(arr, i + 1, required_sum, n, dp, v)
//           + findct(arr, i + 1, required_sum - arr[i], n, dp, v);
//     return dp[i][required_sum + base];
// }

int main(){
	fastIO;
	int l, r, s;
	// cout << "something\n";
	// return 0;
	sieve();
	// cout << "hello" << bline;
	cin >> l >> r >> s;
	vector<int> pfact;
	if (l > r)
		swap(l,r);
	// return 0;
	// print(parr);
	forsn(i, l, r)
		pfact.pb(calc_pf(i));
	// print(pfact);
	// return 0;
	vector<vector<int>> dp(r - l + 1, vector<int> (s + 1, 0));
	// return 0;
	// vector<vector<int>> v(l -r + 1, vector<int> (s + 200, 0));
	// cout << findct(pfact ,0, s, l -r + 1, dp, v);

	cout << findct(pfact, s, dp);
	return 0;
}


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