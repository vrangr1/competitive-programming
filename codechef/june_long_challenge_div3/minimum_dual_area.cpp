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


bool comp1(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return a.first < b.first;
}


bool comp2(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return a.second < b.second;
}


inline ll calc_area(ll x11, ll x12, ll y11, ll y12, ll x21, ll x22, ll y21, ll y22){
	return ( (abs(x11 - x12) * abs(y11 - y12)) + (abs(x21 - x22) * abs(y21 - y22)) );
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<pair<ll, ll>> arr(n), mnmx(n-1);
		forn(i, n)
			cin >> arr[i].first >> arr[i].second;
		if (n == 1){
			cout << 0 << bline;
			continue;
		}
		sort(arr.begin(), arr.end(), comp1);
		mnmx[n-2].first = arr[n-1].second;
		mnmx[n-2].second = arr[n-1].second;
		for (int i = n - 3; i >= 0; --i){
			mnmx[i].first = min(arr[i + 1].second, mnmx[i + 1].first);
			mnmx[i].second = max(arr[i + 1].second, mnmx[i + 1].second);
		}
		ll ans = calc_area(arr[0].first, arr[0].first, arr[0].second, arr[0].second, arr[1].first, arr[n - 1].first, mnmx[0].first, mnmx[0].second);
		ll mn = arr[0].second;
		ll mx = arr[0].second;
		forsn(i, 1, n - 2){
			mn = min(mn, arr[i].second);
			mx = max(mx, arr[i].second);
			ans = min(ans, calc_area(arr[0].first, arr[i].first, mn, mx, arr[i + 1].first, arr[n - 1].first, mnmx[i].first, mnmx[i].second));
		}
		sort(arr.begin(), arr.end(), comp2);
		mn = arr[0].first;
		mx = arr[0].first;
		mnmx[n-2].first = arr[n-1].first;
		mnmx[n-2].second = arr[n-1].first;
		for (int i = n - 3; i >= 0; --i){
			mnmx[i].first = min(arr[i + 1].first, mnmx[i + 1].first);
			mnmx[i].second = max(arr[i + 1].first, mnmx[i + 1].second);
		}
		ans = min(ans, calc_area(mn, mx, arr[0].second, arr[0].second, mnmx[0].first, mnmx[0].second, arr[1].second, arr[n - 1].second));
		forsn(i, 1, n - 2){
			mn = min(mn, arr[i].first);
			mx = max(mx, arr[i].first);
			ans = min(ans, calc_area(mn, mx, arr[0].second, arr[i].second, mnmx[i].first, mnmx[i].second, arr[i + 1].second, arr[n - 1].second));
		}
		cout << ans << bline;
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