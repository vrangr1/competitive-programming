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


int main(){
	fastIO;
	int T;
	cin >> T;
	// T--;
// 	T = 3;
	while(T--){
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		assert(s.length() == n);
		string ans(n, '2');
		forn(i, n){
			if (s[i] == '1')
				ans[i] = '1';
		}
		int ct = 0;
		while(ct < n && s[ct] != '1'){
			ct++;
		}
		if (ct == n){
			cout << s << bline;
			continue;
		}
		int cp = m;
		ct--;
		while(ct >= 0 && cp--){
			ans[ct] = '1';
			ct--;
		}
		// cp = m;
		// ct = 0;
		// while(s[m - ct - 1] != '1'){
		// 	ct++;
		// }
		// ct--;
		// while(ct >= 0 && cp--){
		// 	ans[m - ct - 1] = '1';
		// 	ct--;
		// }
		// if (ans[0] == 0){
		// 	int ind = 0;
		// 	bool st = false;
		// 	while(ind < n && ans[ind] == 0){
		// 		ans[ind] = '0';
		// 		ind++;
		// 	}
		// 	while(ind < n){
		// 		if (ans[ind] != 0){
		// 			ind++;
		// 			continue;
		// 		}
		// 		if (!st && ind < n - 1 && ans[ind + 1] != '1'){
		// 			cp = m;
		// 			cp--;
		// 			ans[ind] = '1';
		// 			st = true;
		// 			continue;
		// 		}
		// 		if (st && cp > 0){
		// 			cp--;
		// 			ans[ind] = '1';
		// 		}
		// 	}

		// }
		vector<pair<int,int>> inv;
		bool st = false;
		ct = 0;
		// cout << "n: "<< n << bline;
		forn(i, n){
			if (!st && s[i] == '0'){
				st = true;
				ct++;
				inv.push_back({i, i});
				continue;
			}
			if (st && s[i] == '0')
				continue;
			if (st && s[i] == '1'){
				st = false;
				inv[ct - 1].second = i - 1;
				continue;
			}
		}
		if (st == true){
			inv[ct - 1].second = n - 1;
		}
		// cout << "0 intervals:\n";
		// forn(i, ct){
		// 	cout << "int: " << inv[i].first << "," << inv[i].second << bline;
		// }
		forn(i, ct){
			if (i == 0 && s[0] == '0'){
				if (ans[0] == '2'){
				    int iter = 0;
				    while(iter < n && ans[iter] == '2')
					    ans[iter++] = '0';
				    
				}
				continue;
			}
			if (i == ct - 1 && s[n - 1] == '0'){
			    int len = inv[i].first;
			    cp = m;
			    while(len < n && cp--){
			        ans[len++] = '1';
			    }
			    while(len < n)
			        ans[len++] = '0';
			    continue;
			}
			int len = inv[i].second - inv[i].first + 1;
			// cout << "len: " << len << bline;
			if (len == 1){
				ans[inv[i].first] = '0';
				continue;
			}
			if (len >= 2 * m){
				forsn(j, inv[i].first, inv[i].first + m - 1){
					ans[j] = '1';
				}
				forsn(j, inv[i].second - m + 1, inv[i].second){
					ans[j] = '1';
				}
				forsn(j, inv[i].first + m, inv[i].second - m){
					ans[j] = '0';
				}
				continue;
			}
			if (len % 2){
				len = len/2;
				ans[len + inv[i].first] = '0';
				forsn(j, inv[i].first, inv[i].first + len - 1)
					ans[j] = '1';
				forsn(j, inv[i].second - len + 1, inv[i].second)
					ans[j] = '1';
				continue;
			}
			forsn(j, inv[i].first, inv[i].second)
				ans[j] = '1';
		}
		// cout << "ct: " << ct << bline;
		if (ct == 0){
			if (ans[0] == '2'){
				int iter = 0;
				while(iter < n && ans[iter] == '2')
					ans[iter++] = '0';  
			}
		}
		cout << ans << bline;
	}

	return 0;
}