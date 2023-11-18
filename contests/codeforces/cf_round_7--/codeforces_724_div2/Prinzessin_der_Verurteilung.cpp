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


inline int get_ind(char ch){
	return (int)(ch - 'a');
}


inline int get_ind(char ch1, char ch2){
	return (int)(26 * get_ind(ch1) + get_ind(ch2) + 26);
}


inline int get_ind(char ch1, char ch2, char ch3){
	return (int)(26 * 26 * get_ind(ch1) + get_ind(ch2, ch3) + 26 * 26);
}


inline char ret_char(int ind){
	return (char)('a' + ind);
}

inline void print_char(int in1, int in2){
	cout << ret_char(in1) << ret_char(in2) << bline;
}


inline void print_str(int in1, int in2, int in3){
	cout << ret_char(in1) << ret_char(in2) << ret_char(in3) << bline;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		// cout << "n: " << n << bline;
		string s;
		cin >> s;
		// cout << "s: " << s << bline;
		// double k = n;
		// k = pow(26, (log(k+1) / log(26))) + 1;
		// int r = k + 1;
		vector<bool> chk(1500, false);
		// cout << "hello";
		// vector<bool> fir(26,false);
		forn(i, n){
			// fir[get_ind(s[i])] = true;
			chk[get_ind(s[i])] = true;
		}
		bool obt = false;
		forn(i, 26){
			if (!chk[i]){
				obt = true;
				cout << (char)('a' + i) << bline;
				break;
			}
		}
		if (obt)
			continue;
		// vector<bool> sec(26*26, false);

		
		forn(i, n - 1){
			int ind = get_ind(s[i],s[i+1]);
			// sec[ind] = true;
			chk[ind] = true;
		}
		forsn(i, 26, 26 * 26 + 25){
			if (!chk[i]){
				i -= 26;
				// i = 0;
				print_char(i / 26, i % 26);
				obt = true;
				break;
			}
		}
		if (obt)
			continue;
		// else{
		// 	assert(1 ==2);
		// }
		// return 0;
		// // continue;
		int r = 1500;
		forn(i, n-2){
			int ind = get_ind(s[i], s[i+1], s[i+2]);
			if (ind >= r)
				continue;
			else{
				chk[ind] = true;
			}
		}
		forsn(i, 26 * 26 + 26, r - 1){
			if (!chk[i]){
				i -= (26 + 26 * 26);
				int in1 = i % 26;
				i /= 26;
				int in2 = i %26;
				print_str(i/26, in2, in1);
				obt = true;
				break;
			}

		}

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