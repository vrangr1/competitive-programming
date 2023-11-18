/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main(){
	int T;
	// scanf("%d", &T);
	cin >> T;
	string s;
	int n;
	while(T--){
		// getline(cin, s);
		cin >> s;
		n = s.size();
		bool carry = false, nine = false;
		// cout << (int)s[0] - 48;
		if (s[n-1] != '9'){
			for(int i = 0; i < n-1; ++i){
				cout << s[i];
			}
			cout << (char)(s[n-1]+1) << endl;
		}
		else{
			s[n-1] = '0';
			carry = true;
			nine = false;
			for(int i = n-2; i >=0; --i){
				if(carry){
					if(s[i] != '9'){
						s[i] = s[i] + 1;
						carry = false;
					}
					else{
						s[i] = '0';
						carry = true;
						if(i == 0)
							nine = true;
					}
				}
			}
			if(T != 0){
				if(!nine)
					cout << s << "\n";
				else
					cout << '1' << s << endl;
			}
			else{
				if(!nine)
					cout << s;
				else
					cout << '1' << s;
			}
			
		}
		s.clear();
	}
	
	return 0;
}