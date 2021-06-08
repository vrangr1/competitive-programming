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
ll x, y;

inline ll dist(ll a, ll b){
	return ((a-x)*(a-x) + (b-y)*(b-y));
}


bool comp(const pair<pair<ll,ll>, char> &a, const pair<pair<ll,ll>, char> &b){
	return dist(a.first.first, a.first.second) < dist(b.first.first, b.first.second);
}


int main(){
	fastIO;
	// int T;
	// cin >> T;
	// while(T--){
		int n, k;
		cin >> x >> y >> n >> k;
		vector<pair<pair<ll,ll>, char>> sites(n);
		forn(i, n){
			cin >> sites[i].first.first >> sites[i].first.second >> sites[i].second;
		}
		sort(sites.begin(), sites.end(), comp);
		int s = 0, x = 0;
		// cout <<"chosen: \n";
		forn(i, k){
			// cout << "x, y, ch: " << sites[i].first.first << ", " << sites[i].first.second << ", " << sites[i].second << bline;
			if (sites[i].second == 'X')
				x++;
			else
				s++;
		}
		if (s > x){
			cout << "IT IS EXHILARATING";
		}
		else{
			cout << "EASY AS CAKE";
		}

	// }
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