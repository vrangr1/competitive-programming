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



void append_substr(string &s1, string &s2, int st, int end){
	forsn(i, st, end)
		s1.push_back(s2[i]);
}


int main(){
	fastIO;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size(), ind;
		char mn;
		vector<pair<char, int> > prefx(n);
		prefx[n-1] = make_pair(s[n-1], n-1);
		forsr(i, n-2, 0){
			if (s[i] >= prefx[i+1].first)
				prefx[i] = prefx[i+1];
			else
				prefx[i] = make_pair(s[i], i);
		}
		string lt, ans;
		bool found = false;

		forn(i, n){
			if (!found){
				mn = prefx[i].first;
				ind = prefx[i].second;
				found = true;
				if (lt.size() > 0 && mn > lt[0]){
					// assert(i != 0);
					// lt.append(s.substr(i, n-1));
					append_substr(lt, s, i, n-1);
					break;
				}
				if (lt.size() > 0 && mn == lt[0]){
					int index = 0;
					while (index < lt.size() && mn == lt[index])
						index++;
					if (index < lt.size() && mn > lt[index]){
						append_substr(lt, s, i, n-1);
						break;
					}

				}
			}
			if (i == ind){
				found = false;
				// if (s[i] == 'd'){
				// 	cout << "Here\n" << lt << endl << i << endl;
				// 	cout << "Fin\n";	
				// }
				// int index = 0;
				// if (lt.size() == 0){
				// 	ans.push_back(mn);
				// 	continue;
				// }
				// if (mn < lt[0]){
				// 	ans.push_back(mn);
				// 	continue;
				// }
				// if (i == n-1){
				// 	while(index < lt.size() && lt[index] == mn){
				// 		index++;
				// 	}
				// 	if (index == lt.size()){
				// 		ans.push_back(mn);
				// 		break;
				// 	}
				// 	else{
				// 		append_substr()
				// 	}
				// }


				// if (i == n-1 && mn < lt[0]){
				// 	ans.push_back(mn);
				// 	continue;
				// }
				// char temp;
				// if (i == n-1){
				// 	temp = mn;
				// }
				// else
				// 	temp = prefx[i+1].first;
				// if (i < n && lt[0] > temp){
				// 	ans.push_back(mn);
				// 	continue;
				// }

				// int index = 0;
				// while(lt.size() > index && prefx[i+1] == lt[index])
				// 	index++;
				// if (lt.size() == index){
				// 	ans.push_back(mn);
				// 	continue;
				// }
				// else if (lt[index] < mn) {
				// 	append_substr(lt, s, i, n-1);
				// 	cout << lt << endl;
				// 	cout << index << endl << i << endl;
				// 	cout << "Called!!!!!!\n";
				// 	break;
				// }
				// // if (mn == lt[0] && mn >= lt[1]){
				// // 	ch = lt[index];
				// // 	while(index ch == mn){
				// // 		index++;
				// // 		ch = lt[index];
				// // 	}
				// // 	append_substr(lt, s, i, n-1);
				// // 	break;
				// // }
				// else{
				// 	ans.push_back(mn);
				// 	continue;
				// }
				
			}
			if (s[i] == mn){
				ans.push_back(mn);
				continue;
			}
			lt.push_back(s[i]);
		}
		ans.append(lt);
		// if (t != 0)
		cout << ans << endl;
		// else
			// cout << ans;
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