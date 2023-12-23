/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mod 998244353

typedef long long int ll;


void upd(vector<ll> &arr, int n, int val){
	for (int i = val * 2; i <= n; i += val){
		arr[i] = (arr[i] + (ll)1) % mod;
	}
}


int main(){
	//fastIO;
	int n;
	cin >> n;
	vector<ll> arr(n + 1, 1);
	arr[1] = 1;
	upd(arr, n, 1);
	ll cursum = arr[1];
	for(int i = 2; i <= n; ++i){
		arr[i] = (arr[i] + cursum) % mod;
		cursum = (cursum + arr[i]) % mod; 
		upd(arr, n, i);

	}
	cout << arr[n];
	return 0;
}