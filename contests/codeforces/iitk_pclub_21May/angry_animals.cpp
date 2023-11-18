#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int calc(int st, int end, int &act){
	if (st > end)
		return 0;
	if (st == end)
		return 1;
	ll l1 = end - act;
	ll ans = (l1 * (l1 + 1)) / 2;
	ans += (end - act) * (act - st);
	act = end;
	return ans;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(m, vector<int> (2, 0));
	vector<int> en(n, -1);
	vector<int> a(m), b(m);
	int cp1, cp2;
	int useless;
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	cin >> useless;
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	for (int i = 0; i < m; ++i){
		cp1 = a[i];
		cp2 = b[i];
		cp1--;
		cp2--;
		if (cp1 > cp2){
			cp1 = cp1 + cp2;
			cp2 = cp1 - cp2;
			cp1 = cp1 - cp2;
		}
		arr[i][0] = cp1;
		arr[i][1] = cp2;
		if (en[cp2] < cp1)
			en[cp2] = cp1;
	}
	ll ans = 0;
	int st = 0, act = 0;
	for (int i = 0; i < n; ++i){
		if (en[i] >= 0){
			ans += calc(st, i - 1, act);
			st = en[i] + 1;
		}
	}
	ans += n + calc(st, n - 1, act);
	cout << ans;

	return 0;
}

