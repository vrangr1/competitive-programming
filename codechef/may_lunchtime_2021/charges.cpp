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


inline int ret_num(char ch){
	return (int)(ch - '0');
}


int calc_dist(int a, int b){
	if (a == b){
		return 2;
	}
	return 1;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> arr(n);
		int dist = 0;
		arr[0] = ret_num(s[0]);
		// cin >> arr[0];
		if (n == 1){
			forn(i, k){
				int q;
				cin >> q;
				cout << 0 << bline;
			}
			continue;
		}
		forsn(i, 1, n - 1){
			// cin >> arr[i];
			arr[i] = ret_num(s[i]);
			dist += calc_dist(arr[i-1], arr[i]);
		}
		forn(i, k){
			int q;
			cin >> q;
			q--;
			if (q != 0 && q != n - 1){
				dist -= calc_dist(arr[q - 1], arr[q]);
				dist -= calc_dist(arr[q], arr[q + 1]);
				arr[q] = (arr[q] + 1) % 2;
				dist += calc_dist(arr[q - 1], arr[q]);
				dist += calc_dist(arr[q], arr[q + 1]);
				cout << dist << bline;
			}
			else if (q == 0){
				dist -= calc_dist(arr[q], arr[q + 1]);
				arr[q] = (arr[q] + 1) % 2;
				dist += calc_dist(arr[q + 1], arr[q]);
				cout << dist << bline;
			}
			else{
				dist -= calc_dist(arr[q], arr[q - 1]);
				arr[q] = (arr[q] + 1) % 2;
				dist += calc_dist(arr[q - 1], arr[q]);
				cout << dist << bline;
			}
		}

	}
	return 0;
}