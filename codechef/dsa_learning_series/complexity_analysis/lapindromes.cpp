/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;


int main(){
	int T;
	cin >> T;
	string s;
	while(T--){
		cin >> s;
		int n = s.size();
		vector<int> alb(26, 0);
		bool ans = true;
		for(int i = 0; i < n; ++i){
			if(i < n/2){
				int ind = (int)tolower(s[i]) - 97;
				// cout << ind << endl;
				++alb[ind];
			}
			else if ( (n&1) ? i > n/2 : i >= n/2){
				(--alb[(int)tolower(s[i]) - 97] < 0 ? ans = false: true);

			}
		}
		if (!ans)
			cout << "NO\n";
		else
			cout << "YES" << bline;
	}
	return 0;
}