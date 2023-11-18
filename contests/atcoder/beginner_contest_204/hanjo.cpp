/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
// #define forn(i, n) for (int i = 0; i < n; i++)
// #define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
// #define pb(a) push_back(a)
// #define pass (void)0
typedef long long int ll;
// void print(vector<vector<int>> &arr){
// 	cout << "2d vector: \n";
// 	forn(i, arr.size()){
// 		forn(j, arr[i].size())
// 			cout << arr[i][j] << " ";
// 		cout << bline;
// 	}
// }
// void print(vector<int> &arr){
// 	cout << "1d vector: \n";
// 	forn(i, arr.size())
// 		cout << arr[i] << " ";
// 	cout << bline;
// }
#define mod 998244353


void init(ll h, vector<vector<ll>> &mat, vector<ll> &arr){
	if (h == 6){
		mat[0][0] = 13;
		mat[0][1] = 378;
		mat[1][0] = 1;
		arr[0] = 547;
		arr[1] = 13;
		return;
	}
	else if (h == 5){
		mat[0][0] = 8;
		mat[0][1] = 118;
		mat[1][0] = 1;
		arr[0] = 182;
		arr[1] = 8;
		return;
	}
	else if (h == 4){
		mat[0][0] = 5;
		mat[0][1] = 36;
		mat[1][0] = 1;
		arr[0] = 61;
		arr[1] = 5;
		return;
	}
	else if (h == 3){
		mat[0][0] = 3;
		mat[0][1] = 11;
		mat[1][0] = 1;
		arr[0] = 20;
		arr[1] = 3;
		return;
	}
	else if (h == 2){
		mat[0][0] = 2;
		mat[0][1] = 3;
		mat[1][0] = 1;
		arr[0] = 7;
		arr[1] = 2;
		return;
	}
	else if (h == 1){
		mat[0][0] = 1;
		mat[0][1] = 1;
		mat[1][0] = 1;
		arr[0] = 2;
		arr[1] = 1;
		return;
	}
}


vector<vector<ll>> mat_mult(vector<vector<ll>> m1, vector<vector<ll>> m2){
	vector<vector<ll>> ans(2, vector<ll> (2, 0));
	ans[0][0] = ((((ll)(m1[0][0]) * (ll)(m2[0][0])) % mod) + (((ll)(m1[0][1]) * (ll)(m2[1][0])) % mod)) % mod;
	ans[0][1] = ((((ll)(m1[0][0]) * (ll)(m2[0][1])) % mod) + (((ll)(m1[0][1]) * (ll)(m2[1][1])) % mod)) % mod;
	ans[1][0] = ((((ll)(m1[1][0]) * (ll)(m2[0][0])) % mod) + (((ll)(m1[1][1]) * (ll)(m2[1][0])) % mod)) % mod;
	ans[1][1] = ((((ll)(m1[1][0]) * (ll)(m2[0][1])) % mod) + (((ll)(m1[1][1]) * (ll)(m2[1][1])) % mod)) % mod;
	return ans;
}


vector<vector<ll>> power(vector<vector<ll>> mat, ll n){
	if (n == 1)
		return mat;
	vector<vector<ll>> ans = power(mat, n/2);
	ans = mat_mult(ans, ans);
	if (n&1)
		ans = mat_mult(ans, mat);
	return ans;
}


void solve(){
	ll h, w;
	cin >> h >> w;
	vector<vector<ll>> mat(2, vector<ll> (2, 0));
	vector<ll> arr(2, 0);
	init(h, mat, arr);
	if (w < 3){
		cout << arr[w % 2];
		return;
	}
	mat = power(mat, w - 2);
	int ans = ( ( ((ll)(mat[0][0]) * (ll)(arr[0])) % mod) + (((ll)(mat[0][1]) * (ll)(arr[1])) % mod) ) % mod;
	cout << ans;
}


int main(){
	fastIO;
	solve();
	return 0;
}