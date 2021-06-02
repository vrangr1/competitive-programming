#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n, x, temp;
	vector<int> b;
	bool check;
	vector<pair<int, int>> a;
	cin >> T;
	while(T--){
	    cin >> n >> x;
	    for(int i = 0; i < n; ++i){
	        cin >> temp;
	        a.push_back(make_pair(temp,i));
	    }
	    sort(a.begin(), a.end());
	    for(int i = 0; i < n; ++i){
	        cin >> temp;
	        b.push_back(temp);
	    }
	    sort(b.begin(), b.end(), greater<int>());
	    check = true;
	    int i = 0;
	    while(i<n){
	        if (a[i].first + b[i] > x){
	            check = false;
	            break;
	        }
	        i++;
	    }
	    if (check)
	        cout << "Yes\n";
	    else
	        cout << "No\n";
	    a.clear();
	    b.clear();
	}
	return 0;
}

