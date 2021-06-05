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
#define mod 1000000007
#define maxn 1000010

vector<ll> two(maxn, 0);


inline void init(){
	two[0] = 1ll;
	forsn(i, 1, maxn)
		two[i] = (two[i - 1] * 2ll) % mod;
}


ll calc(ll a, ll n){
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	ll ans = calc(a, n/2);
	if (n % 2)
		return ((((ans * ans) % mod) * a) % mod);
	return ((ans * ans) % mod);
}


inline ll solve(int n, int m){
	return (calc(two[n] - 1, m));
}


int main(){
	fastIO;
	int T;
	cin >> T;
	init();
	while(T--){
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << bline;
	}
	return 0;
}