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
void print(vector<vector<int>> &arr);
void print(vector<int> &arr);
#define maxn 1300000
vector<bool> prime(maxn, true);
vector<int> primect(maxn);

void sieve(){
	for(int p = 2; p * p < maxn; ++p){
		if (prime[p])
			for(int i = p * p; i < maxn; i+= p)
				prime[i] = false;
	}
	primect[0] = 0;
	primect[1] = 0;
	primect[2] = 1;
	forsn(i, 3, maxn-1){
		if (prime[i])
			primect[i] = primect[i - 1] + 1;
		else
			primect[i] = primect[i-1];
	}
}

int main(){
	fastIO;
	int T;
	sieve();
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int k = lower_bound(primect.begin(), primect.end(), n) - primect.begin();
		assert(primect[k] == n);
		// while(primect[k] == n)
		// 	--k;
		// k++;
		// cout << "k: " << k << bline;
		// int ans = 0;
		// forsn(i, 1, k)
		// 	ans = ans ^ i;
		// cout << ans << bline;
		int rem = k % 4;
		if (rem == 0)
			cout << k <<bline;
		else if (rem == 1)
			cout << 1 << bline;
		else if (rem == 2)
			cout << k + 1 << bline;
		else
			cout << 0 << bline;
	}
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