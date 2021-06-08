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
void prll(vector<vector<ll>> &arr);
void prll(vector<ll> &arr);


int main(){
	fastIO;
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		ll temp, ans = temp;
		cin >> temp;
		ans = temp;
		ll cur = temp;
		ll mx = temp;
		bool vis = false;
		if (cur < 0){
			cur = 0;
		}
		else{
			vis = true;
		}
		
		forn(i, n -1){
			cin >> temp;
			if (mx < temp)
				mx = temp;
			cur += temp;
			if (cur < 0){
				cur = 0;
			}
			else{
				vis = true;
				if (ans < cur)
					ans = cur;
			}

		}
		if (!vis){
			cout << "Cannot study - " << mx << bline;
			continue;
		}
		else{
			if (ans > 0)
				cout <<"Can study - ";
			else
				cout <<"Cannot study - ";
			cout << ans << bline;
			continue;
		}
	}
	return 0;
}


void prll(vector<vector<ll>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}


void prll(vector<ll> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}