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
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<vector<bool> > square(n, vector<bool> (n, false));
		forn(i, n){
			forn(j, n){
				int inp;
				cin >> inp;
				if (inp == 1)
					square[i][j] = true;
				// else
				// 	square[i][j] = false;
			}
		}
		vector<vector<vector<bool> > > columns(n, vector<vector<bool> > (n, vector<bool> (n, false)));
		forn(i, n){
			// bool begun = false;
			int ind = -1;
			forn(j, n){
				if (ind == -1 && square[j][i]){
					ind = j;
					columns[j][j][0] = true;
					continue;
				}
				else if(square[j][i]){
					forsn(k, 0, j - ind){
						columns[j-ind][j][k] = true;
					}
				}
				else{
					ind = -1;
				}
			}
		}
		ll count = 0;
		forn(i, n){
			forn(j, n){
				bool begun = false;
				ll cur_count = 0;
				if (columns[i][j][0])
					count++;
				forsn(k, 1, n-1){
					if (!begun && square[i][k] && square[j][k] && columns[i][j][k]){
						begun = true;
						continue;
					}
					if (begun && square[i][k] && square[j][k] && columns[i][j][k]){
						// count++;
						cur_count++;
						count += cur_count;
						continue;
					}
					if (begun && square[i][k] && square[j][k] && !columns[i][j][k]){
						continue;
					}
					if (begun){
						begun = false;
						cur_count = 0;
						continue;
					}
				}
			}
		}
		cout << count << endl;
		
	}
	return 0;
}


template <typename type> void print(const vector<vector<type> > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size() - 1)
			cout << arr[i][j] << ", ";
		cout << arr[i][arr[i].size() - 1] << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector\n";
}


template <typename type> void print(const vector<type> &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ", ";
	}
	cout << "], 1D Vector\n";
}


template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr){
	int n = arr.size();
	cout << "\n[";
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}], 1D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size()){
			cout << "{" << arr[i][j].first << "," << arr[i][j].second << "}";
			if (j != arr[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "\n{" << p.first << "," << p.second << "}, Pair\n";
}