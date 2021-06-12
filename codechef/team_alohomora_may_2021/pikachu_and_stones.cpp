/***************************************************
* AUTHOR : Anav Prasad
* Nick : graworth
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0
#define print_var(x) cout << #x << ": " << x << "\n";
#define space " "
typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
template <typename t1, typename t2> void print(vector<pair<t1,t2>> &arr);


inline ull pow_sum(ull n){
	if (n&1){
		return ((n+1)/2)*n;
	}
	return ((n/2) * (n+1));
}


ull calc_stones(ull n, ull ind, ull peak){
	ull ans = pow_sum(peak);
	if (peak - ind - 1 > 0)
		ans -= pow_sum(peak - ind - 1);
	ans += pow_sum(peak);
	ans -= peak;
	if (peak - n + ind - 1 > 0)
		ans -= pow_sum(peak - n + ind - 1);
	return ans;
}


int translate(int cur, int ind, int target, bool inc){
	if (target == ind)
		return cur;
	if (target < ind){
		if (inc){
			return (cur + (ind - target));
		}
		else
			return (cur - (ind - target));
	}
	if (inc)
		return (cur + (target -ind));
	return (cur - (target - ind));
}


bool comp(const pair<int, int> &p1, const pair<int, int> &p2){
	return p1.first < p2.first;
}


ull solve(vector<int> &arr, int n, int ind, vector<pair<int,int>> &req, int lcur, int rcur){
	int peak = max(lcur, arr[ind]);
	if (peak >= rcur){
		return calc_stones(n, ind, peak);
	}
	while(req.size() > 0 && req[0].second <= ind){
		req.erase(req.begin());
	}
	if (req.size() == 0){
		return calc_stones(n, ind, peak);
	}
	if (translate(peak, ind, req[0].second, false)){
		
	}
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		ll cur = 0;
		ull or_sum = 0;
		forn(i, n){
			cin >> arr[i];
			or_sum += arr[i];
		}
		ull mn = 0;
		vector<pair<int,int>> req_ht;
		cur = arr[0];
		cur++;
		int ind = 1;
		ull orp;
		cur = max(cur, arr[1]);
		orp = cur;
		forsn(i, 2, n - 1){
			cur--;
			if (arr[i] > cur){
				orp += arr[i] - cur;
				cur = arr[i];
			}
			req_ht.pb(cur - arr[i], i);
		}
		mn = calc_stones(n, 1, orp);
		sort(req_ht.begin(), req_ht.end(), comp);
		cur = max(arr[0] + 1, arr[1]);
		int rcur = orp;
		forsn(i, 3, n - 1){
			cur++;
			orp--;

		}
	}
	return 0;
}


template <typename type> void print(vector<vector<type>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << endl;
	}
}


template <typename type> void print(vector<type> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << endl;
}


template <typename t1, typename t2> void print(vector<pair<t1,t2>> &arr){
	cout << "1d vector with pairs: \n";
	int n = arr.size();
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}\n";
}