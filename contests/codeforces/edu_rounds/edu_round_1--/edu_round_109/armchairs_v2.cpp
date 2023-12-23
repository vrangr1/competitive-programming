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
	int n;
	cin >> n;
	int ans = 0;
	stack<int> ones, zero;
	
	forn(i, n){
		int cur;
		cin>>cur;
		if (cur == 1){
			if (zero.size()){
				ans += (abs(zero.top() - i));
				zero.pop();
				continue;
			}
			else{
				ones.push(i);
			}
		}
		else{
			if (ones.size()){
				ans += (abs(ones.top() - i));
				ones.pop();
				continue;
			}
			else
				zero.push(i);
		}
	}
	cout << ans;
	return 0;
}