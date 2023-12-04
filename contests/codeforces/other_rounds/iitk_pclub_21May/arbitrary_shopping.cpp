#include<bits/stdc++.h>

using namespace std;


int get_num(vector<int> &arr, int &lst, int cur, int m){
	if (lst == -1){
		if (arr[cur] <= m)
			return cur + 1;
		else{
			lst = 0;
			while(arr[cur] - arr[lst] > m)
				lst++;
			return (cur - lst);
		}
	}
	else{
		while(arr[cur] - arr[lst] > m)
			lst++;
		return (cur - lst);
	}
}


int main(){
	int n, money;
	cin >> n;
	vector<int> out(n);
	vector<int> pxsum(n, 0);
	cin >> out[0];
	pxsum[0] = out[0];
	for (int i = 1; i < n; ++i){
		cin >> out[i];
		pxsum[i] = pxsum[i - 1] + out[i];
	}
	cin >> money;
	int mx = 0;
	int lst = -1;
	int temp;
	for (int i = 0; i < n; ++i){
		temp = get_num(pxsum, lst, i, money);
		if (mx < temp)
			mx = temp;
	}
	cout << mx;
	return 0;
}

