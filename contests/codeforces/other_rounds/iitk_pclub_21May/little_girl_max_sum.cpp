#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


bool comp(const ll &a, const ll &b){
	if (a >= b)
		return true;
	return false;
}


void prt(vector<ll> &ar, int n){
	cout << "prt: ";
	for (int i = 0; i < n; ++i){
		cout << ar[i] << " ";
	}
	cout << endl;
}


int main(){
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n);//, sm(n, 0);
	vector<int> chk(n, 0), st(n, 0), ed(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end(), comp);
	// sm[0] = arr[0];
	// for (int i = 1; i < n; ++i){
	// 	sm[i] = sm[i - 1] + arr[i];
	// }
	// prt(arr, n);
	// prt(sm, n);
	int l, r;
	int ct = 0;
	for (int i = 0; i < q; ++i){
		cin >> l >> r;
		l--;
		r--;
		st[l] += 1;
		ed[r] += 1;
	}
	int i = 0, cur = 0;
	while (i < n){
		if (st[i] > 0){
			cur += st[i];
		}
		chk[i] += cur;
		++i;
		if (ed[i - 1] > 0)
			cur -= ed[i - 1];
	}
	sort(chk.begin(), chk.end(), greater<int>());
	ll ans = 0;
	i = 0;
	cur = 0;
	while(i < n && chk[i] > 0){
		ans += ((ll)chk[i]) * arr[cur];
		cur++;
		i++;
	}
	cout << ans;
	// cout << sm[ct - 1];
	return 0;
}

