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


void dfs(vector<int> &arr, int ind, string &s, int n){
	if (ind >= n)
		return;
	dfs(arr, (ind<<1) + 1, s, n);
	dfs(arr, (ind<<1) + 2, s, n);
	if ((ind<<1) + 1 >= n){
		if (s[ind] == '?')
			arr[ind] = 2;
		else
			arr[ind] = 1;
		return;
	}
	else{
		if (s[ind] == '?')
			arr[ind] = arr[(ind<<1) + 1] + arr[(ind<<1) + 2];
		else{
			if (s[ind] == '1')
				arr[ind] = arr[ind * 2 + 1];
			else
				arr[ind] = arr[ind * 2 + 2];
		}
	}
}


void follow(vector<int> &arr, int ind, string &s, int n){
	while(ind > 0){
		if ((ind<<1) + 1 >= n){
			arr[ind] = ((s[ind] == '?')? 2 : 1);
			if (ind & 1)
				ind >>= 1;
			else
				ind = (ind>>1) - 1;
			continue;
		}
		if (s[ind] == '?')
			arr[ind] = arr[(ind<<1) + 1] + arr[(ind<<1) + 2];
		else{
			if (s[ind] == '1')
				arr[ind] = arr[ind * 2 + 1];
			else
				arr[ind] = arr[ind * 2 + 2];
		}
		if (ind & 1)
			ind >>= 1;
		else
			ind = (ind>>1) - 1;
	}
	if ((ind<<1) + 1 >= n){
		arr[ind] = ((s[ind] == '?')? 2 : 1);
		return;
	}
	if (s[ind] == '?')
		arr[ind] = arr[(ind<<1) + 1] + arr[(ind<<1) + 2];
	else{
		if (s[ind] == '1')
			arr[ind] = arr[ind * 2 + 1];
		else
			arr[ind] = arr[ind * 2 + 2];
	}
}


int main(){
	fastIO;
	int k, n, q, ind, ans;
	char ch;
	cin >> k;
	n = (1<<k) - 1;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	vector<int> arr(n, 0);
	dfs(arr, 0, s, n);
	cin >> q;
	forn(i, q){
		cin >> ind;
		cin >> ch;
		ind = n - ind;
		s[ind] = ch;
		follow(arr, ind, s, n);
		cout << arr[0] << bline;
	}
	return 0;
}