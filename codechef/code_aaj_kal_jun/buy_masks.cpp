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

void print(vector<pair<double,double>> &cst){
	cout << "costs: " << bline;
	forn(i, 3){
		cout << "cost, ct: " << cst[i].first << ", " << cst[i].second << bline;
	}
}
bool comp(const pair<double,double> &a, const pair<double, double> &b){
	return a.first < b.first;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		double n;
		vector<pair<double, double>> cst(3);
		cin >> n >> cst[0].first >> cst[1].first >> cst[2].first;
		cst[0].second = 10;
		cst[1].second = 5;
		cst[2].second = 1;
		// print(cst);
		forn(i, 3)
			cst[i].first = cst[i].first / cst[i].second;
		// print(cst);
		sort(cst.begin(), cst.end(), comp);
		// print(cst);
		ll ind = 0, ct = n/cst[ind].second;
		ll cost = 0;
		// cout <<"ct: " << ct<< bline;
		cost += (ct * ((ll)(cst[ind].first * cst[ind].second)));
		n -= ((ll)(ct * (ll)(cst[ind].second)));
		// cout <<"cost: " << cost<<bline;
		// cout <<"n: " << n << bline;
		
		if (n == 0){
			cout << (ll)(cost) << bline;
			continue;
		}
		ind++;
		ct = n / cst[ind].second;
		cost += ct * ((ll)(cst[ind].first * cst[ind].second));

		n -= (ll)(ct * (ll)(cst[ind].second));
		// cout << "ind: " << ind << bline;
		// cout << "ct: " << ct << bline;
		// cout << "cost: " << cost << bline;
		// cout << "n: " << n << bline;
		if (n == 0){
			cout << (ll)(cost) << bline;
			continue;
		}
		ind++;
		ct = n / cst[ind].second;
		cost += ct * ((ll)(cst[ind].first * cst[ind].second));
		n -= (ll)(ct * (ll)(cst[ind].second));
		// cout << "ind: " << ind << bline;
		// cout << "ct: " << ct << bline;
		// cout << "cost: " << cost << bline;
		// cout << "n: " << n << bline;
		if (n == 0){
			cout << (ll)(cost) << bline;
			continue;
		}
		else{
			// cout << "prob: " << n << bline;
			assert(false);
		}
		// c = min(c, x.first/x.second);
		// c = min(c, y.first/y.second);
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