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


inline int get_ind(int ind){
	if (ind >= 0)
		return ind;
	ind = -ind;
	return ind + 100;
}


int solve(vector<int> &arr){
	int ct = 0;
	vector<bool> chk(500, false);
	vector<int> neg;
	int n = arr.size();

	forn(i,n){
		if (arr[i] > 0 && !chk[arr[i]])
			chk[arr[i]] = true;
		else if(arr[i] <= 0)
			neg.pb(arr[i]);
	}
	// print(arr);
	// print(neg);
	// return 0;
	// int ct = 0;
	forn(i, n){
		forsn(j, i + 1, n - 1){
			if (!chk[abs(arr[i] - arr[j])]){
				chk[abs(arr[i] - arr[j])] = true;
				ct++;
			}
		}
	}
	vector<int> b;
	forn(i, neg.size())
		b.pb(neg[i]);
		// cout << neg[i] << " ";
	forsn(i, 1, 100){
		if (chk[i])
			b.pb(i);
			// cout << i << " ";
	}
	arr.clear();
	arr = b;
	return ct;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		forn(i, n)
			cin >> arr[i];
		int ct = n;
		while(ct <= 300){
			int prev = ct;
			ct = solve(arr);
			if (ct == 0){
				ct = ct + prev;
				break;
			}
			ct = ct + prev;
		}
		// cout <<"ct: " << ct << bline;
		// return 0;
		if (ct <= 300){
			cout << "YES" << bline;
			cout << ct << bline;
			// forn(i, neg.size())
			// 	cout << neg[i] << " ";
			// forsn(i, 1, 100){
			// 	if (chk[i])
			// 		cout << i << " ";
			// }
			// cout << bline;
			print(arr);
		}
		else{
			cout << "NO"  << bline;
		}
		// cout << ct << bline;

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
	// cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}