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


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int t, r, b, rad;
		cin >> t >> r >> b >> rad;
		if (t > r)
			swap(t, r);
		if (b + rad < t){
			cout << r - t << bline;
			continue;
		}
		if (b - rad > r){
			cout << r - t << bline;
			continue;
		}
		// if (b - rad >= t && b + rad <= r){
		// 	cout << 2 * r << bline;
		// 	continue;
		// }
		// if (b + rad > r){
		// 	cout << r - max(b - rad, t) << bline;
		// 	continue;
		// }
		cout << r - t - min(b + rad, r) + max(b - rad, t) << bline;
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