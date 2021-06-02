#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, n, m, temp, sum;
	cin >> T;
	for (int test = 0; test < T; ++test){
	    cin >> n >> m;
	    sum = 0;
	    for (int i = 0; i < n; ++i){
	        cin >> temp;
	        sum += temp;
	    }
	    if (sum == m){
	        cout << "YES\n";
	    }
	    else
	        cout << "NO\n";
	    
	}
	return 0;
}

