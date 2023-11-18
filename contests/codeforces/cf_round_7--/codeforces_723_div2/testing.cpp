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
	int n;
	cin >> n;
	vector<int> arr(n);
	// vector<ll> sum(n);
	ll sum = 0;
	cin >> arr[0];
	sum = arr[0];
	map<int, int, greater<int>> mp;
	int bk = -1;
	int mxdist = 1;
	int dist = 1;
	if (sum < 0){
		cout << 0;
		return 0;
	}
	// cout << "i: " << 0 << ", sum: " << sum << ", arr[i]: " << arr[0]<< bline;
	forsn(i, 1, n - 1){
		cin >> arr[i];

		
		if (sum + arr[i] < 0){
			int len = mp.size();
			ll nsum = 0;
			bool pos = false;
			while(len > 0){
				nsum += mp.begin()->first;
				// cout << "first: " << mp.begin()->first << bline;
				if (nsum + arr[i] + sum < 0){
					mp.erase(mp.begin());
					len--;
					dist--;
				}
				else{
					mp.erase(mp.begin());
					len--;
					dist--;
					sum += nsum + arr[i];
					pos = true;
					break;
				}
			}
			if (!pos){
				cout << mxdist;
				return 0;
			}
		}
		else{
			sum += arr[i];
		}
		if (arr[i] < 0)
			mp.insert({-arr[i], i});
		// cout << "i: " << i << ", sum: " << sum << ", arr[i]: " << arr[i]<< bline;
		dist += 1;
		if (mxdist < dist)
			mxdist = dist;
	}
	cout << mxdist;

	return 0;
}