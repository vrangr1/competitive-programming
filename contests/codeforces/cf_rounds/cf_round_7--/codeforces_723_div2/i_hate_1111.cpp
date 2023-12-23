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
	// fastIO;
	int n;
	cin >> n;
	vector<int> arr(n), pos, neg;
	ll sum = 0;
	int ct = 0;
	forn(i, n){
		cin>>arr[i];
		if (arr[i] >= 0){
			sum += arr[i];
			ct++;
		}
		else{
			neg.push_back(arr[i]);
		}
	}
	sort(neg.begin(), neg.end(), greater<int>());
	ll nsum = 0;
	forn(i, neg.size()){
		nsum += neg[i];
		if (sum + nsum >= 0){
			ct++;
		}
		else
			break;
	}
	cout << ct;
	return 0;
}