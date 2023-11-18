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


int calc(string s){
	int ans = 0, l = s.length();
	int ind = l - 1;
	while (ind >= 0 && s[ind] != '.'){
		ind--;
	}
	ind++;
	forsn(i, ind, l - 1){
		ans = ret_num(s[i]) + ans * 10;
	}
	return ans;
}


string update(string s, int n){
	int ans = 0, l = s.length();
	int ind = l - 1;
	while (ind >= 0 && s[ind] != '.'){
		ind--;
	}
	ind++;
	string arr = to_string(n);
	int k = 0, len = arr.length();
	while(k < len){
		if (ind < l)
		s[ind] = arr[k];
		else{
			s += arr[k];
		}
		ind++;
		k++;
	}
	return s;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		stack<string> stk;
		cin >> arr[0];
		stk.push("1");
		cout << "1\n";
		forsn(i, 1, n - 1){
			cin >> arr[i];
			if (arr[i] == 1){
				stk.push(stk.top() + ".1");
				cout << stk.top() << bline;
				continue;
			}
			else{
				while (calc(stk.top()) + 1 != arr[i]){
					stk.pop();
				}
				string tp = stk.top();
				stk.pop();
				tp = update(tp, arr[i]);
				cout << tp << bline;
				stk.push(tp);
			}
		}

	}
	return 0;
}