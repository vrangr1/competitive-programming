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
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
#define maxn 1000010
#define mod 1000000007
vector<bool> primes(maxn, true);
vector<int> parr;


void sieve(){
	primes[0] = false;
	primes[1] = false;
	for (ll p = 2; p < maxn; ++p){
		if (primes[p]){
			parr.push_back(p);
			for(ll i = p * p ; i < maxn; i = i + p)
				primes[i] = false;
		}
	}
}


int calc_pf(int n){
	int ct = 0;
	for(int i = 0; /*assert(i < parr.size()),*/ parr[i] <= n; ++i){		
		if (n % parr[i] == 0){
			ct++;
		}
	}
	return ct;
}


ll findct(vector<int> &arr, int sm, vector<vector<ll>> &dp){
	int n = arr.size();
	if (arr[0] <= sm)
		dp[0][arr[0]] = 1;
	for(int i = 1; i < n; ++i){
		forn(j, sm + 1){
			if (j == arr[i])
				dp[i][j] = 1;
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (j >= arr[i]){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i]]) % mod;
			}
		}
	}
	return dp[n-1][sm];
}


int main(){
	fastIO;
	int l, r, s;
	cin >> l >> r >> s;
	if (s == 0 && l > 1){
		cout << 1;
		return 0;
	}
	else if (s == 0){
		cout << 2;
		return 0;
	}
	
	sieve();
	vector<int> pfact;
	
	forsn(i, l, r)
		pfact.pb(calc_pf(i));
	
	vector<vector<ll>> dp(r - l + 1, vector<ll> (s + 1, 0ll));
	cout << findct(pfact, s, dp);
	return 0;
}


template <typename type> void print(vector<vector<type>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}


template <typename type> void print(vector<type> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}