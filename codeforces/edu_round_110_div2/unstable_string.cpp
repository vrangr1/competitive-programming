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
#define push_back(a) pb(a)
#define pass (void)0
typedef long long int ll;


inline ll calc(ll st, ll end){
	ll n = end - st + 1;
	return (n * (n + 1))/2;
}


inline ret_char(int n){
	return (char)(n + '0');
}


inline int update(int e, char s){
	if (e == -1 && s == '?')
		return -1;
	if (s == '1')
		return 0;
	else if (s == '0')
		return 1;
	return (e + 1) % 2;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int n = s.length();
		ll ans = 0;
		int last = 0;
		int exp = -1;
		if (s[0] == '0')
			exp = 1;
		else if(s[0] == '1')
			exp = 0;
		int lq = -1, bval;
		bool stt = false, back = false;
		forsn(i, 1, n - 1){
			
			if ((exp >= 0 && (s[i] == ret_char(exp) || s[i] == '?')) || exp == -1){
				exp = update(exp, s[i]);
			}
			else{
				if (back){
					// ans += (calc(bval, i - 1) - calc(bval, last - 1));
					ans += (i - last) * (last - bval);
					back = false;
				}
				if (s[i - 1] == '?'){
					back = true;
					bval = lq;
				}
				ans += calc(last, i - 1);
				last = i;
				exp = update(-1, s[i]);
			}
			if (s[i] == '?' && !stt){
				stt = true;
				lq = i;
			}
			else if(s[i] == '?'){
				pass;
			}
			else{
				stt = false;
			}
		}
		if (back){
			// ans += calc(bval, n - 1);
			ans += (n - last) * (last - bval);
		}
		ans += calc(last, n - 1);
		cout << ans << bline;
	}
	return 0;
}